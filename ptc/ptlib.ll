target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%string = type {
	i8*,     ; 0: buffer; pointer to the character buffer
	i32,     ; 1: length; the number of chars in the buffer
	i32,     ; 2: maxlen; the maximum number of chars in the buffer
	i32      ; 3: factor; the number of chars to preallocate when growing
}

define fastcc void @string_Create_Default(%string* %this) nounwind {
	; Initialize 'buffer'.
	%1 = getelementptr %string, %string* %this, i32 0, i32 0
	store i8* null, i8** %1

	; Initialize 'length'.
	%2 = getelementptr %string, %string* %this, i32 0, i32 1
	store i32 0, i32* %2

	; Initialize 'maxlen'.
	%3 = getelementptr %string, %string* %this, i32 0, i32 2
	store i32 0, i32* %3

	; Initialize 'factor'.
	%4 = getelementptr %string, %string* %this, i32 0, i32 3
	store i32 16, i32* %4

    call void @string_Add_Char(%string* %this, i8 0)

    ; Initialize 'length' again to 0.
	store i32 0, i32* %2

	ret void
}

declare i8* @malloc(i32)
declare void @free(i8*)
declare i8* @memcpy(i8*, i8*, i32)

define fastcc void @string_Delete(%string* %this) nounwind {
	; Check if we need to call 'free'.
	%1 = getelementptr %string, %string* %this, i32 0, i32 0
	%2 = load i8*, i8** %1
	%3 = icmp ne i8* %2, null
	br i1 %3, label %free_begin, label %free_close

free_begin:
	call void @free(i8* %2)
	br label %free_close

free_close:
	ret void
}

define fastcc void @string_Resize(%string* %this, i32 %value) {
	; %output = malloc(%value)
	%output = call i8* @malloc(i32 %value)

	; todo: check return value

	; %buffer = this->buffer
	%1 = getelementptr %string, %string* %this, i32 0, i32 0
	%buffer = load i8*, i8** %1

	; %length = this->length
	%2 = getelementptr %string, %string* %this, i32 0, i32 1
	%length = load i32, i32* %2

	; memcpy(%output, %buffer, %length)
	%3 = call i8* @memcpy(i8* %output, i8* %buffer, i32 %length)

	; free(%buffer)
	call void @free(i8* %buffer)

	; this->buffer = %output
	store i8* %output, i8** %1

	ret void
}

define fastcc void @string_Add_Char(%string* %this, i8 %value) {
	; Check if we need to grow the string.
	%1 = getelementptr %string, %string* %this, i32 0, i32 1
	%length = load i32, i32* %1
	%2 = getelementptr %string, %string* %this, i32 0, i32 2
	%maxlen = load i32, i32* %2
	; if length == maxlen:
	%3 = icmp eq i32 %length, %maxlen
	br i1 %3, label %grow_begin, label %grow_close

grow_begin:
	%4 = getelementptr %string, %string* %this, i32 0, i32 3
	%factor = load i32, i32* %4
	%5 = add i32 %maxlen, %factor
	call void @string_Resize(%string* %this, i32 %5)
	br label %grow_close

grow_close:
	%6 = getelementptr %string, %string* %this, i32 0, i32 0
	%buffer = load i8*, i8** %6
	%7 = getelementptr i8, i8* %buffer, i32 %length
	store i8 %value, i8* %7
	%8 = add i32 %length, 1
	store i32 %8, i32* %1

	ret void
}

declare i32 @strlen(i8*)

define fastcc void @string_Add_CStr(%string* %this, i8* %value) {
    %vlen = call i32 @strlen(i8* %value)
	; Check if it's an empty string
	%empty = icmp eq i32 %vlen, 0
	br i1 %empty, label %end, label %add_str
add_str:
    ; Check if we need to grow the string.
	%1 = getelementptr %string, %string* %this, i32 0, i32 1
	%length = load i32, i32* %1
	%2 = getelementptr %string, %string* %this, i32 0, i32 2
	%maxlen = load i32, i32* %2
	; if length+vlen >= maxlen:
    %lennew = add i32 %length, %vlen
    ; add 1 for \0
    %lennewzero = add i32 %lennew, 1
	%3 = icmp uge i32 %lennewzero, %maxlen
	br i1 %3, label %grow_begin, label %grow_close
grow_begin:
	%4 = getelementptr %string, %string* %this, i32 0, i32 3
	%factor = load i32, i32* %4
	%isbigger = icmp uge i32 %factor, %vlen
	br i1 %isbigger, label %growbyfact, label %growbylen
growbyfact:
	%5 = add i32 %maxlen, %factor
	call void @string_Resize(%string* %this, i32 %5)
	br label %grow_close
growbylen:
	; TODO: Compute closes power of 2 for vlen
	%factlen = add i32 %maxlen, %vlen
	call void @string_Resize(%string* %this, i32 %factlen)
	br label %grow_close
grow_close:
	%6 = getelementptr %string, %string* %this, i32 0, i32 0
	%buffer = load i8*, i8** %6
    ; int *ichar
    %icharptr = alloca i32
    ; *ichar = 0
    store i32 0, i32* %icharptr
    ; this->length = lennew
    br label %grow_loop
grow_loop:
    ; int ival = *i
    %ichar = load i32, i32* %icharptr
    %ival = add i32 %length, %ichar
    ; char *v7 = &buffer[ival] 
	%7 = getelementptr i8, i8* %buffer, i32 %ival
    ; char *chrptr = &value[ichar]
    %chrptr = getelementptr i8, i8* %value, i32 %ichar
    ; char chr = *charptr
    %chr = load i8, i8* %chrptr
    ; *v7 = chr
	store i8 %chr, i8* %7
	; int inex = ival + 1
    %inew = add i32 %ival, 1
    ;
    %icharnew = add i32 %ichar, 1
    store i32 %icharnew, i32* %icharptr
    ; bool v8 = inew == reslen
    %8 = icmp eq i32 %icharnew, %vlen
    br i1 %8, label %grow_end, label %grow_loop
grow_end:
	store i32 %lennew, i32* %1
    ; Store zero as the last value
    %9 = getelementptr i8, i8* %buffer, i32 %lennew
    store i8 0, i8* %9
	br label %end
end:
    ret void
}

define fastcc void @string_Add_Str(%string* %res, %string %src1, %string %src2) {
	%buffer = extractvalue %string %src1, 0
	call void @string_Create_Init(%string* %res, i8* %buffer)
	%buffer2 = extractvalue %string %src2, 0
	call void @string_Add_CStr(%string* %res, i8* %buffer2)
	ret void
}

define fastcc void @string_Create_Init(%string* %this, i8* %value) nounwind {
	call void @string_Create_Default(%string* %this)
	call void @string_Add_CStr(%string* %this, i8* %value)
	ret void
}

%matrix = type {
	i8*,  ; data
	i32,  ; length
	i32,  ; maxlen
	i32   ; factor
}

define fastcc void @matrix_Create_Default(%matrix* %this) nounwind {
	; Initialize 'buffer'.
	%1 = getelementptr %matrix, %matrix* %this, i32 0, i32 0
	store i8* null, i8** %1

	; Initialize 'length'.
	%2 = getelementptr %matrix, %matrix* %this, i32 0, i32 1
	store i32 0, i32* %2

	; Initialize 'maxlen'.
	%3 = getelementptr %matrix, %matrix* %this, i32 0, i32 2
	store i32 0, i32* %3

	; Initialize 'factor'.
	%4 = getelementptr %matrix, %matrix* %this, i32 0, i32 3
	store i32 16, i32* %4

	ret void
}

define fastcc void @matrix_Delete(%matrix* %this) nounwind {
	; Check if we need to call 'free'.
	%1 = getelementptr %matrix, %matrix* %this, i32 0, i32 0
	%2 = load i8*, i8** %1
	%3 = icmp ne i8* %2, null
	br i1 %3, label %free_begin, label %free_close

free_begin:
	call void @free(i8* %2)
	br label %free_close

free_close:
	ret void
}

define fastcc void @matrix_Resize(%matrix* %this, i32 %value) {
	; %output = malloc(%value)
	%output = call i8* @malloc(i32 %value)

	; todo: check return value

	; %buffer = this->buffer
	%1 = getelementptr %matrix, %matrix* %this, i32 0, i32 0
	%buffer = load i8*, i8** %1

	; %length = this->length
	%2 = getelementptr %matrix, %matrix* %this, i32 0, i32 1
	%length = load i32, i32* %2

	; memcpy(%output, %buffer, %length)
	%3 = call i8* @memcpy(i8* %output, i8* %buffer, i32 %length)

	; free(%buffer)
	call void @free(i8* %buffer)

	; this->buffer = %output
	store i8* %output, i8** %1

	ret void
}

define fastcc void @matrix_Append_Prepare(%matrix* %this) {
	; Check if we need to grow the matrix.
	%1 = getelementptr %matrix, %matrix* %this, i32 0, i32 1
	%length = load i32, i32* %1
	%2 = getelementptr %matrix, %matrix* %this, i32 0, i32 2
	%maxlen = load i32, i32* %2
	; if length == maxlen:
	%3 = icmp eq i32 %length, %maxlen
	br i1 %3, label %grow_begin, label %grow_close

grow_begin:
	%4 = getelementptr %matrix, %matrix* %this, i32 0, i32 3
	%factor = load i32, i32* %4
	%5 = add i32 %maxlen, %factor
	%actsize = mul i32 %5, 8
	call void @matrix_Resize(%matrix* %this, i32 %actsize)
	br label %grow_close

grow_close:
	%6 = getelementptr %matrix, %matrix* %this, i32 0, i32 0
	%buffer = load i8*, i8** %6
	;%casted = bitcast i8* %buffer to i64*
	;%7 = getelementptr i64, i64* %casted, i32 %length
	;store i64 %value, i64* %7
	%7 = add i32 %length, 1
	store i32 %7, i32* %1

	ret void
}