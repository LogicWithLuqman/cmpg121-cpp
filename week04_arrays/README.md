# Week 4: Arrays

Arrays store multiple values of the same type in contiguous memory. Fixed size at compile time (mostly).

## 1. Declaration & Initialization
```cpp
// Declaration (uninitialized - garbage values!)
int scores[5];

// Initialization
int scores[5] = {90, 85, 78, 92, 88};

// Size deduced
int scores[] = {90, 85, 78, 92, 88}; // Size = 5

// Partial initialization (rest = 0)
int scores[10] = {1, 2, 3}; // {1,2,3,0,0,0,0,0,0,0}

// All zeros
int scores[100] = {0};
```

## 2. Accessing Elements
```cpp
int arr[5] = {10, 20, 30, 40, 50};

arr[0] = 100;        // Modify first
std::cout << arr[2]; // Print third (30)

// BOUNDS CHECKING: C++ does NOT check bounds!
// arr[10] = 5; // CRASH or garbage - UNDEFINED BEHAVIOR
```

## 3. Array Size
```cpp
int arr[] = {1, 2, 3, 4, 5};
int size = sizeof(arr) / sizeof(arr[0]); // 5

// ONLY works in same scope! If passed to function, decays to pointer.
```

## 4. Common Algorithms

### Linear Search
```cpp
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i; // Found at index i
    }
    return -1; // Not found
}
```

### Finding Min/Max
```cpp
int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] < min) min = arr[i];
    return min;
}
```

### Traversal
```cpp
for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
}

// Range-based (C++11)
for (int val : arr) {
    std::cout << val << " ";
}
```

## 5. Sorting Algorithms

### Bubble Sort (O(n²))
```cpp
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

### Selection Sort (O(n²))
```cpp
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        std::swap(arr[i], arr[minIdx]);
    }
}
```

### Insertion Sort (O(n²) - good for small/nearly sorted)
```cpp
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```

## 6. Multi-Dimensional Arrays
```cpp
// 3 rows, 4 columns
int matrix[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

matrix[1][2] = 99; // Row 1, Col 2

// Nested loop traversal
for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 4; c++) {
        std::cout << matrix[r][c] << " ";
    }
    std::cout << std::endl;
}
```

## 7. Arrays & Functions
Arrays decay to pointers when passed:
```cpp
// These are equivalent
void func(int arr[], int size);
void func(int *arr, int size);
void func(int arr[100], int size); // Size ignored!
```

---
## Exercises

1. **Grade Book**: Input 10 student marks. Calculate average, highest, lowest. Count how many above/below average.
2. **Array Operations Menu**: Menu-driven program: Insert, Delete, Search, Display, Sort, Reverse.
3. **Remove Duplicates**: Given sorted array, remove duplicates in-place. Return new size.
4. **Matrix Operations**: Add two 3x3 matrices. Multiply 3x3 * 3x3.
5. **Merge Two Sum Problem**: Given array and target, find indices of two numbers that add to target.