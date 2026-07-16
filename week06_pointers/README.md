# Week 6: Pointers & References

Pointers are arguably the hardest concept in C++. They give you direct access to memory addresses. Understand this week well — Week 7 builds on it heavily.

## 1. Memory & Addresses

Every variable lives at a memory address:
```cpp
int x = 42;
std::cout << &x;  // Prints address like 0x7ffd5a3b4c
```

## 2. Pointer Basics

A pointer is a variable that **stores a memory address**.

```cpp
int x = 42;
int* ptr = &x;   // ptr stores the ADDRESS of x

std::cout << ptr;   // Address (e.g., 0x7ffd5a3b4c)
std::cout << *ptr;  // Dereference -> value (42)

*ptr = 100;         // Changes x to 100
```

### Pointer Syntax Diagram
```
int* ptr = &x;
^   ^      ^
|   |      Address-of operator (&)
|   Pointer variable name
Type (pointer to int)
```

## 3. The Two Operators

| Operator | Name | Meaning |
|----------|------|---------|
| `&x` | Address-of | Gives the memory address of `x` |
| `*ptr` | Dereference | Gets/sets the value AT the address `ptr` holds |

## 4. Null Pointers

A pointer that points to nothing:
```cpp
int* ptr = nullptr;  // C++11 (preferred)
int* ptr = NULL;     // C-style (still works)
int* ptr = 0;        // Also valid

// ALWAYS check before dereferencing!
if (ptr != nullptr) {
    std::cout << *ptr;  // Safe
}
```

## 5. Pointers and `const`

```cpp
int x = 10, y = 20;
const int* p1 = &x;     // Pointer to CONSTANT int (can't change *p1)
int* const p2 = &x;     // CONSTANT pointer (can't change p2)
const int* const p3 = &x; // Both constant

*p1 = 30;  // ERROR!
p1 = &y;   // OK
p2 = &y;   // ERROR!
*p2 = 30;  // OK
```

## 6. References (Aliases)

A reference is an **alias** for an existing variable. Think of it as a constant pointer that is automatically dereferenced.

```cpp
int x = 42;
int& ref = x;  // ref is an alias for x

ref = 100;     // x is now 100
std::cout << x;  // 100
```

### References vs Pointers

| Feature | Pointer | Reference |
|---------|---------|-----------|
| Can be reassigned | Yes | **No** |
| Can be null | Yes | **No** |
| Must be initialized | No | **Yes** |
| Syntax | `*` to dereference | Implicitly dereferenced |
| Use case | Dynamic memory, optional params | Function parameters, operator overloading |

## 7. Dynamic Memory Allocation (`new` / `delete`)

```cpp
// Single variable
int* p = new int;   // Allocate on heap
*p = 42;
delete p;           // FREE the memory
p = nullptr;        // Good practice

// Array
int* arr = new int[10];
arr[0] = 5;
delete[] arr;       // NOTE: delete[] for arrays
arr = nullptr;
```

### Common Pitfalls
- **Dangling pointer**: Using pointer after `delete`
- **Memory leak**: Not calling `delete`
- **Double delete**: Calling `delete` twice on same pointer
- **Null dereference**: Using `*ptr` when `ptr == nullptr`

---
## Exercises

1. **Pointer Basics**: Declare variables of different types. Print their addresses and values. Modify via pointer.
2. **Swap via Pointers**: `void swap(int* a, int* b)` — swap using pointers.
3. **Dynamic Array**: Ask user for size. Allocate array dynamically. Fill with user input. Print and sum. Delete.
4. **Find Max via Pointer**: Function `int* findMax(int* arr, int size)` returns pointer to largest element.
5. **Reference vs Pointer**: Write two functions that increment a variable — one via pointer, one via reference. Show both work.