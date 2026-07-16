#include <iostream>
#include <cmath>

// ============================================
// 1. BASIC FUNCTIONS
// ============================================

// Function prototype (declaration)
int add(int a, int b);
double circleArea(double radius);
void printLine(char c, int length);

// Function with default parameter
void greet(std::string name, std::string greeting = "Hello") {
    std::cout << greeting << ", " << name << "!" << std::endl;
}

// ============================================
// 2. PASS BY VALUE vs REFERENCE vs POINTER
// ============================================

void passByValue(int x) {
    x = 20;
    std::cout << "Inside passByValue: x = " << x << std::endl;
}

void passByReference(int &x) {
    x = 20;
    std::cout << "Inside passByReference: x = " << x << std::endl;
}

void passByPointer(int *x) {
    *x = 20;
    std::cout << "Inside passByPointer: *x = " << *x << std::endl;
}

// ============================================
// 3. FUNCTION OVERLOADING
// ============================================

int multiply(int a, int b) {
    return a * b;
}

double multiply(double a, double b) {
    return a * b;
}

int multiply(int a, int b, int c) {
    return a * b * c;
}

// ============================================
// 4. ARRAYS AS PARAMETERS
// ============================================

// Arrays decay to pointers - size must be passed separately
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void modifyArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2; // Modifies original!
    }
}

double findAverage(int arr[], int size) {
    if (size == 0) return 0;
    int sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return static_cast<double>(sum) / size;
}

// ============================================
// 5. RETURNING MULTIPLE VALUES (via reference)
// ============================================

void minMax(int arr[], int size, int &minVal, int &maxVal) {
    minVal = maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }
}

// ============================================
// 6. RECURSION
// ============================================

int factorial(int n) {
    if (n <= 1) return 1; // Base case
    return n * factorial(n - 1); // Recursive case
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Tail recursion (optimizable)
int factorialTail factorialTail(int n, int accumulator = 1) {
    if (n <= 1) return accumulator;
    return factorialTail(n - 1, n * accumulator);
}

// ============================================
// 7. INLINE FUNCTIONS
// ============================================

inline int square(int x) {
    return x * x;
}

// ============================================
// MAIN - DEMONSTRATION
// ============================================

int main() {
    std::cout << "=== 1. Basic Functions ===" << std::endl;
    std::cout << "add(5, 3) = " << add(5, 3) << std::endl;
    std::cout << "circleArea(2.0) = " << circleArea(2.0) << std::endl;
    printLine('=', 30);
    greet("Alice");
    greet("Bob", "Hi");

    std::cout << "\n=== 2. Parameter Passing ===" << std::endl;
    int val = 10;
    std::cout << "Original: " << val << std::endl;
    passByValue(val);
    std::cout << "After passByValue: " << val << std::endl;

    val = 10;
    passByReference(val);
    std::cout << "After passByReference: " << val << std::endl;

    val = 10;
    passByPointer(&val);
    std::cout << "After passByPointer: " << val << std::endl;

    std::cout << "\n=== 3. Function Overloading ===" << std::endl;
    std::cout << "multiply(3, 4) = " << multiply(3, 4) << std::endl;
    std::cout << "multiply(2.5, 4.0) = " << multiply(2.5, 4.0) << std::endl;
    std::cout << "multiply(2, 3, 4) = " << multiply(2, 3, 4) << std::endl;

    std::cout << "\n=== 4. Arrays as Parameters ===" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    int size = 5;

    std::cout << "Original: ";
    printArray(numbers, size);

    std::cout << "Average: " << findAverage(numbers, size) << std::endl;

    modifyArray(numbers, size);
    std::cout << "After modify (x2): ";
    printArray(numbers, size);

    std::cout << "\n=== 5. Multiple Return Values ===" << std::endl;
    int minV, maxV;
    minMax(numbers, size, minV, maxV);
    std::cout << "Min: " << minV << ", Max: " << maxV << std::endl;

    std::cout << "\n=== 6. Recursion ===" << std::endl;
    std::cout << "factorial(5) = " << factorial(5) << std::endl;
    std::cout << "fibonacci(10) = " << fibonacci(10) << std::endl;
    std::cout << "factorialTail(5) = " << factorialTail(5) << std::endl;

    std::cout << "\n=== 7. Inline Function ===" << std::endl;
    std::cout << "square(9) = " << square(9) << std::endl;

    return 0;
}

// ============================================
// FUNCTION DEFINITIONS (after main)
// ============================================

int add(int a, int b) {
    return a + b;
}

double circleArea(double radius) {
    const double PI = 3.14159265359;
    return PI * radius * radius;
}

void printLine(char c, int length) {
    for (int i = 0; i < length; i++) std::cout << c;
    std::cout << std::endl;
}