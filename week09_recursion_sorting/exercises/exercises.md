# Week 9 Exercises: Recursion & Sorting

## Exercise 1: Recursive Power Function
Write `int power(int base, int exp)` recursively.
```cpp
Input:  power(2, 5)
Output: 32
```
Handle `exp == 0` (return 1) and negative exponents.

---

## Exercise 2: Merge Sort on Structs
```cpp
struct Student {
    int id;
    char name[50];
    double gpa;
};
```
Implement `mergeSortStudents(Student arr[], int left, int right)` that sorts by GPA descending.
Test with 6 students.

---

## Exercise 3: Quick Sort on Strings
Implement `quickSortStrings(std::string arr[], int low, int high)` to sort strings alphabetically.
```cpp
Input:  {"banana", "apple", "date", "cherry", "elderberry"}
Output: {"apple", "banana", "cherry", "date", "elderberry"}
```

---

## Exercise 4: Towers of Hanoi Visualizer
Solve Towers of Hanoi for N disks. Track and display:
- Number of moves (2ⁿ - 1)
- State of each peg after each move
- Minimum moves required

**Extension**: Use structs for pegs (arrays as stacks).

---

## Exercise 5: Generate All Permutations
Generate all permutations of a string of length N (1 to 6).
```cpp
Input:  "ABC"
Output: ABC ACB BAC BCA CAB CBA
```

**Challenge**: Generate permutations in lexicographic (dictionary) order.

---

## Exercise 6: Maze Solver with Path Display
Given a maze:
```
S 0 1 0 1
1 1 1 0 1
0 0 1 0 0
1 1 1 1 1
1 0 0 0 E
```
S = Start (0,0), E = End (4,4). 1 = path, 0 = wall.
Find path using recursion. Display path with `*`.

---

## Exercise 7: N-Queens Problem
Place N queens on an N×N chessboard so no two attack each other.
```cpp
const int N = 8;
bool solveNQueens(int board[N][N], int col);
void printBoard(int board[N][N]);
bool isSafe(int board[N][N], int row, int col);
```
Output the first valid arrangement.

---

## Exercise 8: Recursive Directory Traversal (Bonus)
Using `<filesystem>` (C++17) or system commands, recursively list all files:
```
dir/
  file1.txt
  subdir/
    file2.txt
    nested/
      file3.txt
```

---

## Solutions

### Exercise 1 Solution
```cpp
int power(int base, int exp) {
    if (exp == 0) return 1;
    if (exp < 0) return 1 / power(base, -exp);
    if (exp % 2 == 0) {
        int half = power(base, exp / 2);
        return half * half;
    }
    return base * power(base, exp - 1);
}
```

### Exercise 7 Solution - N-Queens
```cpp
const int N = 8;

bool isSafe(int board[N][N], int row, int col) {
    // Check row on left
    for (int i = 0; i < col; i++)
        if (board[row][i]) return false;

    // Check upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // Check lower diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j]) return false;

    return true;
}

bool solveNQueens(int board[N][N], int col) {
    if (col >= N) return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQueens(board, col + 1))
                return true;

            board[i][col] = 0; // Backtrack
        }
    }
    return false;
}

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            std::cout << (board[i][j] ? " Q" : " .");
        std::cout << std::endl;
    }
}
```

### Exercise 8 Solution
```cpp
#include <filesystem>
namespace fs = std::filesystem;

void listFiles(const fs::path& path, int depth = 0) {
    for (const auto& entry : fs::directory_iterator(path)) {
        for (int i = 0; i < depth; i++) std::cout << "  ";
        std::cout << (entry.is_directory() ? "[DIR] " : "[FILE] ")
                  << entry.path().filename() << std::endl;
        if (entry.is_directory())
            listFiles(entry.path(), depth + 1);
    }
}
```