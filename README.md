# Proto-typed Project

Proto-typed (pt) is a compiled statically typed language with garbage collection and modern syntax.

As the name suggests, proto-typed was designed for writing prototypes and short simple programs in a compiled and typed manner.

This repository contains Proto-typed Compiler (ptc) and the language definition in textual form.

#### Table of contents
- [Proto-typed Project](#proto-typed-project)
- [Proto-typed Programming Language](#proto-typed-programming-language)
- [Proto-typed Compiler](#proto-typed-compiler)

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

### Struct

### Array (matrix)

### Maybe

### Any

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
if(a)
    print("Hi")   // Syntax error

else print("Bye") // Syntax error

if(a) print("Hi") // Correct
else print("Bye") // Correct
```

Also keep in mind that the statement following if has to be terminated as well, either by a new line or a semicolon and therefore when writing a one-line if-else, one must use semicolon (or `{}`) after each statement:

```c
if(a) print("Hi") else print("Bye")  // Syntax error
if(a) print("Hi"); else print("Bye") // Correct
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
for(float i : values) {
    print(i++"\n")
}

string text = "Some text"
for(string letter: text) {
    print(letter++" ")
}
```

Proto-typed also offers special type `range` (see more bellow), which can be used counted for loops:
```c
for(int i : 0..5) {
    print(i++" ") // 0 1 2 3 4
}

for(int j : 0,2..5) {
    print(j++" ") // 0 2 4
}

string text = "Some more text"
for(int k : 0..length(text)) {
    print(k++": "++text[k]++"\n")
}
```

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

# Proto-typed Compiler
