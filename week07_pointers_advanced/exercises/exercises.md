# Week 7 Exercises: Advanced Pointers

## Exercise 1: Manual String Copy
Implement all string functions using **only pointer arithmetic** (no `[]`):
```cpp
int strLen(const char* s);
char* strCpy(char* dest, const char* src);
char* strCat(char* dest, const char* src);
int strCmp(const char* a, const char* b);
char* strChr(char* s, char c);  // Find first occurrence
```
Test with: `"Hello"`, `"World"`, empty string `""`.

---

## Exercise 2: Dynamic Student Manager
```cpp
struct Student {
    int id;
    char name[50];
    double gpa;
};
```
Implement:
```cpp
Student* createStudent(int id, const char* name, double gpa);
void printStudents(const Student* students, int count);
void sortByGPA(Student* students, int count);  // Descending
Student* findById(Student* students, int count, int id);
void destroyStudents(Student* students);
```

**Menu**: 1=Add student, 2=Display all, 3=Sort by GPA, 4=Find by ID, 5=Exit

---

## Exercise 3: Command-Line Calculator
Create a program that takes input from command line:
```bash
./calc 15 + 3
./calc 10 x 4
./calc 100 / 7
./calc 50 - 8
```
Use `argc`/`argv` and function pointers. Handle invalid operators/arguments.

---

## Exercise 4: Matrix Transpose (In-Place)
```cpp
void transpose(int** matrix, int rows, int cols);
```
Transpose a dynamically allocated matrix. Use pointer notation throughout.
For non-square matrices, create a new matrix.

---

## Exercise 5: String Tokenizer
```cpp
char** split(const char* str, char delimiter, int& tokenCount);
```
Splits a string by delimiter. Returns array of C-strings.
```cpp
char** tokens = split("apple,banana,cherry", ',', count);
// tokens = {"apple", "banana", "cherry"}, count = 3
```
Must also implement `void freeTokens(char** tokens, int count)`.

---

## Exercise 6: Generic Swap
Write a function that swaps any two values using `void*`:
```cpp
void genericSwap(void* a, void* b, size_t size);
```
Test swapping `int`, `double`, and `char` arrays.

---

## Exercise 7: Bubble Sort with Function Pointer
```cpp
void bubbleSort(int* arr, int size, bool (*compare)(int, int));
```
Where `compare` determines ordering:
```cpp
bool ascending(int a, int b)  { return a > b; }
bool descending(int a, int b) { return a < b; }
```
Sort array either way based on function parameter.

---

## Exercise 8: Linked List with Advanced Operations
Extend Week 6 linked list:
```cpp
struct Node { int data; Node* next; };

void insertSorted(Node*& head, int value);  // Maintain sorted order
void remove(Node*& head, int value);         // Remove first occurrence
bool hasCycle(Node* head);                   // Detect cycle (Floyd's)
Node* reverse(Node* head);                   // Return reversed list
Node* merge(Node* a, Node* b);              // Merge two sorted lists
```

---

## Solutions

### Exercise 1 Solution
```cpp
int strLen(const char* s) {
    const char* p = s;
    while (*p) p++;
    return p - s;
}

char* strCpy(char* dest, const char* src) {
    char* d = dest;
    while (*src) *d++ = *src++;
    *d = '\0';
    return dest;
}

char* strCat(char* dest, const char* src) {
    char* d = dest;
    while (*d) d++;
    while (*src) *d++ = *src++;
    *d = '\0';
    return dest;
}

int strCmp(const char* a, const char* b) {
    while (*a && *a == *b) { a++; b++; }
    return *a - *b;
}

char* strChr(char* s, char c) {
    while (*s) {
        if (*s == c) return s;
        s++;
    }
    return nullptr;
}
```

### Exercise 7 Solution
```cpp
bool ascending(int a, int b)  { return a > b; }
bool descending(int a, int b) { return a < b; }

void bubbleSort(int* arr, int size, bool (*compare)(int, int)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (compare(arr[j], arr[j + 1]))
                std::swap(arr[j], arr[j + 1]);
        }
    }
}

// Usage:
int arr[] = {5, 2, 8, 1, 9};
bubbleSort(arr, 5, ascending);   // Ascending
bubbleSort(arr, 5, descending);  // Descending
```

### Exercise 8 - detect cycle (Floyd's algorithm)
```cpp
bool hasCycle(Node* head) {
    if (!head) return false;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```

### Exercise 8 - reverse linked list
```cpp
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
```