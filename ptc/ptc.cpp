/**
 * @file ptc.cpp
 * @author Marek Sedlacek
 * @brief Proto-typed compiler entry point
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) Marek Sedlacek, 2023
 */

#include "ptc.hpp"
#include "scanner.hpp"
#include "logging.hpp"
#include "codegen.hpp"
#include "llvm/Support/InitLLVM.h"
#include "llvm/CodeGen/CommandFlags.h"
#include "llvm/IR/IRPrintingPasses.h"
#include "llvm/Pass.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/ToolOutputFile.h"
#include "llvm/Support/WithColor.h"
#include "llvm/Support/FileSystem.h"
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>

using namespace ptc;

static llvm::codegen::RegisterCodeGenFlags cgf;
static llvm::cl::list<std::string> inputFiles(llvm::cl::Positional, llvm::cl::desc("<input-files>"));
static llvm::cl::opt<std::string> mTriple("mtriple", llvm::cl::desc("Override target triple for module"));
static llvm::cl::opt<bool> emitLLVM("emit-llvm", llvm::cl::desc("Emit IR code instead of assembler"), llvm::cl::init(false));

static const char *head = "Proto-typed compiler";

void printVersion(llvm::raw_ostream &OS) {
    // TODO: print version
    OS << head << " " << PTC_VERSION << "\n";
    OS << "  Default target: "
        << llvm::sys::getDefaultTargetTriple() << "\n";
    std::string CPU(llvm::sys::getHostCPUName());
    OS << "  Host CPU: " << CPU << "\n";
    OS << "\n";
    OS.flush();
    llvm::TargetRegistry::printRegisteredTargetsForVersion(OS);
    exit(EXIT_SUCCESS);
}

llvm::TargetMachine *createTargetMachine(std::string ptcName) {
    llvm::Triple triple = llvm::Triple(!mTriple.empty() ? llvm::Triple::normalize(mTriple) : llvm::sys::getDefaultTargetTriple());
    llvm::TargetOptions targetOpts = llvm::codegen::InitTargetOptionsFromCodeGenFlags(triple);
    std::string cpuStr = llvm::codegen::getCPUStr();
    std::string featureStr = llvm::codegen::getFeaturesStr();

    std::string error;
    const llvm::Target *target = llvm::TargetRegistry::lookupTarget(llvm::codegen::getMArch(), triple, error);

    if(!target) {
        llvm::WithColor::error(llvm::errs(), ptcName) << error << "\n";
        return nullptr;
    }

    llvm::TargetMachine *tm = target->createTargetMachine(
        triple.getTriple(),
        cpuStr,
        featureStr,
        targetOpts,
        llvm::Optional<llvm::Reloc::Model>(llvm::codegen::getRelocModel()));

    return tm;
}

bool emit(std::string ptcName, llvm::Module *module, llvm::TargetMachine *target, llvm::StringRef fileName) {
    llvm::CodeGenFileType fileType = llvm::codegen::getFileType();
    std::string outputFileName;
    if(fileName == "-") {
        outputFileName = "-";
    }
    else {
        if(fileName.endswith(".pt")) {
            outputFileName = fileName.drop_back(3).str();
        }
        else {
            outputFileName = fileName.str();
        }

        switch(fileType) {
        case llvm::CGFT_AssemblyFile:
            outputFileName.append(emitLLVM ? ".ll" : ".s");
        break;
        case llvm::CGFT_ObjectFile:
            outputFileName.append(".o");
        break;
        case llvm::CGFT_Null:
            outputFileName.append(".null");
        break;
        }
    }

    std::error_code ec;
    llvm::sys::fs::OpenFlags openFlags = llvm::sys::fs::OF_None;
    if(fileType == llvm::CGFT_AssemblyFile) {
        openFlags |= llvm::sys::fs::OF_Text;
    }
    auto outF = std::make_unique<llvm::ToolOutputFile>(outputFileName, ec, openFlags);
    if(ec) {
        llvm::WithColor::error(llvm::errs(), ptcName) << ec.message() << "\n";
        return false;
    }

    llvm::legacy::PassManager passM;
    if(fileType == llvm::CGFT_AssemblyFile && emitLLVM) {
        passM.add(llvm::createPrintModulePass(outF->os()));
    }
    else {
        if(target->addPassesToEmitFile(passM, outF->os(), nullptr, fileType)) {
            llvm::WithColor::error() << "Unsupported file type\n";
            return false;
        }
    }

    passM.run(*module);
    outF->keep();

    return true;
}

/** Main */
int main(int argc, char *argv[]) {
    llvm::InitLLVM LLVMX(argc, argv);

    log::Logger::get().set_disable(false);
    log::Logger::get().set_log_everything(true);
    //log::Logger::get().set_logging_level(MAX_LOGGING_LEVEL);

    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmPrinters();
    llvm::InitializeAllAsmParsers();

    llvm::cl::SetVersionPrinter(&printVersion);
    llvm::cl::ParseCommandLineOptions(argc, argv, head);

    if(llvm::codegen::getMCPU() == "help" ||
            std::any_of(llvm::codegen::getMAttrs().begin(), 
                        llvm::codegen::getMAttrs().end(),
                        [](const std::string &a) { return a == "help"; })) {
        auto triple = llvm::Triple(LLVM_DEFAULT_TARGET_TRIPLE);
        std::string errMsg;
        if(auto target = llvm::TargetRegistry::lookupTarget(triple.getTriple(), errMsg)) {
            llvm::errs() << "Targeting " << target->getName() << ".";
        
            target->createMCSubtargetInfo(triple.getTriple(),
                                      llvm::codegen::getCPUStr(),
                                      llvm::codegen::getFeaturesStr());
        } else {
            llvm::errs() << errMsg << "\n";
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    } 

    // Parsing
    const char *ptcName = argv[0];
    bool parsingMain = true;
    for(const auto &fileName: inputFiles) {
        llvm::ErrorOr<std::unique_ptr<llvm::MemoryBuffer>> fileOrErr = llvm::MemoryBuffer::getFile(fileName);
        if(std::error_code buffErr = fileOrErr.getError()) {
            llvm::WithColor::error(llvm::errs(), ptcName) << "Error reading " << fileName << ": " << buffErr.message() << "\n";
        }

        llvm::SourceMgr srcMgr;
        Diagnostics diags(srcMgr);

        srcMgr.AddNewSourceBuffer(std::move(*fileOrErr), llvm::SMLoc());

        // TODO: use SourceMgr
        std::ifstream code(fileName);

        std::string moduleName = std::filesystem::path(fileName).stem();
        auto scanner = new Scanner(diags, moduleName);
        scanner->parse(&code);
        if(parsingMain) {
            scanner->mainModule->setMain(true);
            parsingMain = false;
        }
        LOG1("Parsing done for "+fileName);

        // Code generation
        llvm::TargetMachine *target = createTargetMachine(ptcName);
        if (!target) {
            llvm::report_fatal_error("Could not create target machine");
            exit(EXIT_FAILURE);
        }
        if(scanner->mainModule && diags.getNumErrors() == 0) {
            LOG1("Starting code generation for "+fileName);
            // Code generation
            llvm::LLVMContext ctx;
            if(cg::CodeGenHandler *CGHandle = cg::CodeGenHandler::create(ctx, target)) {
                std::unique_ptr<llvm::Module> mainMod = CGHandle->run(scanner->mainModule, fileName);
                if(!emit(ptcName, mainMod.get(), target, fileName)) {
                    llvm::WithColor::error(llvm::errs(), ptcName) << "error writing output\n";
                }
                delete CGHandle;
            }
        }
        else if(diags.getNumErrors() > 0) {
            LOG1("\033[91mFailure, compilation ended with "+std::to_string(diags.getNumErrors())+" error(s)\033[39m")
            return EXIT_FAILURE;
        }

        delete scanner;
    }

    LOG1("\033[92mCompilation was successful\033[39m");
    return 0;
}