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
int[4, 2] m = [[1, 1, 0, 1], 
              [1, 1, 1, 0]]
float[] n = [0.0, 1.0]
string[4] = ["hello", ", ", "world", "!"]

int[WIDTH, HEIGHT] screen
screen[x][y] = 1
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
import Module1
import Module2 as m2
from Module3 import MyStruct, foo
```

## Examples

__Mathematical expression__:
```
var a = 42.5 # Double
int b = 8

print(a + b)
```

## Qs
* Add pointer? Since int[1] is a pointer and dereference is with a[0]
