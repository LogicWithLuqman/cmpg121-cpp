# Week 6 Exercises: Pointers & References

## Exercise 1: Pointer Exploration
Write a program that:
1. Declares `int`, `double`, `char`, and `bool` variables with initial values
2. Creates pointers to each
3. Prints: variable value, variable address, pointer value, dereferenced pointer
4. Modifies each variable via its pointer
5. Prints all values again to confirm change

---

## Exercise 2: Pointer Swap
```cpp
void swap(int* a, int* b);
```
Test with two integers. Show values before and after.

**Challenge**: Write a version that uses reference parameters instead:
```cpp
void swapRef(int& a, int& b);
```

---

## Exercise 3: Dynamic Array Manager
Write a program that:
1. Asks user for array size
2. Dynamically allocates array
3. Fills with random numbers (1-100)
4. Prints the array
5. Finds and prints min, max, average (using pointer functions)
6. Properly deletes the array

---

## Exercise 4: String Length without strlen
Write function:
```cpp
int stringLength(const char* str);
```
That returns the length of a C-string **without** using `<cstring>` functions.
Test on several strings.

---

## Exercise 5: Find First Occurrence
```cpp
int* findFirst(int* arr, int size, int target);
```
Returns pointer to first occurrence of target, or `nullptr` if not found.
```cpp
int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
int* result = findFirst(arr, 8, 1);
// result should point to arr[1]
```

---

## Exercise 6: Reverse Array via Pointers
```cpp
void reverse(int* arr, int size);
```
Reverse an array in-place using two pointers (one at start, one at end). No index variables allowed — use pointer arithmetic only.

---

## Exercise 7: Matrix via Pointers
Create a dynamic 2D matrix:
```cpp
int** createMatrix(int rows, int cols);
void fillMatrix(int** matrix, int rows, int cols);
void printMatrix(int** matrix, int rows, int cols);
void destroyMatrix(int** matrix, int rows);
```
Use `new` for each row. The `destroyMatrix` function must free every row then the main pointer.

---

## Exercise 8: Linked List Node (Pre-OOP)
```cpp
struct Node {
    int data;
    Node* next;
};
```
Implement:
- `Node* createNode(int value)` — allocate and return
- `void append(Node*& head, int value)` — add to end
- `void printList(Node* head)` — traverse and print
- `void deleteList(Node*& head)` — free all nodes

---

## Exercise 9: Function Pointer Calculator
Create an array of function pointers for: add, subtract, multiply, divide.
Prompt user for two numbers and an operation choice (0-3).
Apply the selected operation via pointer.

---

## Solutions

### Exercise 1 Solution
```cpp
#include <iostream>

int main() {
    int i = 42;
    double d = 3.14;
    char c = 'X';
    bool b = true;

    int* pi = &i;
    double* pd = &d;
    char* pc = &c;
    bool* pb = &b;

    std::cout << "int:   value=" << i << " addr=" << &i
              << " ptr=" << pi << " *ptr=" << *pi << std::endl;
    std::cout << "double:value=" << d << " addr=" << &d
              << " ptr=" << pd << " *ptr=" << *pd << std::endl;
    std::cout << "char:  value=" << c << " addr=" << (void*)&c
              << " ptr=" << (void*)pc << " *ptr=" << *pc << std::endl;
    std::cout << "bool:  value=" << b << " addr=" << &b
              << " ptr=" << pb << " *ptr=" << *pb << std::endl;

    // Modify via pointers
    *pi = 99; *pd = 2.71; *pc = 'Y'; *pb = false;

    std::cout << "\nAfter modification via pointers:\n";
    std::cout << "i=" << i << " d=" << d << " c=" << c << " b=" << b << std::endl;
    return 0;
}
```

### Exercise 2 Solution
```cpp
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapRef(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
```

### Exercise 5 Solution
```cpp
int* findFirst(int* arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return &arr[i]; // Return pointer to found element
    }
    return nullptr;
}
```

### Exercise 6 Solution
```cpp
void reverse(int* arr, int size) {
    int* left = arr;
    int* right = arr + size - 1;
    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}
```

### Exercise 7 Solution
```cpp
int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];
    return matrix;
}

void destroyMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
}

void fillMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = i * cols + j + 1;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            std::cout << matrix[i][j] << "\t";
        std::cout << std::endl;
    }
}
```

### Exercise 8 Solution
```cpp
struct Node { int data; Node* next; };

Node* createNode(int value) {
    Node* n = new Node;
    n->data = value;
    n->next = nullptr;
    return n;
}

void append(Node*& head, int value) {
    if (head == nullptr) {
        head = createNode(value);
        return;
    }
    Node* current = head;
    while (current->next != nullptr)
        current = current->next;
    current->next = createNode(value);
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "nullptr\n";
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
```

### Exercise 9 Solution
```cpp
int main() {
    const int OPS = 4;
    int (*operations[OPS])(int, int) = {add, subtract, multiply, divide};
    const char* names[OPS] = {"Add", "Subtract", "Multiply", "Divide"};

    int a, b, choice;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;
    std::cout << "0=Add 1=Sub 2=Mul 3=Div: ";
    std::cin >> choice;

    if (choice >= 0 && choice < OPS)
        std::cout << "Result: " << operations[choice](a, b) << std::endl;
    else
        std::cout << "Invalid choice\n";
}
```