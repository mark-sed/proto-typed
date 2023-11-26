; ModuleID = 'ptc/libpt.pt'
source_filename = "ptc/libpt.pt"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%string = type { i8*, i32, i32, i32 }
%string.0 = type { i8*, i32, i32, i32 }
%string.2 = type { i8*, i32, i32, i32 }
%string.4 = type { i8*, i32, i32, i32 }
%string.6 = type { i8*, i32, i32, i32 }
%string.8 = type { i8*, i32, i32, i32 }
%string.10 = type { i8*, i32, i32, i32 }
%string.12 = type { i8*, i32, i32, i32 }
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
@20 = private global i8* getelementptr inbounds ([1 x i8], [1 x i8]* @21, i32 0, i32 0)
@21 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@22 = private global i8* getelementptr inbounds ([1 x i8], [1 x i8]* @23, i32 0, i32 0)
@23 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@24 = private global i8* getelementptr inbounds ([1 x i8], [1 x i8]* @25, i32 0, i32 0)
@25 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@26 = private global i8* getelementptr inbounds ([1 x i8], [1 x i8]* @27, i32 0, i32 0)
@27 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@28 = private global i8* getelementptr inbounds ([1 x i8], [1 x i8]* @29, i32 0, i32 0)
@29 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@30 = private global i8* getelementptr inbounds ([1 x i8], [1 x i8]* @31, i32 0, i32 0)
@31 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@32 = private global i8* getelementptr inbounds ([1 x i8], [1 x i8]* @33, i32 0, i32 0)
@33 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@34 = private global i8* getelementptr inbounds ([1 x i8], [1 x i8]* @35, i32 0, i32 0)
@35 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1

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

define private i64 @ord_string(%string %0) {
entry:
  %1 = extractvalue %string %0, 0
  %2 = load i8, i8* %1, align 1
  %3 = zext i8 %2 to i64
  ret i64 %3
}

define private %string @chr_int(i64 %0) {
entry:
  %1 = alloca %string, align 8
  call void @string_Create_Default(%string* %1)
  %2 = trunc i64 %0 to i8
  call void @string_Add_Char(%string* %1, i8 %2)
  %3 = load %string, %string* %1, align 8
  ret %string %3
}

declare void @string_Add_Char(%string*, i8)

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

define %string.8 @upper_string(%string.8 %s) {
entry:
  %0 = alloca %string.8, align 8
  store %string.8 %s, %string.8* %0, align 8
  %1 = alloca %string.8, align 8
  %2 = alloca %string.8, align 8
  %3 = load i8*, i8** @20, align 8
  call void bitcast (void (%string.0*, i8*)* @string_Create_Init to void (%string.8*, i8*)*)(%string.8* %2, i8* %3)
  %4 = load %string.8, %string.8* %2, align 8
  %5 = alloca %string.8, align 8
  store %string.8 %4, %string.8* %5, align 8
  %6 = alloca i64, align 8
  %7 = alloca i64, align 8
  store i64 0, i64* %6, align 8
  store i64 1, i64* %7, align 8
  %8 = alloca %string.8, align 8
  %9 = load i8*, i8** @22, align 8
  call void bitcast (void (%string.0*, i8*)* @string_Create_Init to void (%string.8*, i8*)*)(%string.8* %8, i8* %9)
  %10 = load %string.8, %string.8* %8, align 8
  %11 = alloca %string.8, align 8
  store %string.8 %10, %string.8* %11, align 8
  br label %for.cond

for.cond:                                         ; preds = %for.next, %entry
  %12 = load i64, i64* %6, align 8
  %13 = load %string.8, %string.8* %0, align 8
  %14 = call i64 bitcast (i64 (%string)* @length_string to i64 (%string.8)*)(%string.8 %13)
  %15 = icmp slt i64 %12, %14
  br i1 %15, label %for.body, label %for.after

range.posstep:                                    ; No predecessors!

range.negstep:                                    ; No predecessors!

for.body:                                         ; preds = %for.cond
  %16 = call i8* @llvm.stacksave()
  %17 = alloca %string.8, align 8
  %18 = load i8*, i8** @24, align 8
  call void bitcast (void (%string.0*, i8*)* @string_Create_Init to void (%string.8*, i8*)*)(%string.8* %17, i8* %18)
  %19 = load %string.8, %string.8* %17, align 8
  %20 = extractvalue %string.8 %13, 0
  %21 = getelementptr i8, i8* %20, i64 %12
  %22 = load i8, i8* %21, align 1
  call void bitcast (void (%string*, i8)* @string_Add_Char to void (%string.8*, i8)*)(%string.8* %17, i8 %22)
  %23 = load %string.8, %string.8* %17, align 8
  %24 = load %string.8, %string.8* %11, align 8
  store %string.8 %23, %string.8* %11, align 8
  %25 = load %string.8, %string.8* %11, align 8
  %26 = call i64 @ord_string(%string.8 %25)
  %27 = alloca i64, align 8
  store i64 %26, i64* %27, align 8
  %28 = load i64, i64* %27, align 8
  %29 = icmp sgt i64 %28, 96
  %30 = load i64, i64* %27, align 8
  %31 = icmp slt i64 %30, 123
  %32 = and i1 %29, %31
  br i1 %32, label %if.body, label %if.else

for.next:                                         ; preds = %if.after
  %33 = load i64, i64* %7, align 8
  %34 = add i64 %12, %33
  store i64 %34, i64* %6, align 8
  call void @llvm.stackrestore(i8* %16)
  br label %for.cond

for.after:                                        ; preds = %for.cond
  %35 = load %string.8, %string.8* %5, align 8
  ret %string.8 %35

if.body:                                          ; preds = %for.body
  %36 = load %string.8, %string.8* %5, align 8
  %37 = load %string.8, %string.8* %5, align 8
  %38 = load i64, i64* %27, align 8
  %39 = xor i64 %38, 32
  %40 = call %string @chr_int(i64 %39)
  %41 = alloca %string.8, align 8
  call void @string_Add_Str(%string.8* %41, %string.8 %37, %string %40)
  %42 = load %string.8, %string.8* %41, align 8
  store %string.8 %42, %string.8* %5, align 8
  br label %if.after

if.else:                                          ; preds = %for.body
  %43 = load %string.8, %string.8* %5, align 8
  %44 = load %string.8, %string.8* %5, align 8
  %45 = load %string.8, %string.8* %11, align 8
  %46 = alloca %string.8, align 8
  call void @string_Add_Str(%string.8* %46, %string.8 %44, %string.8 %45)
  %47 = load %string.8, %string.8* %46, align 8
  store %string.8 %47, %string.8* %5, align 8
  br label %if.after

if.after:                                         ; preds = %if.else, %if.body
  br label %for.next
}

define %string.10 @lower_string(%string.10 %s) {
entry:
  %0 = alloca %string.10, align 8
  store %string.10 %s, %string.10* %0, align 8
  %1 = alloca %string.10, align 8
  %2 = alloca %string.10, align 8
  %3 = load i8*, i8** @26, align 8
  call void bitcast (void (%string.0*, i8*)* @string_Create_Init to void (%string.10*, i8*)*)(%string.10* %2, i8* %3)
  %4 = load %string.10, %string.10* %2, align 8
  %5 = alloca %string.10, align 8
  store %string.10 %4, %string.10* %5, align 8
  %6 = alloca i64, align 8
  %7 = alloca i64, align 8
  store i64 0, i64* %6, align 8
  store i64 1, i64* %7, align 8
  %8 = alloca %string.10, align 8
  %9 = load i8*, i8** @28, align 8
  call void bitcast (void (%string.0*, i8*)* @string_Create_Init to void (%string.10*, i8*)*)(%string.10* %8, i8* %9)
  %10 = load %string.10, %string.10* %8, align 8
  %11 = alloca %string.10, align 8
  store %string.10 %10, %string.10* %11, align 8
  br label %for.cond

for.cond:                                         ; preds = %for.next, %entry
  %12 = load i64, i64* %6, align 8
  %13 = load %string.10, %string.10* %0, align 8
  %14 = call i64 bitcast (i64 (%string)* @length_string to i64 (%string.10)*)(%string.10 %13)
  %15 = icmp slt i64 %12, %14
  br i1 %15, label %for.body, label %for.after

range.posstep:                                    ; No predecessors!

range.negstep:                                    ; No predecessors!

for.body:                                         ; preds = %for.cond
  %16 = call i8* @llvm.stacksave()
  %17 = alloca %string.10, align 8
  %18 = load i8*, i8** @30, align 8
  call void bitcast (void (%string.0*, i8*)* @string_Create_Init to void (%string.10*, i8*)*)(%string.10* %17, i8* %18)
  %19 = load %string.10, %string.10* %17, align 8
  %20 = extractvalue %string.10 %13, 0
  %21 = getelementptr i8, i8* %20, i64 %12
  %22 = load i8, i8* %21, align 1
  call void bitcast (void (%string*, i8)* @string_Add_Char to void (%string.10*, i8)*)(%string.10* %17, i8 %22)
  %23 = load %string.10, %string.10* %17, align 8
  %24 = load %string.10, %string.10* %11, align 8
  store %string.10 %23, %string.10* %11, align 8
  %25 = load %string.10, %string.10* %11, align 8
  %26 = call i64 @ord_string(%string.10 %25)
  %27 = alloca i64, align 8
  store i64 %26, i64* %27, align 8
  %28 = load i64, i64* %27, align 8
  %29 = icmp sgt i64 %28, 64
  %30 = load i64, i64* %27, align 8
  %31 = icmp slt i64 %30, 91
  %32 = and i1 %29, %31
  br i1 %32, label %if.body, label %if.else

for.next:                                         ; preds = %if.after
  %33 = load i64, i64* %7, align 8
  %34 = add i64 %12, %33
  store i64 %34, i64* %6, align 8
  call void @llvm.stackrestore(i8* %16)
  br label %for.cond

for.after:                                        ; preds = %for.cond
  %35 = load %string.10, %string.10* %5, align 8
  ret %string.10 %35

if.body:                                          ; preds = %for.body
  %36 = load %string.10, %string.10* %5, align 8
  %37 = load %string.10, %string.10* %5, align 8
  %38 = load i64, i64* %27, align 8
  %39 = xor i64 %38, 32
  %40 = call %string @chr_int(i64 %39)
  %41 = alloca %string.10, align 8
  call void bitcast (void (%string.8*, %string.8, %string.8)* @string_Add_Str to void (%string.10*, %string.10, %string.10)*)(%string.10* %41, %string.10 %37, %string %40)
  %42 = load %string.10, %string.10* %41, align 8
  store %string.10 %42, %string.10* %5, align 8
  br label %if.after

if.else:                                          ; preds = %for.body
  %43 = load %string.10, %string.10* %5, align 8
  %44 = load %string.10, %string.10* %5, align 8
  %45 = load %string.10, %string.10* %11, align 8
  %46 = alloca %string.10, align 8
  call void bitcast (void (%string.8*, %string.8, %string.8)* @string_Add_Str to void (%string.10*, %string.10, %string.10)*)(%string.10* %46, %string.10 %44, %string.10 %45)
  %47 = load %string.10, %string.10* %46, align 8
  store %string.10 %47, %string.10* %5, align 8
  br label %if.after

if.after:                                         ; preds = %if.else, %if.body
  br label %for.next
}

define %string.12 @reverse_string(%string.12 %s) {
entry:
  %0 = alloca %string.12, align 8
  store %string.12 %s, %string.12* %0, align 8
  %1 = alloca %string.12, align 8
  %2 = alloca %string.12, align 8
  %3 = load i8*, i8** @32, align 8
  call void bitcast (void (%string.0*, i8*)* @string_Create_Init to void (%string.12*, i8*)*)(%string.12* %2, i8* %3)
  %4 = load %string.12, %string.12* %2, align 8
  %5 = alloca %string.12, align 8
  store %string.12 %4, %string.12* %5, align 8
  %6 = alloca i64, align 8
  %7 = alloca i64, align 8
  %8 = load %string.12, %string.12* %0, align 8
  %9 = call i64 @length_string(%string.12 %8)
  %10 = sub nsw i64 %9, 1
  store i64 %10, i64* %6, align 8
  %11 = icmp sge i64 -1, %10
  br i1 %11, label %range.step.pos, label %range.step.neg

range.step.pos:                                   ; preds = %entry
  store i64 1, i64* %7, align 8
  br label %range.step.end

range.step.neg:                                   ; preds = %entry
  store i64 -1, i64* %7, align 8
  br label %range.step.end

range.step.end:                                   ; preds = %range.step.neg, %range.step.pos
  %12 = alloca i64, align 8
  store i64 0, i64* %12, align 8
  br label %for.cond

for.cond:                                         ; preds = %for.next, %range.step.end
  %13 = load i64, i64* %6, align 8
  %14 = load i64, i64* %7, align 8
  %15 = icmp sgt i64 %14, 0
  br i1 %15, label %range.posstep, label %range.negstep

range.posstep:                                    ; preds = %for.cond
  %16 = icmp slt i64 %13, -1
  br i1 %16, label %for.body, label %for.after

range.negstep:                                    ; preds = %for.cond
  %17 = icmp sgt i64 %13, -1
  br i1 %17, label %for.body, label %for.after

for.body:                                         ; preds = %range.negstep, %range.posstep
  %18 = call i8* @llvm.stacksave()
  %19 = load i64, i64* %12, align 8
  store i64 %13, i64* %12, align 8
  %20 = load %string.12, %string.12* %5, align 8
  %21 = load %string.12, %string.12* %5, align 8
  %22 = load %string.12, %string.12* %0, align 8
  %23 = load i64, i64* %12, align 8
  %24 = alloca %string.12, align 8
  %25 = load i8*, i8** @34, align 8
  call void bitcast (void (%string.0*, i8*)* @string_Create_Init to void (%string.12*, i8*)*)(%string.12* %24, i8* %25)
  %26 = load %string.12, %string.12* %24, align 8
  %27 = extractvalue %string.12 %22, 0
  %28 = getelementptr i8, i8* %27, i64 %23
  %29 = load i8, i8* %28, align 1
  call void bitcast (void (%string*, i8)* @string_Add_Char to void (%string.12*, i8)*)(%string.12* %24, i8 %29)
  %30 = load %string.12, %string.12* %24, align 8
  %31 = alloca %string.12, align 8
  call void bitcast (void (%string.8*, %string.8, %string.8)* @string_Add_Str to void (%string.12*, %string.12, %string.12)*)(%string.12* %31, %string.12 %21, %string.12 %30)
  %32 = load %string.12, %string.12* %31, align 8
  store %string.12 %32, %string.12* %5, align 8
  br label %for.next

for.next:                                         ; preds = %for.body
  %33 = load i64, i64* %7, align 8
  %34 = add i64 %13, %33
  store i64 %34, i64* %6, align 8
  call void @llvm.stackrestore(i8* %18)
  br label %for.cond

for.after:                                        ; preds = %range.negstep, %range.posstep
  %35 = load %string.12, %string.12* %5, align 8
  ret %string.12 %35
}

define void @_entry() {
entry:
  ret void
}

declare void @string_Create_Init(%string.0*, i8*)

; Function Attrs: nofree nosync nounwind willreturn
declare i8* @llvm.stacksave() #1

; Function Attrs: nofree nosync nounwind willreturn
declare void @llvm.stackrestore(i8*) #1

declare void @string_Add_Str(%string.8*, %string.8, %string.8)

define void @init_libpt() {
  ret void
}

declare void @matrix_Create_Default(%matrix*)

attributes #0 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #1 = { nofree nosync nounwind willreturn }
