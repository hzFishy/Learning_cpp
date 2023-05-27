
# Compile & Execute
## Compile:
g++ filename.cpp -o filenametoexecute

## Execute:
`./filenametoexecute` or `filenametoexecute.exe`

# Libs
```cpp
#include <iostream>
```
For inputs & outputs

# Inputs and Outputs (from "iostream")
## Output
### Single
```cpp
std::cout << data << "\n";
```
### Concatenation
```cpp
int age = 28;
 
std::cout << "Hello, I am ";
std::cout << age;
std::cout << " years old\n";
```
> Output: `Hello, I am 28 years old`
or
```cpp
int age = 28;
 
std::cout << "Hello, I am " << age << " years old\n";
```
> Output: `Hello, I am 28 years old`

## Input
```cpp
std::cin >> data;
```

# Variables:
> Every variable in C++ must be declared before it can be used!

![](https://img001.prntscr.com/file/img001/blWsh3h6R4u7uI2Q_Jq_Mw.png)

Synthax:
```cpp
// Declare
int score;
// Init
score = 0;
```
Or
```cpp
int score = 0;
```

# Functions
```cpp
type name(type input) {
    // ...
    return ...;
}
```
// `type` : `int`, `float`, `char`, etc.), type personnalisé (une classe, une structure) ou  `void` si no return


# Conditionals & Logic
## If, else if, and else statements
```cpp
if (condition) {

  //do something

} else {

  //do something else

}
```

## Switch
> must evaluate to an integral type (int, char, short, long, long long, or enum).

```cpp
switch (data) {
 
  case ?:
    // code
    break;
  case ??:
    // code
    break;
  default:
    // code
    break;
 
}
```

## Relational operators

## Logical operators
`&&`: the and logical operator
`||`: the or logical operator
`!`: the not logical operator
