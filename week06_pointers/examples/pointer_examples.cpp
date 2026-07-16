#include <iostream>
#include <cstring>

// ============================================
// 1. BASIC POINTER OPERATIONS
// ============================================

void basicPointers() {
    std::cout << "=== Basic Pointers ===\n";

    int x = 42;
    double y = 3.14;
    char c = 'A';

    int* ptrX = &x;
    double* ptrY = &y;
    char* ptrC = &c;

    std::cout << "x  value: " << x  << ", address: " << &x  << ", via ptr: " << *ptrX << "\n";
    std::cout << "y  value: " << y  << ", address: " << &y  << ", via ptr: " << *ptrY << "\n";
    std::cout << "c  value: " << c  << ", address: " << (void*)&c << ", via ptr: " << *ptrC << "\n";

    // Modify via pointer
    *ptrX = 100;
    std::cout << "After *ptrX = 100, x = " << x << std::endl;
}

// ============================================
// 2. POINTER SIZE & ARITHMETIC
// ============================================

void pointerArithmetic() {
    std::cout << "\n=== Pointer Arithmetic ===\n";

    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr; // Points to arr[0]

    std::cout << "sizeof(int) = " << sizeof(int) << " bytes\n";
    std::cout << "arr[0] at " << ptr << ", value = " << *ptr << std::endl;

    ptr++; // Moves 4 bytes forward (sizeof(int))
    std::cout << "After ptr++: " << ptr << ", value = " << *ptr << std::endl;

    ptr += 2; // Moves 8 bytes (2 * 4)
    std::cout << "After ptr+=2: " << ptr << ", value = " << *ptr << std::endl;

    // Array indexing is pointer arithmetic!
    std::cout << "arr[2] = " << arr[2] << " = *(arr + 2) = " << *(arr + 2) << std::endl;
    std::cout << "2[arr] = " << 2[arr] << " (yes, this works!)\n";
}

// ============================================
// 3. NULL POINTERS
// ============================================

void nullPointerDemo() {
    std::cout << "\n=== Null Pointers ===\n";

    int* ptr = nullptr;

    if (ptr == nullptr) {
        std::cout << "ptr is null - safe to check before dereferencing\n";
    }

    // This would CRASH:
    // std::cout << *ptr;

    // Allocate then use
    ptr = new int(42);
    if (ptr != nullptr) {
        std::cout << "ptr now points to: " << *ptr << std::endl;
        delete ptr;
        ptr = nullptr;
    }
}

// ============================================
// 4. CONST POINTERS
// ============================================

void constPointers() {
    std::cout << "\n=== const Pointers ===\n";

    int x = 10, y = 20;

    const int* p1 = &x;  // Can't change value via p1
    // *p1 = 30;  // ERROR!
    p1 = &y;             // But can change where p1 points
    std::cout << "const int*: can change address, can't change value\n";

    int* const p2 = &x;  // Can't change address
    *p2 = 30;            // But can change value
    // p2 = &y;  // ERROR!
    std::cout << "int* const: can change value, can't change address\n";
}

// ============================================
// 5. REFERENCES
// ============================================

void referenceDemo() {
    std::cout << "\n=== References ===\n";

    int x = 42;
    int& ref = x;  // ref is x

    std::cout << "x = " << x << ", ref = " << ref << std::endl;
    std::cout << "&x = " << &x << ", &ref = " << &ref << " (same!)\n";

    ref = 100;
    std::cout << "After ref = 100, x = " << x << std::endl;

    // References cannot be reassigned
    int y = 50;
    ref = y;  // This sets x = y = 50, ref still REFERS TO x!
    std::cout << "After ref = y, x = " << x << ", y = " << y << std::endl;
}

// ============================================
// 6. POINTERS TO POINTERS
// ============================================

void pointerToPointer() {
    std::cout << "\n=== Pointers to Pointers ===\n";

    int x = 42;
    int* ptr = &x;    // Points to x
    int** pptr = &ptr; // Points to ptr

    std::cout << "x = " << x << std::endl;
    std::cout << "*ptr = " << *ptr << std::endl;
    std::cout << "**pptr = " << **pptr << std::endl;

    **pptr = 99;
    std::cout << "After **pptr = 99, x = " << x << std::endl;
}

// ============================================
// 7. DYNAMIC MEMORY
// ============================================

void dynamicMemory() {
    std::cout << "\n=== Dynamic Memory ===\n";

    // Single allocation
    int* p = new int(10);
    std::cout << "Dynamically allocated int: " << *p << std::endl;
    delete p;

    // Array allocation
    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;

    int* arr = new int[size];

    std::cout << "Enter " << size << " values: ";
    for (int i = 0; i < size; i++)
        std::cin >> arr[i];

    int sum = 0;
    std::cout << "You entered: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
        sum += arr[i];
    }
    std::cout << "\nSum: " << sum << std::endl;

    delete[] arr;  // MUST use delete[] for arrays
    arr = nullptr;
}

// ============================================
// 8. FUNCTION POINTERS
// ============================================

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

void functionPointers() {
    std::cout << "\n=== Function Pointers ===\n";

    // Declare a function pointer
    int (*operation)(int, int);

    operation = add;
    std::cout << "add(5, 3) = " << operation(5, 3) << std::endl;

    operation = subtract;
    std::cout << "subtract(5, 3) = " << operation(5, 3) << std::endl;

    operation = multiply;
    std::cout << "multiply(5, 3) = " << operation(5, 3) << std::endl;
}

// ============================================
// 9. PASSING TO FUNCTIONS
// ============================================

void passByPointer(int* p) {
    *p = 20;
}

void passByReference(int& r) {
    r = 30;
}

void passingDemo() {
    std::cout << "\n=== Passing to Functions ===\n";
    int x = 10;

    passByPointer(&x);
    std::cout << "After passByPointer: x = " << x << std::endl;

    passByReference(x);
    std::cout << "After passByReference: x = " << x << std::endl;
}

// ============================================
// MAIN
// ============================================

int main() {
    basicPointers();
    pointerArithmetic();
    nullPointerDemo();
    constPointers();
    referenceDemo();
    pointerToPointer();
    dynamicMemory();
    functionPointers();
    passingDemo();

    return 0;
}