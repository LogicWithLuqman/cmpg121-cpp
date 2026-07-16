# Week 1: Transition from Python to C++

Welcome to your first week of C++! In Python, things happen "magically" in the background. In C++, you are closer to the machine. You must be explicit about everything.

## Key Differences: Python vs. C++

| Feature | Python | C++ |
|--------|-------|-----|
| **Type System** | Dynamic (no need to declare types) | Static (MUST declare types) |
| **Execution** | Interpreted | Compiled (Code -> Binary) |
| **Syntax** | Indentation based | Braces `{}` and Semicolons `;` |
| **Memory** | Automatic management | Manual management (Pointers) |
| **Speed** | Slower | Extremely Fast |

## Core Concept: The "Boilerplate"

Every C++ program needs a `main` function. This is the entry point.

```cpp
#include <iostream> // Preprocessor directive to include Input/Output library

int main() { // The entry point of the program
    std::cout << "Hello World!" << std::endl; // Print to console
    return 0; // Success!
}
```

## Data Types Reference

| Type | Description | Example |
|------|-------------|---------|
| `int` | Integers (whole numbers) | `int age = 20;` |
| `double` | Floating point (decimals) | `double price = 19.99;` |
| `char` | Single character | `char grade = 'A';` |
| `bool` | Boolean (true/false) | `bool isCoding = true;` |
| `std::string` | Text | `std::string name = "NWU";` |

---
## Exercises

1. **The Greeting**: Write a program that asks for a user's name and age, then prints: "Hello [name], you are [age] years old."
2. **The Calculator**: Create a program that takes two `double` numbers and prints their sum, difference, product, and quotient.
3. **Type Explorer**: Create variables for every data type mentioned above, assign them values, and print them all.
