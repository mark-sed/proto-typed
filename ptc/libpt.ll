; ModuleID = 'ptc/libpt.pt'
source_filename = "ptc/libpt.pt"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%string = type { i8*, i32, i32, i32 }
%string.0 = type { i8*, i32, i32, i32 }
%string.2 = type { i8*, i32, i32, i32 }
%string.4 = type { i8*, i32, i32, i32 }
%string.6 = type { i8*, i32, i32, i32 }
%matrix = type { i8*, i32, i32, i32 }

@0 = private global i8* getelementptr inbounds ([3 x i8], [3 x i8]* @1, i32 0, i32 0)
@1 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@2 = private global i8* getelementptr inbounds ([4 x i8], [4 x i8]* @3, i32 0, i32 0)
@3 = private unnamed_addr constant [4 x i8] c"%ld\00", align 1
@4 = private global i8* getelementptr inbounds ([6 x i8], [6 x i8]* @5, i32 0, i32 0)
@5 = private unnamed_addr constant [6 x i8] c"%.16g\00", align 1
@6 = private global i8* getelementptr inbounds ([5 x i8], [5 x i8]* @7, i32 0, i32 0)
@7 = private unnamed_addr constant [5 x i8] c"true\00", align 1
@8 = private global i8* getelementptr inbounds ([6 x i8], [6 x i8]* @9, i32 0, i32 0)
@9 = private unnamed_addr constant [6 x i8] c"false\00", align 1
@10 = private global i8* getelementptr inbounds ([1 x i8], [1 x i8]* @11, i32 0, i32 0)
@11 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@M_PI = global double 0x400921FB54442D18
@M_E = global double 0x4005BF0A8B145769
@M_PHI = global double 0x3FF9E3779B97F4A8
@M_EGAMMA = global double 0x3FE2788CFC6FB619
@12 = private global i8* getelementptr inbounds ([5 x i8], [5 x i8]* @13, i32 0, i32 0)
@13 = private unnamed_addr constant [5 x i8] c"none\00", align 1
@14 = private global i8* getelementptr inbounds ([5 x i8], [5 x i8]* @15, i32 0, i32 0)
@15 = private unnamed_addr constant [5 x i8] c"none\00", align 1
@16 = private global i8* getelementptr inbounds ([5 x i8], [5 x i8]* @17, i32 0, i32 0)
@17 = private unnamed_addr constant [5 x i8] c"none\00", align 1
@18 = private global i8* getelementptr inbounds ([5 x i8], [5 x i8]* @19, i32 0, i32 0)
@19 = private unnamed_addr constant [5 x i8] c"none\00", align 1

declare i32 @printf(i8*, i8*, ...)

define private void @print_string(%string %0) {
entry:
  %1 = extractvalue %string %0, 0
  %2 = load i8*, i8** @0, align 8
  %3 = call i32 (i8*, i8*, ...) @printf(i8* %2, i8* %1)
  ret void
}

define private %string @to_string_int(i64 %0) {
entry:
  %1 = alloca %string, align 8
  call void @string_Create_Default(%string* %1)
  call void @string_Resize(%string* %1, i32 24)
  %2 = getelementptr %string, %string* %1, i32 0, i32 0
  %3 = load i8*, i8** %2, align 8
  %4 = load i8*, i8** @2, align 8
  %5 = call i32 (i8*, i8*, ...) @sprintf(i8* %3, i8* %4, i64 %0)
  %6 = call i32 @strlen(i8* %3)
  %7 = getelementptr %string, %string* %1, i32 0, i32 1
  store i32 %6, i32* %7, align 4
  %8 = load %string, %string* %1, align 8
  ret %string %8
}

declare void @string_Create_Default(%string*)

declare void @string_Resize(%string*, i32)

declare i32 @sprintf(i8*, i8*, ...)

declare i32 @strlen(i8*)

define private %string @to_string_float(double %0) {
entry:
  %1 = alloca %string, align 8
  call void @string_Create_Default(%string* %1)
  call void @string_Resize(%string* %1, i32 24)
  %2 = getelementptr %string, %string* %1, i32 0, i32 0
  %3 = load i8*, i8** %2, align 8
  %4 = load i8*, i8** @4, align 8
  %5 = call i32 (i8*, i8*, ...) @sprintf(i8* %3, i8* %4, double %0)
  %6 = call i32 (i8*, ...) bitcast (i32 (i8*)* @strlen to i32 (i8*, ...)*)(i8* %3)
  %7 = getelementptr %string, %string* %1, i32 0, i32 1
  store i32 %6, i32* %7, align 4
  %8 = load %string, %string* %1, align 8
  ret %string %8
}

define private %string @to_string_bool(i1 %0) {
entry:
  %1 = alloca %string, align 8
  call void @string_Create_Default(%string* %1)
  %2 = icmp eq i1 %0, true
  br i1 %2, label %truestr, label %falsestr

truestr:                                          ; preds = %entry
  %3 = load i8*, i8** @6, align 8
  call void @string_Add_CStr(%string* %1, i8* %3)
  br label %end

falsestr:                                         ; preds = %entry
  %4 = load i8*, i8** @8, align 8
  call void @string_Add_CStr(%string* %1, i8* %4)
  br label %end

end:                                              ; preds = %falsestr, %truestr
  %5 = load %string, %string* %1, align 8
  ret %string %5
}

declare void @string_Add_CStr(%string*, i8*)

define private i64 @length_string(%string %0) {
entry:
  %1 = extractvalue %string %0, 1
  %2 = sext i32 %1 to i64
  ret i64 %2
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare double @llvm.sin.f64(double) #0

define private double @sin_float(double %0) {
entry:
  %1 = call double @llvm.sin.f64(double %0)
  ret double %1
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare double @llvm.cos.f64(double) #0

define private double @cos_float(double %0) {
entry:
  %1 = call double @llvm.cos.f64(double %0)
  ret double %1
}

declare double @tan(double)

define private double @tan_float(double %0) {
entry:
  %1 = call double @tan(double %0)
  ret double %1
}

define %string.0 @mto_string_int(i64** %v) {
entry:
  %0 = load i64*, i64** %v, align 8
  %1 = load i64, i64* %0, align 8
  %2 = icmp eq i64* %0, null
  br i1 %2, label %if.body, label %if.after

if.body:                                          ; preds = %entry
  %3 = alloca %string.0, align 8
  %4 = load i8*, i8** @12, align 8
  call void @string_Create_Init(%string.0* %3, i8* %4)
  %5 = load %string.0, %string.0* %3, align 8
  ret %string.0 %5

if.after:                                         ; preds = %entry
  %6 = load i64*, i64** %v, align 8
  %7 = load i64, i64* %6, align 8
  %8 = alloca i64, align 8
  store i64 %7, i64* %8, align 8
  %9 = load i64, i64* %8, align 8
  %10 = call %string @to_string_int(i64 %9)
  ret %string %10
}

define %string.2 @mto_string_float(double** %v) {
entry:
  %0 = load double*, double** %v, align 8
  %1 = load double, double* %0, align 8
  %2 = icmp eq double* %0, null
  br i1 %2, label %if.body, label %if.after

if.body:                                          ; preds = %entry
  %3 = alloca %string.2, align 8
  %4 = load i8*, i8** @14, align 8
  call void bitcast (void (%string.0*, i8*)* @string_Create_Init to void (%string.2*, i8*)*)(%string.2* %3, i8* %4)
  %5 = load %string.2, %string.2* %3, align 8
  ret %string.2 %5

if.after:                                         ; preds = %entry
  %6 = load double*, double** %v, align 8
  %7 = load double, double* %6, align 8
  %8 = alloca double, align 8
  store double %7, double* %8, align 8
  %9 = load double, double* %8, align 8
  %10 = call %string @to_string_float(double %9)
  ret %string %10
}

define %string.4 @mto_string_bool(i1** %v) {
entry:
  %0 = load i1*, i1** %v, align 8
  %1 = load i1, i1* %0, align 1
  %2 = icmp eq i1* %0, null
  br i1 %2, label %if.body, label %if.after

if.body:                                          ; preds = %entry
  %3 = alloca %string.4, align 8
  %4 = load i8*, i8** @16, align 8
  call void bitcast (void (%string.0*, i8*)* @string_Create_Init to void (%string.4*, i8*)*)(%string.4* %3, i8* %4)
  %5 = load %string.4, %string.4* %3, align 8
  ret %string.4 %5

if.after:                                         ; preds = %entry
  %6 = load i1*, i1** %v, align 8
  %7 = load i1, i1* %6, align 1
  %8 = alloca i1, align 1
  store i1 %7, i1* %8, align 1
  %9 = load i1, i1* %8, align 1
  %10 = call %string @to_string_bool(i1 %9)
  ret %string %10
}

define %string.6 @mto_string_string(%string.6** %v) {
entry:
  %0 = alloca %string.6, align 8
  %1 = load %string.6*, %string.6** %v, align 8
  %2 = load %string.6, %string.6* %1, align 8
  %3 = icmp eq %string.6* %1, null
  br i1 %3, label %if.body, label %if.after

if.body:                                          ; preds = %entry
  %4 = alloca %string.6, align 8
  %5 = load i8*, i8** @18, align 8
  call void bitcast (void (%string.0*, i8*)* @string_Create_Init to void (%string.6*, i8*)*)(%string.6* %4, i8* %5)
  %6 = load %string.6, %string.6* %4, align 8
  ret %string.6 %6

if.after:                                         ; preds = %entry
  %7 = load %string.6*, %string.6** %v, align 8
  %8 = load %string.6, %string.6* %7, align 8
  %9 = alloca %string.6, align 8
  store %string.6 %8, %string.6* %9, align 8
  %10 = load %string.6, %string.6* %9, align 8
  ret %string.6 %10
}

define void @_entry() {
entry:
  ret void
}

declare void @string_Create_Init(%string.0*, i8*)

define void @init_libpt() {
  ret void
}

declare void @matrix_Create_Default(%matrix*)

attributes #0 = { nofree nosync nounwind readnone speculatable willreturn }
