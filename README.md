# Proto-typed

Proto-typed (pt) is a compiled statically typed language with garbage collection and modern syntax.

As the name suggests, proto-typed was designed for writing prototypes and short simple programs in a compiled and typed manner.

This repository contains Proto-typed Compiler (ptc) and the language definition in textual form.

#### Table of contents
- [Proto-typed Project](#proto-typed)
- [How to run programs](#how-to-run-programs-with-pt)
  - [Download](#download)
  - [Installation from source](#installation-from-source)
  - [Using pt to run programs](#Using-pt-to-run-programs-with-pt)
- [Proto-typed Programming Language](#proto-typed-programming-language)
  - [Code examples](#code-examples)
  - [Types](#types)
  - [Syntax](#syntax)
  - [Semantics](#semantics)
  - [Standard library](#standard-library)
- [Proto-typed Compiler](#proto-typed-compiler)
  - [Known issues](#known-issues)

# How to run programs with pt

PT is a standalone program that can be used to compile and run proto-typed programs. Just as the language, it has a straight forward and simple design, but can be customized.

It has 3 commands:
* `build` - Build compiles the program.
* `run` - Run compiles the program and runs it.
* `see` - Run compiles the program, runs it and deletes the binary.

Options for `pt` has to be specified before the command, for `ptc` after the command and arguments to the program after `--`.

1. Create your pt program `hello.pt`:
```
print("Hello, World!\n")
```

2. Run the program using `pt`:
```
pt run hello.pt
```

This will output:
> Hello, World!

and create binary `hello`.

## Download

Soon precompiled ptc releases should be available under release section in GitHub (https://github.com/mark-sed/proto-typed/releases).

## Installation from source

As mentioned before, ptc relies on LLVM and expects it to be installed.
The ptc can be compiled from [source](https://github.com/mark-sed/proto-typed) using CMake with the following steps.

1. Clone the repository (or download it as a zip in GitHub):
```shell
git clone https://github.com/mark-sed/proto-typed.git
```
2. Enter the repository and create a `build` directory:
```shell
cd proto-typed
mkdir build
```
3. Run CMake for pt compiler:
```shell
cmake -S . -B build
cmake --build build --target ptc
```

4. (Optional) Run CMake for pt utility:
```shell
cmake --build build --target pt
```

After running this inside of `build` you should find compiled proto-typed compiler named `ptc` and compiled `pt` utility.

Note that `pt` is currently available only for Linux. To have ptc and pt accessible from anywhere and everything have easy to use, you can use `install.sh` script to place all the needed files into the expected places:

5. (Optional) Setting up pt path and libs:
```shell
sudo bash install.sh
```

# Proto-typed Programming Language

Proto-typed (pt) is a compiled statically typed language with garbage collection and modern syntax. But it offers lot more, here is a list of some of the key proto-typed features:

* Compiled.
* Statically typed.
* Support for modules and simple compilation of multiple modules (only main module path needs to be specified, rest will be found by the compiler).
* Automatic memory management (garbage collection).
* Dynamic `any` type.
* Maybe types (hold value of specified type or `none`).
* Function overloading.
* No need for forward declaration of functions.
* Implicit main function generation (code similar to interpreted scripts).
* C library functions and simple invocation of C functions (_not yet implemented_).

## Code examples

Before going through in depth code features, here are some simple code examples to showcase the syntax.

### Hello World

```c
print("Hello, World!\n")
```

### Fibonacci sequence
```c
int fib(int n) {
    if(n < 2) return n
    return fib(n - 1) + fib(n - 2)
}

int index = 42
print("Fibonacci for index "++index++" is "++fib(index))
```

## Types

Proto-typed offers simple types and user defined structures. These types can then be constructed into arrays or maybe versions.

All variables are initialized to their default value if not initialized explicitly.

There are in fact 2 groups of types, the first - primitive - does not require runtime initialization (`int`, `float`, `bool` and value `none`) and the second - composite - which requires runtime initialization (`string`, maybe type including `any`, arrays and `struct`).

### Int

Signed whole number represented by 64 bits. Such number can be written in decimal, binary (prefix `0b` or `0B`), octal (prefix `0q` or `0Q`) or hexadecimal (prefix `0x` or `0X`) format.

```c
int a_dec = 42       // Decimal
int a_bin = 0b101010 // Binary
int a_oct = 0q52     // Octal
int a_hex = 0x2A     // Hexadecimal
```

### Float

Floating point number represented by 64 bits. It can be also written using scientific notation.

```c
float not_pi = 3.14159265
float avogardo = 6.02214076e23
float rnd = -22e-8
```

Note that for the purpose of correct range parsing, float cannot start or end with only `.` - you cannot write `2.`, but have to write `2.0` and the same for `.5`, which has to be `0.5`.

### Bool

Boolean value capable of containing either `true` or `false` value.

```c
bool slow // false (default value) 
bool compiled = true
```

### String

Dynamic unicode array of characters. String support escape sequences.

```c
string boring_text = "sushi\n\tramen."
string cool_text = "寿司\n\t拉麺"
string cooler_text = "🍣\n\t🍜."
string pozdrav = "Ahoj, jak se máš?"
```

String can also be written as "raw strings" or "rstrings", where no escape sequences are parsed. Such strings have to pre prefixed with `r`:
```c
string raw_text = r"New line is written as \n and \ has to be escaped by another \ in normal strings."
```

Characters can be also encoded using escape sequences, these can be in octal (`\q` or `\Q`) or hexadecimal (`\x` or `\X`) after their prefix in braces `{}`:
```c
string space = "\x{20}"
string space8 = "\Q{12}"
```

Unicode characters can also be escaped using the `\U` or `\u` prefix followed by the character's hexadecimal code.
```c
string potassium_source = "\U{0001f34c}"
```

Strings are represented as simple objects and therefore their size can be easily determined in constant time, but at the same time string's character buffer is zero terminated making it compatible with many C functions.

String can be also sliced. Slicing has a form of `[start..end]` or `[start,next..end]` (range inside of `[]`):
```c
string dna_seqence = "a-c-c-g-t-a-t-g"
string amino_acids = dna_seqence[0,2..length(dna_seqence)]
```

Slice can also use descending range and therefore reverse a string. Keep in mind, that end is not included in the range, but start is and therefore there needs to be some adjustments:
```c
string dna_seqence = "a-c-c-g-t-a-t-g"
int l = length(dna_seqence) - 1
string reversed_aas = dna_seqence[l, l - 2 .. -1]
```

### Struct

Structs can hold variables of any type, but cannot contain function definitions withing their scope. When referring to a struct type only the name can be used (without the `struct` keyword).

```cpp
struct Pair {
    int first
    int second
}

Pair p
p.first = foo()
p.second = bar()

print(p.first++", "++p.second)
```

Structs can also have default initializers for their elements:
```cpp
struct Player {
    string name = "Unknown"
    float strength = 10.5
    int x = 350
    int y = 200
}
```

### Array (matrix)

Arrays in pt are dynamic (you can think of them as vectors in C++).
Array type is defined by putting `[]` after type name:
```c
int[] values
for (int i : 0..20) {
    append(values, i)
}

for (int c: values) {
    print(c++" ")
}
```

Multidimensional arrays (matrices) work in the same way:
```c
int[][] pos = [
    [0, 1, 2, 8],
    [9, 0, 8, 3],
    [2, 3, 5, 6],
    [0, 1, 1, 4]
]

string[][] tt = [
    ["x", "o", "x"],
    ["x", "x", "o"],
    ["o", "x", "o"]
]

string center = tt[1][1]
```

Array is also result of slicing. Slicing has a form of `[start..end]` or `[start,next..end]` (range inside of `[]`):
```c
float x = [0.2, 1.3, 4.5, 5.0, 0.0, 9.9, 7.1, 1.0]
for (float i : x[1,2..6]) {
    print(i++" ") // 1.3 5.0 9.9 
}

float y = x[0..2] // [0.2, 1.3] 
```

### Maybe

Maybe value can either hold value of its base type or `none`.

```c
int? x // none by default
x = -7
```

Every maybe value is passed by a reference to a function and can therefore be used to modify input arguments:
```c
void pow2(int? x) {
    x = x * x
}

int v = 5
pow2(v)
print(v++"\n")
```

But don't think of maybe values as of pointers or references since any function taking a maybe value can accept any base value, including a constant:
```c
void pow2(int? x) {
    x = x * x
}

pow2(42)
```

But there is still a difference when passing maybe and actual value to a function. Maybe to maybe assignment will work only for actual maybe value passed in. In the following example the assignment in function `getK` assigns address to passed in argument, but when the passed in value is not a maybe type, what is modified is the address of parameter (`x`), not the address of passed in variable (`k`):
```c
void getK(int? x) {
    any KVAL = 7542
    x = KVAL
}

int? maybe_k
int k

getK(maybe_k)
getK(k)

print(maybe_k++" "++k) // 7542 0
```

When assigning a maybe value to another maybe value, both of these will contain the same address and therefore the same value:
```c
string? a = "hi"
string? b

b = a
b = "bye"
print(a) // bye
```

### Any

Any type (not surprisingly) can hold any value. But what it holds is only known to the user not the compiler and therefore it is easy to get a runtime error. To extract a value it has to be assigned or implicitly casted.

```c
any x = 42
// code ...
x = "forty two"
string y = x
print(y)
```

Any type has to be internally represented as a maybe type (to be able to hold `none`), which might cause some problems with maybe to maybe assignment and memory sharing:
```c
any x = 32
int? y
y = x
x = "Ca vas pas"
print(y++"\n") // Incorrect value - string read as int
```

Any type, unlike maybe type, is checked as an address and not a value (as it is only known to the user what type is stored there).

### Function type

Function type is always a maybe type (the `?` is implicit, just like with any) and therefore it can hold `none`.

Function type has the following syntax:
```
<return type>(<optional list of argument types>) <variable name>
```

For example:
```c
bool isBig(int? a, bool warn) {
    if(a != none) {
        return a > 100 
    }
    if(warn) print("is none")
    return false
}

bool(int?, bool) funIsBig
funIsBig = isBig

print(funIsBig(4, false) as string)
```

Function type can also be taken as an argument:
```c
void err_print(string s) {
    print("Error: "++s++"\n")
}

void report(void(string) rep_fun, string msg) {
    rep_fun(msg)
}

report(err_print, "Oops!")
report(print, "Never mind!")
```

## Syntax

Proto-typed aims for having a simple syntax, that allows good code readability and writing, as it's main purpose is prototyping and small programs. 

### Statements

End of statement in pt can be marked with (1) a new line (`\n`), (2) a semicolon (`;`), (3) the end of the certain construct or (4) end of file.

Example (1):
```c
int a = 42
int b = 0
```
which is equivalent to (2, 4):
```c
int a = 42; int b = 0
```
In case of constructs ending with `}` (3), there is no need for `;` or `\n`:
```c
if(a) {
    c = 42;
} print("hello")
```

### Comments

Proto-typed supports c-style one line comments (`//`) and multiline comments (`/**/`):
```c
// Single line comments

/*
 Multiline
 comment 
*/
```

### Modules

Importing a module is done using the `import` keyword followed by the module's name (without its extension) or comma separated list of module names:
```cpp
import bigmath
import window, controller, handler
```

Every function, global variable and type (struct) can be accessed from another module.

To access external module symbols the symbol has to be always prefaced by the imported module's name, then 2 colons - scope (`::`) - followed by the symbols name.

File _mod2.pt_:
```c
string NAME = "mod2"

int get_key() {
    return 42
}
```

File _main.pt_:
```c
import mod2

print("Key for module " ++ mod2::NAME ++ " is: " ++ mod2::get_key())
```

### Functions

Functions use c-style syntax of return type followed by the name, arguments and then the body:
```c
int foo(float a, bool b) {
    int r
    // Code ...
    return r
}
```

Proto-typed has a support for function overloading (multiple functions with the same name, but different arguments):
```c
void add(int a, int b) {
    print((a + b)++"\n")
}

void add(string a, string b) {
    print(a ++ b ++"\n")
}

add(4, 8)     // 12
add("h", "i") // hi
```

### If statements

If statement's expression has to be boolean value (int or maybe won't be implicitly converted), the same is true for while and do-while.
If follows the c-style syntax as well:
```c
if (a == 0) {
    foo(c)
} else if (a == 1) {
    bar(c)
} else {
    baz(c)
}
```

If does not require `{}` if it is followed only by one statement, but keep in mind that in proto-typed new line is the terminator for a statement and therefore, unlike C, it does not allow for arbitrary amount of new lines after if. Fortunately, proto-typed will emit an error when such incorrect case happens.

```c
if (a)
    print("Hi")    // Syntax error

else print("Bye")  // Syntax error

if (a) print("Hi") // Correct
else print("Bye")  // Correct
```

Also keep in mind that the statement following if has to be terminated as well, either by a new line or a semicolon and therefore when writing a one-line if-else, one must use semicolon (or `{}`) after each statement:

```c
if (a) print("Hi") else print("Bye")  // Syntax error
if (a) print("Hi"); else print("Bye") // Correct
```

### While and Do-while loops

While and do-while loops have the following syntax:

```c
while (a < 10) {
    // code
    a += 1
}

do {
    // code
    a += 1
} while (a < 10)
```

### For loops

For works more like a for each loop, where it iterates over ranges, arrays or strings:

```c
float[] values
// init values
for (float i : values) {
    print(i++"\n")
}

string text = "Some text"
for (string letter: text) {
    print(letter++" ")
}
```

Proto-typed also offers special type `range` (see more bellow), which can be used counted for loops:
```c
for (int i : 0..5) {
    print(i++" ") // 0 1 2 3 4
}

for (int j : 0,2..5) {
    print(j++" ") // 0 2 4
}

string text = "Some more text"
for (int k : 0..length(text)) {
    print(k++": "++text[k]++"\n")
}
```

### Operators

Following table contains pt operators from highest precedence to the lowest.

| **Operator**                                                                                 | **Description**                                                  | **Associativity** |
|----------------------------------------------------------------------------------------------|------------------------------------------------------------------|-------------------|
| `::`                                                                                         | Module scope                                                     | none              |
| `()`, `[]`, `[..]`                                                                           | Function call, array indexing, slicing                           | none              |
| `as`                                                                                         | Type casting                                                     | left              |
| `.`                                                                                          | Structure member access                                          | left              |
| `not`, `~`                                                                                   | Logical NOT, bitwise NOT                                         | right             |
| `**`                                                                                         | Exponentiation (returns `float`)                                 | right             |
| `*`, `/`, `%`                                                                                | Multiplication, division, reminder                               | left              |
| `+`, `-`                                                                                     | Addition/array join, subtraction                                 | left              |
| `<<`, `>>`                                                                                   | Bitwise left shift, bitwise right shift                          | left              |
| `..`                                                                                         | Range                                                            | left              |
| `>`, `>=`, `<`, `<=`                                                                         | Bigger than, bigger than or equal, less than, less than or equal | left              |
| `==`, `!=`                                                                                   | Equality, inequality                                             | left              |
| `&`                                                                                          | Bitwise AND                                                      | left              |
| `^`                                                                                          | Bitwise XOR                                                      | left              |
| `\|`                                                                                         | Bitwise OR                                                       | left              |
| `in`                                                                                         | Membership                                                       | left              |
| `and`                                                                                        | Logical AND                                                      | left              |
| `or`                                                                                         | Logical OR                                                       | left              |
| `++`                                                                                         | Concatenation                                                    | left              |
| `=`, `++=`, `**=`, `+=`,  `-=`, `/=`, `*=`, `%=`,  `&=`, `\|=`, `^=`, `~=`,  `<<=`, `>>=`    | Assignment, compound assignments                                 | left              |

## Semantics

Proto-typed does not provide some of the higher level constructs such as classes and objects, but at the same time tries to provide abstractions for simple and quick coding. Example of such abstractions is the memory managements handled by the garbage collector or not present pointer type. 

### Main function

Main function is implicitly generated by the compiler and it's job is to initialize modules and execute entry function of the current module.

This means that pt module does not contain any main function, but it works with the global scope as this function, but beware that all the functions and variables declared here are still global and accessible from other modules.

### Entry function

Entry function - `_entry` - contains all the global scope code (statements that are not declaration).

Entry function is called only for the main module, so if it needs to be executed for imported modules it is needed to call it explicitly.

```cpp
import mod2

mod2::_entry()
```

Module could possibly call its own entry function.

### Casting (`as` operator)

Casting can be done only to non-maybe type, unless the casted value is of type `any`. The reason for this is that maybe is dynamically allocated memory and casting (reading) this memory as different type (size) does not make sense. For `any`, this cast only reads the value.
```c
void foo(string? c) {
    c = "changed"
}

int? a = 4
foo(a as string?) // Error
// This does not make sense as a would be
// modified to contain string

string? str_a
str_a = a as string
foo(str_a) // Works
```

If you really wish to play god and treat memory as different type, you can utilize the `any` type for this:
```c
any ivalue = 1
float? fvalue
fvalue = ivalue as float?
```

## Standard library
Calls to standard library do not require any module name prefix and any of the functions can be overridden by custom definitions.

### String function
* __`length`__ - String length.
    * `int length(string s)` - Returns the length of the string `s`.
* __`to_string`__ - Conversion of types to string. This is used by the `as` operator.
    * `string to_string(int i)` - Converts int `i` to string.
    * `string to_string(float f)` - Converts float `f` to string.
    * `string to_string(bool b)` - Converts bool `b` to string.
* __`mto_string`__ - Conversion of maybe types to string (for `none` will return "none"). This is used by the `as` operator.
    * `string to_string(int? i)` - Converts maybe int `i` to string.
    * `string to_string(float? f)` - Converts maybe float `f` to string.
    * `string to_string(bool? b)` - Converts maybe bool `b` to string.
    * `string to_string(string? s)` - Converts maybe string `s` to string. This is useful only for printing as `none` will be indistinguishable from string "none".
* __From string__ - Conversion from string to other types. This is used by the `as` operator, but `as` expects valid value (will ignore `none` and crash).
    * `int? to_int(string str)` - Converts string number in base 10 and returns it as int or none if it is not an integer.
    * `int? to_int_base(string str, int base)` - Converts string number in base `base` and returns it as int or none if it is not an integer in given base.
    * `float? to_float(string str)` - Converts string float and returns it a float or none if it is not a float.
* __`find`__ - Find substring.
    * `int find(string s1, string s2)` - Returns first index of substring `s2` in string `s1` or -1 if not found.
* __`contains`__ - Check if string contains substring (equivalent to `s2 in s1`).
    * `bool contains(string s1, string s2)` - Returns true if string `s1` contains string s2, false otherwise.
* __`reverse`__ - String in reverse.
    * `string reverse(string s)` - Returns copy of string `s` reversed.
* __`slice`__ - Slices a string (equivalent to `s[start, next..end]`). Range can be also descending for reversed string.
    * `string slice(string s, int start, int end) ` - Slices string from index `start`, with step 1 or -1 until index `end`.
    * `string slice(string s, int start, int next, int end) ` - Slices string from index `start`, with step `next - start` until index `end`.
* __Case conversion__ - Conversion to uppercase.
    * `string upper(string s)` - Returns copy of string `s` in uppercase.
    * `string lower(string s)` - Returns copy of string `s` in lowercase.
* __`ord`__ - Converts letter of string to its integer value.
    * `int ord(string s)` - Converts first letter of `s` to its integer value.
* __`chr`__ - Converts integer value to corresponding letter.
    * `string chr(int i)` - Converts integer `i` into corresponding letter and returns it as a string.

### Array functions
These functions are templated for any array (matrix) type, the type `T` stands for this general array type. Type `TBase` stands for the base type of `T` (e.g.: `T` might be `int[][]` and then `TBase` would be `int[]`). Type `TElem` is the base non-array type of `T` (e.g.: `T` might be `int[][]` and then `TElem` would be `int`).

* __`append`__ - Append to an array.
    * `void append(T a, TBase v)` - Append `v` at the end of array `a`.
    * `void mappend(T a, TBase? v)` - Append _maybe_ value `v` into array `a`.
* __`insert`__ - Insert to an array.
    * `void insert(T a, TBase v, int index)` - Insert `v` at index `index` (from 0 to `length(a)`) into array `a`.
    * `void minsert(T a, TBase? v, int index)` - Insert _maybe_ value `v` at index `index` (from 0 to `length(a)`) into array `a`.
* __`remove`__ - Remove value from an array.
    * `void remove(T a, int index)` - Removes value of the array `a` at index `index`.
* __`length`__ - Array length.
    * `int length(T a)` - Returns the length of the array `a`. 
* __`equals`__ - Array equality (equivalent to `a1 == a2`)
    * `bool equals(T a1, T a2)` - Returns true if all value in `a1` are equal to those in `a2`.
* __`find`__ - Find value in an array.
    * `int find(T a, TElem e)` - Returns index of value `e` in array `a` or -1 if it does not exist there.
* __`contains`__ - Check if value is present in an array (equivalent to `e in a`)
    * `bool contains(T a, TElem e)` - Returns true if value `e` is in array `a`, false otherwise.
* __`reverse`__ - Array in reverse.
    * `T reverse(T a)` - Returns copy of array `a` reversed.
* __`slice`__ - Slices an array (equivalent to `a[start, next..end]`). Range can be also descending for reversed array.
    * `T slice(T a, int start, int end) ` - Slices array from index `start`, with step 1 or -1 until index `end`.
    * `T slice(T a, int start, int next, int end) ` - Slices array from index `start`, with step `next - start` until index `end`.
* __`sort`__ - Sorts an array.
    * `void sort(T a, bool(TElem, TElem) cmp)` - Sorts array `a` using comparison function `cmp`.

### Struct function
These functions are templated and type `S` represent generic struct type in this case.
* __`equals`__ - Struct equality (equivalent to `s1 == s2`)
    * `bool equals(S s1, S s2)` - Returns true if values of all elements in `s1` are equal to those in `s2`.

### Math functions
* __Math constants__
    * `M_PI` - Ludolph's number.
    * `M_E`  - Euler's number.
    * `M_PHI` - Golden ratio (`(1 + 5^0.5)/2`).
    * `M_EGAMMA` - Euler–Mascheroni constant.
* __Trigonometric functions__
    * `float sin(float x)` - Sine of `x`.
    * `float cos(float x)` - Cosine of `x`.
    * `float tan(float x)` - Tangent of `x`.
* __`abs`__ - Absolute value.
    * `int abs(int x)`
    * `float abs(float x)`
* __`sum`__ - Sum of all values in an array
    * `int sum(int[] arr)`
    * `float sum(float[] arr)`
* __`int gcd(int a, int b)`__ - Greatest common divisor of `a` and `b`.
* __`int lcm(int a, int b)`__ - Least common multiple of `a` and `b`.
* __Logarithm__ - Computes logarithm.
    * `float ln(float x)` - Natural (base e) logarithm of `x`.
    * `float log10(float x)` - Common (base 10) logarithm of `x`.

### Environment functions
* __`int system(string cmd)`__ - Calls host environment command processor with `cmd`. Return value is implementation-defined value.
* __`string getenv(string name)`__ - Return value of environemnt variable.
* __`bool setenv(string name, string value, bool overwrite)`__ - Sets environment variable to passed in value.
* __Pseudo-random number generation__ - Functions for pseudo random number generation. Seed is initialized implicitly.
    * `void set_seed(int)` - Sets seed for generator.
    * `int rand_int(int min, int max)` - Random integer number between `min` and `max` (including).
    * `float rand_float(float min, float max)` - Random float number between `min` and `max` (including).
    * `float rand_float()` - Random float between 0.0 and 1.0 (including).
    * `bool rand_bool()` - Random boolean.
    * `int rand_uint()` - Returns random unsigned integer.
* __`int timestamp()`__ - Current time since epoch (timestamp).

### IO functions
IO works with built-in structure `File`.
* __`File open(string path, string mode)`__ - Opens a file and returns File structure handle. `path` is the relative or absolute path to the file and mode is one of: `"r"` (read), `"w"` (write), `"a"` (append), `"r+"` (read/update), `"w+"` (write/update), `"a+"` (append/update). For binary files suffix the mode with `b` (`"rb"`). On failure File.handle will be 0.
* __`bool close(File f)`__ - Closes opened file. On succeess returns true, false otherwise.
* __Reading whole input__
    * `string read(File f)` - Reads the whole file `f` and returns it as a string.
* __Reading one character__
    * `string getc(File f)` - Reads one character from a file and returns it as a string (the string is empty if `EOF` is reached).
    * `string getc()` - Reads one character from stdin and returns it as a string (the string is empty if `EOF` is reached).
* __Input__
    * `string input()` - Reads one line from stdin.
    * `string input(string prompt)` - Prints out `prompt` and then reads input from stdin.
* __Reading command line arguments__
    * `string[] args` - _This is a global variable, not a function_. It contains all the command line arguments passed to the program.

# Proto-typed compiler
Proto-typed compiler (ptc) uses LLVM and can target any of big amount of targets LLVM can compile for. The ptc also relies on LibC. 

## Known issues

If you encounter any issues not mentioned here, you can report it in GitHub [issues](https://github.com/mark-sed/proto-typed/issues) section.

### Global array initialization in declaration
Because of some types requiring initialization, only non-initialized types can be assigned to a global variable in its declaration, but a workaround is to assign it after the declaration:
```c
int a = 4
int[] arr_wrong = [a, a+1, a+2] // Won't currently work

int[] arr_corr
arr_corr = [a, a+1, a+2] // Will work
```