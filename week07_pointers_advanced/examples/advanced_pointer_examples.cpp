#include <iostream>
#include <cstring>

// ============================================
// 1. ARRAYS AND POINTER ARITHMETIC
// ============================================

void arrayPointerEquivalence() {
    std::cout << "=== Array-Pointer Equivalence ===\n";

    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr;

    std::cout << "arr[0] = " << arr[0]
              << ", *arr = " << *arr
              << ", *ptr = " << *ptr << std::endl;

    std::cout << "arr[2] = " << arr[2]
              << ", *(arr+2) = " << *(arr + 2)
              << ", *(ptr+2) = " << *(ptr + 2)
              << ", 2[arr] = " << 2[arr] << std::endl;

    // Traverse with pointer
    std::cout << "Traversing with pointer: ";
    for (int* p = arr; p < arr + 5; p++)
        std::cout << *p << " ";
    std::cout << std::endl;
}

// ============================================
// 2. POINTERS TO STRUCTS
// ============================================

struct Student {
    int id;
    char name[50];
    double marks[4];
    double average;
};

double calcAvg(double* marks, int count) {
    double sum = 0;
    for (int i = 0; i < count; i++)
        sum += *(marks + i); // Pointer notation
    return sum / count;
}

void initStudent(Student* s, int id, const char* name) {
    s->id = id;
    strcpy(s->name, name);
    for (int i = 0; i < 4; i++)
        s->marks[i] = 0.0;
    s->average = 0.0;
}

void printStudent(const Student* s) {
    std::cout << "ID: " << s->id
              << ", Name: " << s->name
              << ", Avg: " << s->average << std::endl;
}

void structPointerDemo() {
    std::cout << "\n=== Pointers to Structs ===\n";

    // Allocate on heap
    Student* s = new Student;
    initStudent(s, 12345, "Alice");
    s->marks[0] = 85; s->marks[1] = 90;
    s->marks[2] = 78; s->marks[3] = 92;
    s->average = calcAvg(s->marks, 4);
    printStudent(s);
    delete s;
}

// ============================================
// 3. DYNAMIC 2D ARRAY
// ============================================

int** createMatrix(int rows, int cols) {
    int** m = new int*[rows];
    for (int i = 0; i < rows; i++)
        m[i] = new int[cols];
    return m;
}

void fillMatrix(int** m, int rows, int cols) {
    int val = 1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            *(*(m + i) + j) = val++; // Pointer notation
}

void printMatrix(int** m, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            std::cout << *(*(m + i) + j) << "\t";
        std::cout << std::endl;
    }
}

void destroyMatrix(int** m, int rows) {
    for (int i = 0; i < rows; i++)
        delete[] m[i];
    delete[] m;
}

void dynamic2D() {
    std::cout << "\n=== Dynamic 2D Array ===\n";
    int rows = 3, cols = 4;
    int** mat = createMatrix(rows, cols);
    fillMatrix(mat, rows, cols);
    printMatrix(mat, rows, cols);
    destroyMatrix(mat, rows);
}

// ============================================
// 4. CONTIGUOUS 2D ARRAY (single allocation)
// ============================================

void contiguous2D() {
    std::cout << "\n=== Contiguous 2D Array ===\n";
    int rows = 3, cols = 4;
    int* mat = new int[rows * cols];

    // Fill
    int val = 1;
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            mat[r * cols + c] = val++;

    // Print using pointer
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++)
            std::cout << *(mat + r * cols + c) << "\t";
        std::cout << std::endl;
    }
    delete[] mat;
}

// ============================================
// 5. C-STRING MANIPULATION WITH POINTERS
// ============================================

int stringLength(const char* str) {
    const char* p = str;
    while (*p) p++;
    return p - str;
}

char* stringCopy(char* dest, const char* src) {
    char* original = dest;
    while (*src)
        *dest++ = *src++;
    *dest = '\0';
    return original;
}

char* stringConcat(char* dest, const char* src) {
    char* original = dest;
    while (*dest) dest++;
    while (*src) *dest++ = *src++;
    *dest = '\0';
    return original;
}

int stringCompare(const char* a, const char* b) {
    while (*a && *a == *b) { a++; b++; }
    return *a - *b;
}

void cStringPointers() {
    std::cout << "\n=== C-Strings with Pointers ===\n";
    char str1[20] = "Hello";
    const char* str2 = " World";

    char result[30];
    stringCopy(result, str1);
    stringConcat(result, str2);
    std::cout << "Concatenated: " << result << std::endl;
    std::cout << "Length: " << stringLength(result) << std::endl;
    std::cout << "Compare \"abc\" vs \"abd\": " << stringCompare("abc", "abd") << std::endl;
}

// ============================================
// 6. FUNCTION POINTERS
// ============================================

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divide(int a, int b) {
    if (b == 0) { std::cout << "Div by 0!\n"; return 0; }
    return a / b;
}

void functionPointerDemo() {
    std::cout << "\n=== Function Pointers ===\n";

    // Array of function pointers
    int (*ops[])(int, int) = {add, sub, mul, divide};
    const char* names[] = {"Add", "Sub", "Mul", "Div"};

    int x = 20, y = 5;
    for (int i = 0; i < 4; i++)
        std::cout << names[i] << ": " << ops[i](x, y) << std::endl;

    // Function pointer as parameter
    auto compute = [](int (*op)(int, int), int a, int b) {
        return op(a, b);
    };
    std::cout << "compute(add, 10, 5) = " << compute(add, 10, 5) << std::endl;
}

// ============================================
// 7. POINTER TO POINTER (for modifying pointer)
// ============================================

void allocateArray(int** arr, int size) {
    *arr = new int[size];
    for (int i = 0; i < size; i++)
        (*arr)[i] = i * 10;
}

void pointerToPointerDemo() {
    std::cout << "\n=== Pointer to Pointer ===\n";
    int* arr = nullptr;
    allocateArray(&arr, 5);

    for (int i = 0; i < 5; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    delete[] arr;
}

// ============================================
// 8. COMMAND LINE ARGUMENTS
// ============================================

int main(int argc, char* argv[]) {
    std::cout << "=== Command Line Args ===\n";
    std::cout << "Program: " << argv[0] << std::endl;
    std::cout << "Arg count: " << argc - 1 << std::endl;

    for (int i = 1; i < argc; i++)
        std::cout << "arg[" << i << "]: " << argv[i] << std::endl;

    // Demo all sections
    arrayPointerEquivalence();
    structPointerDemo();
    dynamic2D();
    contiguous2D();
    cStringPointers();
    functionPointerDemo();
    pointerToPointerDemo();

    return 0;
}