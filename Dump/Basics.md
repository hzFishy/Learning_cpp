
# Compile & Execute
## Compile:
```bash
g++ filename.cpp -o filenametoexecute
```

## Execute:
`./filenametoexecute` or `filenametoexecute.exe`

# Libs
```cpp
#include <iostream>
```
For inputs & outputs
```cpp
#include <vector>
```
For using vectors (list)

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
`<`, `>`, `<=`, `>=`, `==`, and `!=`

## Logical operators
`&&`: the and logical operator
`||`: the or logical operator
`!`: the not logical operator

# Loops
## While loop
```cpp
while (condition){
 //code
}
```
## For loop
```cpp
for (int i = 0; i < 20; i++){
 //code
}
```
`int i = 0` >> The initialization of a counter
`i < 20` >> The continue condition
`i++` >> The change in the counter


# Vectors
*Needs the vector lib*
## Declaring, initializing & presizing
> Format for declaring a vector
```cpp
std::vector<type> name;
```

> Format for declaring & initializing a vector
```cpp
std::vector<type> name = {e1, e2, ...};
 ```

> Fromat for presizing
 ```cpp
std::vector<type> name(size);
 ```
> *when presizing the vector is populated with the defaults values of the `type` (e.g: for doubles 0.0)*

## Indexs
```cpp
std::cout << name[index]
```

## Adding & Removing Elements
> Adding at the end
```cpp
name.push_back(data);
```
> Removing at the end
```cpp
name.pop_back();
```
## Size
```cpp
name.size();
```

# Functions
```cpp
return_type function_name( parameters) {
   // Code block here
   return output_if_there_is_any;
 
}
```
> `type` : `int`, `float`, `char`, ...) or custom type (class, structure) or  `void` if no return
