# Week 4 Exercises: Arrays

## Exercise 1: Grade Book
Write a program that:
1. Asks how many students (max 100)
2. Inputs marks for each student (0-100)
3. Calculates and displays:
   - Average mark
   - Highest mark and which student got it
   - Lowest mark and which student got it
   - Count of students above average
   - Count of students below average

**Extension**: Display a histogram:
```
0-9:   ***
10-19: *****
20-29: **
...
```

---

## Exercise 2: Dynamic Array Menu
Implement a menu-driven array program:
```
1. Insert (at position)
2. Delete (at position)
3. Search (return index)
4. Display all
5. Sort (ascending)
6. Reverse
7. Exit
```
Use a fixed array of size 100, track actual size.

---

## Exercise 3: Remove Duplicates (in-place)
Given a **sorted** array, remove duplicates in-place so each element appears only once.
Return the new size.
```cpp
Input:  [1, 1, 2, 2, 2, 3, 4, 4, 5]
Output: [1, 2, 3, 4, 5] -> size = 5
```
No new array. Shift elements in-place.

---

## Exercise 4: Matrix Operations
```cpp
const int ROWS = 3;
const int COLS = 3;
```
Implement functions:
```cpp
void inputMatrix(int matrix[ROWS][COLS]);
void printMatrix(int matrix[ROWS][COLS]);
void addMatrices(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]);
void multiplyMatrices(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]);
int determinant(int matrix[ROWS][COLS]);
```
Test with user input.

---

## Exercise 5: Two-Sum
Given an array and a target value, find two indices `i, j` where `arr[i] + arr[j] == target`.
```cpp
Input:  arr = [2, 7, 11, 15], target = 9
Output: [0, 1] because 2 + 7 = 9
```
Assume exactly one solution exists. Try O(n²) first, then optimise.

---

## Exercise 6: Circular Array Rotation
Rotate array elements right by k positions without using extra array.
```cpp
Input:  [1, 2, 3, 4, 5], k = 2
Output: [4, 5, 1, 2, 3]
```

---

## Exercise 7: Subarray with Maximum Sum (Kadane's Algorithm)
Given integer array, find contiguous subarray with the largest sum.
```cpp
Input:  [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: 6 (subarray [4, -1, 2, 1])
```

---

## Exercise 8: Array Intersection
Given two sorted arrays, print their intersection (elements that appear in both).
```cpp
Input:  A = [1, 2, 3, 4, 5], B = [2, 4, 6, 8]
Output: [2, 4]
```

---

## Solutions

### Exercise 1 Solution
```cpp
#include <iostream>
#include <climits>

int main() {
    int n;
    std::cout << "Number of students: ";
    std::cin >> n;

    int marks[100];
    int sum = 0;
    int highest = INT_MIN, lowest = INT_MAX;
    int highIdx = 0, lowIdx = 0;

    for (int i = 0; i < n; i++) {
        std::cout << "Student " << i + 1 << " mark: ";
        std::cin >> marks[i];
        sum += marks[i];

        if (marks[i] > highest) { highest = marks[i]; highIdx = i; }
        if (marks[i] < lowest)  { lowest = marks[i];  lowIdx = i; }
    }

    double avg = (double)sum / n;
    int above = 0, below = 0;
    for (int i = 0; i < n; i++) {
        if (marks[i] > avg) above++;
        else if (marks[i] < avg) below++;
    }

    std::cout << "\n--- Results ---\n";
    std::cout << "Average: " << avg << std::endl;
    std::cout << "Highest: " << highest << " (Student " << highIdx + 1 << ")\n";
    std::cout << "Lowest:  " << lowest << " (Student " << lowIdx + 1 << ")\n";
    std::cout << "Above avg: " << above << ", Below avg: " << below << std::endl;

    // Histogram
    int ranges[10] = {0};
    for (int i = 0; i < n; i++) {
        int idx = marks[i] / 10;
        if (idx == 10) idx = 9;
        ranges[idx]++;
    }
    std::cout << "\nHistogram:\n";
    for (int i = 0; i < 10; i++) {
        std::cout << i * 10 << "-" << i * 10 + 9 << ": ";
        for (int j = 0; j < ranges[i]; j++) std::cout << "*";
        std::cout << "\n";
    }

    return 0;
}
```

### Exercise 3 Solution
```cpp
int removeDuplicates(int arr[], int size) {
    if (size <= 1) return size;

    int writeIdx = 1;
    for (int readIdx = 1; readIdx < size; readIdx++) {
        if (arr[readIdx] != arr[readIdx - 1]) {
            arr[writeIdx] = arr[readIdx];
            writeIdx++;
        }
    }
    return writeIdx;
}
```

### Exercise 5 Solution (O(n²))
```cpp
void twoSum(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == target) {
                std::cout << "[" << i << ", " << j << "]" << std::endl;
                return;
            }
        }
    }
    std::cout << "No solution found" << std::endl;
}
```

### Exercise 6 Solution
```cpp
void rotateRight(int arr[], int size, int k) {
    k = k % size; // Handle k > size
    if (k == 0) return;

    // Reverse entire array
    for (int i = 0, j = size - 1; i < j; i++, j--)
        std::swap(arr[i], arr[j]);

    // Reverse first k
    for (int i = 0, j = k - 1; i < j; i++, j--)
        std::swap(arr[i], arr[j]);

    // Reverse remaining
    for (int i = k, j = size - 1; i < j; i++, j--)
        std::swap(arr[i], arr[j]);
}
```

### Exercise 7 Solution
```cpp
int kadane(int arr[], int size) {
    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];

    for (int i = 1; i < size; i++) {
        maxEndingHere = std::max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = std::max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}
```

### Exercise 8 Solution
```cpp
void intersection(int A[], int sizeA, int B[], int sizeB) {
    int i = 0, j = 0;
    while (i < sizeA && j < sizeB) {
        if (A[i] < B[j]) i++;
        else if (B[j] < A[i]) j++;
        else {
            std::cout << A[i] << " ";
            i++; j++;
        }
    }
    std::cout << std::endl;
}
```