#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// ============================================
// 1. BASIC RECURSION
// ============================================

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int sumDigits(int n) {
    if (n < 10) return n;
    return n % 10 + sumDigits(n / 10);
}

void printBinary(int n) {
    if (n > 1) printBinary(n / 2);
    std::cout << n % 2;
}

// ============================================
// 2. TOWERS OF HANOI
// ============================================

int hanoiMoves = 0;

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        std::cout << "Move disk 1 from " << from << " to " << to << std::endl;
        hanoiMoves++;
        return;
    }
    hanoi(n - 1, from, aux, to);
    std::cout << "Move disk " << n << " from " << from << " to " << to << std::endl;
    hanoiMoves++;
    hanoi(n - 1, aux, to, from);
}

// ============================================
// 3. BINARY SEARCH (RECURSIVE)
// ============================================

int binarySearch(const int arr[], int left, int right, int target) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) return mid;
    if (arr[mid] < target) return binarySearch(arr, mid + 1, right, target);
    return binarySearch(arr, left, mid - 1, target);
}

// ============================================
// 4. MERGE SORT
// ============================================

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

// ============================================
// 5. QUICK SORT
// ============================================

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

// ============================================
// 6. GENERATE PERMUTATIONS
// ============================================

void generatePermutations(std::string str, int left, int right) {
    if (left == right) {
        std::cout << str << std::endl;
        return;
    }
    for (int i = left; i <= right; i++) {
        std::swap(str[left], str[i]);
        generatePermutations(str, left + 1, right);
        std::swap(str[left], str[i]); // Backtrack
    }
}

// ============================================
// 7. MAZE SOLVER
// ============================================

const int MAZE_SIZE = 5;
int maze[MAZE_SIZE][MAZE_SIZE] = {
    {1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1},
    {0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1}
};

bool solveMaze(int x, int y, int sol[MAZE_SIZE][MAZE_SIZE]) {
    // Reached destination? (bottom-right)
    if (x == MAZE_SIZE - 1 && y == MAZE_SIZE - 1) {
        sol[x][y] = 1;
        return true;
    }

    // Valid cell?
    if (x >= 0 && x < MAZE_SIZE && y >= 0 && y < MAZE_SIZE
        && maze[x][y] == 1 && sol[x][y] == 0) {

        sol[x][y] = 1; // Mark as part of path

        // Move Right
        if (solveMaze(x + 1, y, sol)) return true;
        // Move Down
        if (solveMaze(x, y + 1, sol)) return true;
        // Move Left
        if (solveMaze(x - 1, y, sol)) return true;
        // Move Up
        if (solveMaze(x, y - 1, sol)) return true;

        sol[x][y] = 0; // Backtrack
        return false;
    }
    return false;
}

void printMaze(int sol[MAZE_SIZE][MAZE_SIZE]) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++)
            std::cout << (sol[i][j] ? " 1" : " 0");
        std::cout << std::endl;
    }
}

// ============================================
// 8. TIMING DEMO
// ============================================

void timingDemo() {
    std::cout << "\n=== Sorting Performance ===\n";

    const int SIZE = 10000;
    int* arr1 = new int[SIZE];
    int* arr2 = new int[SIZE];

    for (int i = 0; i < SIZE; i++) {
        int val = rand() % 10000;
        arr1[i] = val;
        arr2[i] = val;
    }

    clock_t start = clock();
    mergeSort(arr1, 0, SIZE - 1);
    clock_t end = clock();
    double mergeTime = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Merge Sort: " << mergeTime << "s\n";

    start = clock();
    quickSort(arr2, 0, SIZE - 1);
    end = clock();
    double quickTime = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Quick Sort: " << quickTime << "s\n";

    // Verify they're the same
    bool same = true;
    for (int i = 0; i < SIZE; i++)
        if (arr1[i] != arr2[i]) { same = false; break; }
    std::cout << "Sorts match: " << (same ? "Yes" : "No") << std::endl;

    delete[] arr1;
    delete[] arr2;
}

// ============================================
// MAIN
// ============================================

int main() {
    std::cout << "=== Basic Recursion ===\n";
    std::cout << "factorial(6) = " << factorial(6) << std::endl;
    std::cout << "fibonacci(10) = " << fibonacci(10) << std::endl;
    std::cout << "sumDigits(12345) = " << sumDigits(12345) << std::endl;
    std::cout << "binary(42) = "; printBinary(42); std::cout << std::endl;

    std::cout << "\n=== Towers of Hanoi (3 disks) ===\n";
    hanoi(3, 'A', 'C', 'B');
    std::cout << "Total moves: " << hanoiMoves << std::endl;

    std::cout << "\n=== Binary Search ===\n";
    int sorted[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int idx = binarySearch(sorted, 0, 9, 13);
    std::cout << "Found 13 at index " << idx << std::endl;

    std::cout << "\n=== Merge Sort ===\n";
    int arr1[] = {38, 27, 43, 3, 9, 82, 10};
    int s1 = sizeof(arr1) / sizeof(arr1[0]);
    mergeSort(arr1, 0, s1 - 1);
    for (int x : arr1) std::cout << x << " ";
    std::cout << std::endl;

    std::cout << "\n=== Quick Sort ===\n";
    int arr2[] = {10, 80, 30, 90, 40, 50, 70};
    int s2 = sizeof(arr2) / sizeof(arr2[0]);
    quickSort(arr2, 0, s2 - 1);
    for (int x : arr2) std::cout << x << " ";
    std::cout << std::endl;

    std::cout << "\n=== Permutations of \"ABC\" ===\n";
    generatePermutations("ABC", 0, 2);

    std::cout << "\n=== Maze Solver ===\n";
    int solution[MAZE_SIZE][MAZE_SIZE] = {0};
    if (solveMaze(0, 0, solution)) {
        std::cout << "Solution found:\n";
        printMaze(solution);
    } else {
        std::cout << "No path exists\n";
    }

    timingDemo();

    return 0;
}