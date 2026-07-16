# Week 3: Functions

Functions allow you to break code into reusable, testable pieces. In C++, you must declare the return type and parameter types.

## 1. Function Syntax
```cpp
returnType functionName(parameterType paramName) {
    // body
    return value; // Required if returnType is not void
}
```

## 2. Parameter Passing

### Pass by Value (Default)
Creates a **copy**. Original unchanged.
```cpp
void modify(int x) {
    x = 20; // Changes local copy only
}

int main() {
    int a = 10;
    modify(a);
    // a is still 10
}
```

### Pass by Reference (`&`)
Operates on the **original** variable.
```cpp
void modify(int &x) {
    x = 20; // Changes the actual variable
}

int main() {
    int a = 10;
    modify(a);
    // a is now 20
}
```

### Pass by Pointer (`*`)
Pass memory address. Original modifiable.
```cpp
void modify(int *x) {
    *x = 20; // Dereference to change value
}

int main() {
    int a = 10;
    modify(&a); // Pass address
    // a is now 20
}
```

## 3. Function Overloading
Same name, different parameters (signature).
```cpp
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
int add(int a, int b, int c) { return a + b + c; }
```

## 4. Default Parameters
```cpp
void greet(std::string name, std::string prefix = "Hello") {
    std::cout << prefix << ", " << name << std::endl;
}

greet("Alice");        // "Hello, Alice"
greet("Bob", "Hi");    // "Hi, Bob"
```

## 5. Function Prototypes (Declarations)
Place before `main()`, define after. Standard practice.
```cpp
// Prototype
double calculateArea(double radius);

int main() { ... }

// Definition
double calculateArea(double radius) {
    return 3.14159 * radius * radius;
}
```

## 6. Scope Rules
- **Local**: Inside function/block. Dies when block ends.
- **Global**: Outside all functions. Accessible everywhere (avoid!).
- **Static Local**: Retains value between calls.

---
## Exercises

1. **Math Library**: Create functions: `max(a,b)`, `min(a,b)`, `power(base,exp)`, `factorial(n)`, `isPrime(n)`.
2. **Swap Function**: Write `void swap(int &a, int &b)` using references.
3. **Statistics**: Function `void stats(int arr[], int size, double &mean, double &median)`.
4. **Recursion**: Write `factorial(n)` and `fibonacci(n)` recursively.
5. **Menu System**: Refactor Week 2 calculator into separate functions for each operation.