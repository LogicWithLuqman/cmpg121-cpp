# Week 9: Recursion & Sorting

## Part 1: Recursion

A function that calls itself. Every recursive function needs:
1. **Base case**: Condition where recursion stops
2. **Recursive case**: Function calls itself with modified parameters

```cpp
int factorial(int n) {
    if (n <= 1) return 1;     // Base case
    return n * factorial(n - 1); // Recursive case
}
```

### Call Stack Visualization for `factorial(4)`:
```
factorial(4) -> 4 * factorial(3)
    factorial(3) -> 3 * factorial(2)
        factorial(2) -> 2 * factorial(1)
            factorial(1) -> 1 (BASE)
        returns 2 * 1 = 2
    returns 3 * 2 = 6
returns 4 * 6 = 24
```

### Types of Recursion
| Type | Description | Example |
|------|-------------|---------|
| Direct | Function calls itself | `factorial(n)` |
| Indirect | A -> B -> A | Mutual recursion |
| Tail | Recursive call is last operation | Can be optimized |
| Head | Recursive call before processing | Uses more stack |

### Tail Recursion
```cpp
// Tail recursive: recursive call is the LAST thing
int tailFactorial(int n, int accumulator = 1) {
    if (n <= 1) return accumulator;
    return tailFactorial(n - 1, n * accumulator);
}
// Compiler can optimize this to a loop!
```

## Part 2: Advanced Sorting

### Merge Sort (O(n log n))
Divide and conquer: split array, sort halves, merge.

```cpp
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int* L = new int[n1];
    int* R = new int[n2];
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
```

### Quick Sort (O(n log n) average)
Pick a pivot, partition, recursively sort partitions.

```cpp
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```

## Part 3: Algorithm Complexity (Big O)

| Algorithm | Best | Average | Worst | Space |
|-----------|------|---------|-------|-------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |

## Part 4: Classic Recursion Problems

### Towers of Hanoi
```cpp
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        std::cout << "Move disk 1 from " << from << " to " << to << std::endl;
        return;
    }
    hanoi(n - 1, from, aux, to);
    std::cout << "Move disk " << n << " from " << from << " to " << to << std::endl;
    hanoi(n - 1, aux, to, from);
}
```

### Binary Search (Recursive)
```cpp
int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target) return binarySearch(arr, mid + 1, right, target);
    return binarySearch(arr, left, mid - 1, target);
}
```

---
## Exercises

1. **Merge Sort on Structs**: Sort Student array by GPA using merge sort.
2. **Quick Sort on Strings**: Sort array of strings alphabetically.
3. **Hanoi Tower**: Solve 3-5 disks. Track number of moves.
4. **Permutations**: Generate all permutations of a string recursively.
5. **Maze Solver**: Find path through a 2D maze using recursion.