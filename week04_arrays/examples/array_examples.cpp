#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

// ============================================
// ARRAY EXAMPLES
// ============================================

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// Linear search
int linearSearch(const int arr[], int size, int target) {
    for (int i = 0; i < size; i++)
        if (arr[i] == target) return i;
    return -1;
}

// Bubble sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}

// Selection sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        std::swap(arr[i], arr[minIdx]);
    }
}

// Binary search (array must be sorted)
int binarySearch(const int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// 2D Array - matrix addition
const int ROWS = 3;
const int COLS = 4;

void addMatrices(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            result[r][c] = a[r][c] + b[r][c];
}

void printMatrix(int m[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++)
            std::cout << std::setw(4) << m[r][c];
        std::cout << std::endl;
    }
}

// Array reversal (in-place)
void reverseArray(int arr[], int size) {
    for (int i = 0, j = size - 1; i < j; i++, j--)
        std::swap(arr[i], arr[j]);
}

int main() {
    std::cout << "=== Array Declaration & Initialization ===\n";

    // Method 1: Size + values
    int arr1[5] = {10, 20, 30, 40, 50};
    std::cout << "arr1: "; printArray(arr1, 5);

    // Method 2: Deduced size
    int arr2[] = {5, 3, 1, 4, 2};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "arr2 (unsorted): "; printArray(arr2, size2);

    // Sorting
    bubbleSort(arr2, size2);
    std::cout << "arr2 (sorted):   "; printArray(arr2, size2);

    std::cout << "\n=== Searching ===\n";
    int target = 30;
    int idx = linearSearch(arr1, 5, target);
    std::cout << "Linear search for " << target << ": index " << idx << std::endl;

    idx = binarySearch(arr2, size2, 3);
    std::cout << "Binary search for 3 in sorted: index " << idx << std::endl;

    std::cout << "\n=== 2D Arrays ===\n";
    int matrixA[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int matrixB[ROWS][COLS] = {
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };
    int result[ROWS][COLS] = {0};
    addMatrices(matrixA, matrixB, result);
    std::cout << "Matrix A + Matrix B:\n";
    printMatrix(result);

    std::cout << "\n=== Reverse ===\n";
    int arrRev[] = {1, 2, 3, 4, 5};
    int revSize = sizeof(arrRev) / sizeof(arrRev[0]);
    std::cout << "Before reverse: "; printArray(arrRev, revSize);
    reverseArray(arrRev, revSize);
    std::cout << "After reverse:  "; printArray(arrRev, revSize);

    std::cout << "\n=== Vectors (C++11) ===\n";
    std::vector<int> vec = {7, 2, 9, 1, 5};
    std::sort(vec.begin(), vec.end());
    std::cout << "Sorted vector: ";
    for (int v : vec) std::cout << v << " ";
    std::cout << std::endl;

    return 0;
}