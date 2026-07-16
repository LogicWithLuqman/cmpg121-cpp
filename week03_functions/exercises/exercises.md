# Week 3 Exercises: Functions

## Exercise 1: Math Utility Library
Create a header file `math_utils.h` and implementation `math_utils.cpp` with:
- `int max(int a, int b)` - returns larger
- `int min(int a, int b)` - returns smaller
- `int power(int base, int exp)` - base^exp (exp >= 0)
- `long long factorial(int n)` - n! (handle 0! = 1)
- `bool isPrime(int n)` - true if prime
- `int gcd(int a, int b)` - Greatest Common Divisor (Euclidean algorithm)

**Test**: Write a `main.cpp` that tests all functions.

---

## Exercise 2: Swap Variations
Implement three swap functions:
```cpp
void swapByValue(int a, int b);        // Won't actually swap
void swapByReference(int &a, int &b);  // Will swap
void swapByPointer(int *a, int *b);    // Will swap
```
Test all three and explain why the first doesn't work.

---

## Exercise 3: Array Statistics
Write a function:
```cpp
void arrayStats(int arr[], int size, 
                double &mean, double &median, int &mode);
```
- **Mean**: Average
- **Median**: Middle value (sort first!)
- **Mode**: Most frequent value

Handle even-sized arrays for median (average of two middle).

---

## Exercise 4: Recursive Functions
Implement recursively:
1. `int sumToN(int n)` - Sum 1 to n (e.g., sumToN(5) = 15)
2. `int countDigits(int n)` - Count digits in number
3. `void printBinary(int n)` - Print binary representation
4. `bool isPalindrome(string str, int start, int end)` - Check palindrome

---

## Exercise 5: Calculator Refactor
Refactor your Week 2 calculator into functions:
```cpp
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b); // Handle divide by zero!
int modulo(int a, int b);

void showMenu();
double getNumber(string prompt);
```

Main loop calls these functions.

---

## Exercise 6: Function Overloading Practice
Create overloaded `print()` functions:
- `print(int n)` - prints "Integer: n"
- `print(double d)` - prints "Double: d"
- `print(string s)` - prints "String: s"
- `print(int arr[], int size)` - prints array elements
- `print(vector<int> v)` - prints vector elements

---

## Exercise 7: Default Parameters
Write a function:
```cpp
void drawBox(int width, int height, char border = '*', char fill = ' ');
```
Examples:
- `drawBox(5, 3)` → 5x3 box with * border, space fill
- `drawBox(4, 2, '#')` → 4x2 box with # border, space fill
- `drawBox(6, 4, '@', '.')` → 6x4 box with @ border, . fill

---

## Exercise 8: Scope & Static Variables
Write a function `int counter()` that:
- Uses a `static int count = 0` inside the function
- Increments and returns count each call
- Call it 5 times in main and print results

Explain: What happens if `static` is removed?

---

## Solutions

### Exercise 1 Solution (math_utils.h)
```cpp
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

int max(int a, int b);
int min(int a, int b);
int power(int base, int exp);
long long factorial(int n);
bool isPrime(int n);
int gcd(int a, int b);

#endif
```

### Exercise 1 Solution (math_utils.cpp)
```cpp
#include "math_utils.h"

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) result *= base;
    return result;
}

long long factorial(int n) {
    if (n < 0) return -1;
    long long result = 1;
    for (int i = 2; i <= n; i++) result *= i;
    return result;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```

### Exercise 2 Solution
```cpp
#include <iostream>

void swapByValue(int a, int b) {
    int temp = a; a = b; b = temp; // Swaps copies
}

void swapByReference(int &a, int &b) {
    int temp = a; a = b; b = temp; // Swaps originals
}

void swapByPointer(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp; // Swaps via addresses
}

int main() {
    int x = 5, y = 10;
    swapByValue(x, y);
    std::cout << "By Value: " << x << ", " << y << std::endl; // 5, 10

    swapByReference(x, y);
    std::cout << "By Reference: " << x << ", " << y << std::endl; // 10, 5

    swapByPointer(&x, &y);
    std::cout << "By Pointer: " << x << ", " << y << std::endl; // 5, 10
}
```

### Exercise 3 Solution
```cpp
#include <iostream>
#include <algorithm>
#include <map>

void arrayStats(int arr[], int size, double &mean, double &median, int &mode) {
    // Mean
    int sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    mean = static_cast<double>(sum) / size;

    // Copy and sort for median/mode
    int *sorted = new int[size];
    std::copy(arr, arr + size, sorted);
    std::sort(sorted, sorted + size);

    // Median
    if (size % 2 == 0) {
        median = (sorted[size/2 - 1] + sorted[size/2]) / 2.0;
    } else {
        median = sorted[size/2];
    }

    // Mode (frequency map)
    std::map<int, int> freq;
    for (int i = 0; i < size; i++) freq[sorted[i]]++;
    
    int maxFreq = 0;
    mode = sorted[0];
    for (auto &p : freq) {
        if (p.second > maxFreq) {
            maxFreq = p.second;
            mode = p.first;
        }
    }
    delete[] sorted;
}
```

### Exercise 4 Solutions
```cpp
// 1. Sum 1 to n
int sumToN(int n) {
    if (n <= 1) return n;
    return n + sumToN(n - 1);
}

// 2. Count digits
int countDigits(int n) {
    if (n < 10) return 1;
    return 1 + countDigits(n / 10);
}

// 3. Print binary
void printBinary(int n) {
    if (n > 1) printBinary(n / 2);
    std::cout << n % 2;
}

// 4. Palindrome
bool isPalindrome(std::string str, int start, int end) {
    if (start >= end) return true;
    if (str[start] != str[end]) return false;
    return isPalindrome(str, start + 1, end - 1);
}
```

### Exercise 7 Solution
```cpp
void drawBox(int width, int height, char border, char fill) {
    // Top border
    for (int i = 0; i < width; i++) std::cout << border;
    std::cout << std::endl;

    // Middle rows
    for (int row = 1; row < height - 1; row++) {
        std::cout << border;
        for (int col = 1; col < width - 1; col++) std::cout << fill;
        std::cout << border << std::endl;
    }

    // Bottom border (if height > 1)
    if (height > 1) {
        for (int i = 0; i < width; i++) std::cout << border;
        std::cout << std::endl;
    }
}
```

### Exercise 8 Solution
```cpp
int counter() {
    static int count = 0; // Initialized ONCE
    count++;
    return count;
}

// Without static: count resets to 0 every call, always returns 1
```