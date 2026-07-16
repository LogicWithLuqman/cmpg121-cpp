# Week 7: Advanced Pointers (Pointers + Arrays + Functions)

This week combines everything: pointers, arrays, and functions into more complex patterns.

## 1. Array Name as Pointer

The name of an array IS a pointer to the first element:

```cpp
int arr[] = {10, 20, 30, 40};
int* ptr = arr;      // Equivalent to: ptr = &arr[0]

arr[2] == *(arr + 2) // TRUE
2[arr] == *(2 + arr) // TRUE (quirky but valid!)
```

## 2. Pointer Arithmetic with Arrays

```cpp
int arr[] = {10, 20, 30, 40, 50};
int* p = arr;

p++;           // Now points to arr[1]
std::cout << *p;      // 20
std::cout << p[-1];   // 10 (yes, negative index works!)
std::cout << p[2];    // 40 (equivalent to arr[3])
```

## 3. Pointer Difference

```cpp
int arr[] = {10, 20, 30, 40, 50};
int* start = arr;
int* end = &arr[4];

int count = end - start;  // 4 (number of elements between)
ptrdiff_t diff = end - start; // Proper type
```

## 4. Dynamic Multi-Dimensional Arrays

### Array of pointers (jagged arrays):
```cpp
int** matrix = new int*[rows];
for (int i = 0; i < rows; i++)
    matrix[i] = new int[cols];
```

### Contiguous 2D array (single allocation):
```cpp
int* matrix = new int[rows * cols];
// Access: matrix[row * cols + col]
```

## 5. Strings and Pointers

```cpp
char str[] = "Hello";
char* ptr = str;
while (*ptr != '\0') {
    std::cout << *ptr;
    ptr++;
}

// Array of C-strings
const char* words[] = {"Apple", "Banana", "Cherry"};
for (int i = 0; i < 3; i++)
    std::cout << words[i] << " ";
```

## 6. Pointers to Structs

```cpp
struct Student { int id; std::string name; double gpa; };

Student s = {123, "Alice", 3.8};
Student* ptr = &s;

// Arrow operator (->) is shorthand
ptr->id = 456;       // Equivalent to (*ptr).id = 456
std::string n = ptr->name;
```

## 7. Returning Pointers from Functions

```cpp
// WARNING: NEVER return pointer to local variable!
int* badFunction() {
    int x = 10;
    return &x;  // Dangling pointer! x destroyed when function ends
}

// SAFE: Return pointer to dynamic memory
int* goodFunction() {
    int* p = new int(10);
    return p;   // Caller must delete
}

// SAFE: Return pointer to static/global
int* safeFunction() {
    static int x = 10;
    return &x;
}
```

## 8. Function Pointers (Detailed)

```cpp
// Function type: takes two ints, returns int
int (*funcPtr)(int, int);

// Assign
funcPtr = &add; // & is optional: funcPtr = add; also works

// Call
int result = funcPtr(5, 3);  // or (*funcPtr)(5, 3)

// Array of function pointers
int (*operations[])(int, int) = {add, subtract, multiply};
```

## 9. Command Line Arguments

```cpp
int main(int argc, char* argv[]) {
    // argc = argument count (program name counts as 1)
    // argv = array of C-strings
    for (int i = 0; i < argc; i++)
        std::cout << "arg[" << i << "] = " << argv[i] << std::endl;
}
```

---
## Exercises

1. **String Copy using Pointers**: Implement `void stringCopy(char* dest, const char* src)` using pointer arithmetic only (no array indexing).
2. **Dynamic Student Array**: Create array of Student structs dynamically. Sort by GPA using pointer to struct.
3. **Command-Line Calculator**: Read expression from command line: `calc 5 + 3`. Use argv parsing + function pointers for operations.
4. **Matrix Transpose**: Write function to transpose a matrix using pointer notation.
5. **String Tokenizer**: Implement `char** split(const char* str, char delimiter, int& count)` that returns array of tokens.