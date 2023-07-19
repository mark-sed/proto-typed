# Proto-typed language

* Statically typed
* Type inference
* Modules (imports)
* Constants
* Optional semicolons (for one-liners)
* No main
* Arithmetics over matrices

## Types

### Int
```
int a = 42
```

### Float
```
float a = 42e-8
float b = 0.42
```

### Bool
```
bool a = true;
bool b = false;
```

### String
```
string a = "Hello" 
```

#### FString
```
string who = "World"
string fa = f"Hello, {who}!"
```
  
#### RString
```
string a = r"\n\n Still one line \t\n"
```

### Matrix (1D-nD)
```
int[4, 3] m = [[1, 1, 0, 1], 
              [1, 1, 1, 0],
              [1, 1, 1, 1]]
float[] n = [0.0, 1.0]
string[4] s = ["hello", ", ", "world", "!"]

int[WIDTH, HEIGHT] screen
screen[x][y] = 1

int[] subm = m[:1][1:2] // [[1, 0],[1, 1]]
```

When the size of the matrix is used in the type, then
the matrix cannot be appended to or removed from
(it has static size).

When `[]` is used then its a dynamic matrix.

Matrix is also a product of slicing:
```
a[1:300:2];
```
And a product of a range:
```
for(a : (1..100)) {}

a = (1,3 .. 500)
```

### Struct
```
struct MyData {
    int x
    int y
    string name
}

MyData md = {.x = 42, .name = "md"}
print(md.name, md.x)

struct MD {
    int x = 4
}

MD md2
print(md2.x)
```

### Maybe types
```
int? b1 = 4
int? b2 = none

int? f() {
    return none
}
```

## Syntax

### Comments
```
// Single line comment

/* Multi
   line
   comment */
```

### Functions
```
int foo(int x) {
    return x*42
}

void bar(int[4] a) {
    a *= [42, 42, 42, 42]
}

void baz(int[] a, int v=42) {
    a *= matrix([len(a)], v)
}

print(foo(1))
bar(m1)
baz(a, v=0)

int(int[4], int) fbaz = baz

int(bool) getf(string name) {
    return funcs[name];
}

int(bool)(string) fgetf = getf
```

### Ifs
```
if(x < 42) {
    print("big")
} else {
    print("small")
}

if (a in [1,4,8]) print("a") elif(a > 100) print("b") else print("c")
```

### Foreach loop
```
for(i : [1..x]) {

}

for(i : a) print(i)
```

### Constants
```
const a = "Hello"
const b = true
```

### While/Do loop
```
while(a) {

}

do {

}while(a)

do print(".") while(a)
```

### Modules
```
import Module1, Module2

int b = Module1::foo(42)
```

## Examples

__Mathematical expression__:
```
var a = 42.5 # Double
int b = 8

print(a + b)
```
