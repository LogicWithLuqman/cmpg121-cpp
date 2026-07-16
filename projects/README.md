# CMPG121 Projects

## Warm-Up: Student Management System (C++)

Build a console-based student management system. This is the **same project you will port to C#** in CMPG122 — proving you understand concepts, not just syntax.

### Features
- Add student (name, ID, marks)
- View all students
- Calculate average marks
- Search by name or ID
- Save/load from file (`students.txt`)
- Simple text menu interface

### Starter structure
```cpp
struct Student {
    string name;
    string id;
    double marks[5];
    int markCount;
};

void addStudent(Student students[], int& count);
void displayAll(Student students[], int count);
double calculateAverage(Student s);
void saveToFile(Student students[], int count);
void loadFromFile(Student students[], int& count);
```

### Why build this?
- Same project in two languages = interview flex
- Covers: structs, arrays, loops, file I/O, functions, search
- Porting to C# teaches you C# syntax quickly

---

## Final Projects

Two comprehensive projects that combine ALL topics from the semester.

---

## Project 1: Library Management System

Build a complete library management system that uses structs, arrays, file I/O, pointers, sorting, and searching.

### Requirements

```cpp
struct Book {
    int isbn;
    char title[100];
    char author[100];
    int year;
    bool isBorrowed;
    char borrowerName[50];
    char borrowerSurname[50];
    struct { int day, month, year; } borrowDate;
    struct { int day, month, year; } dueDate;
};
```

### Features
1. **Add Book**: Input book details, append to binary file `library.dat`
2. **Display All Books**: Read and display all books in table format
3. **Search Books**: By ISBN (exact), by title (partial), by author (partial)
4. **Borrow Book**: Mark as borrowed, record borrower name and dates (14-day loan period)
5. **Return Book**: Mark as available, clear borrower fields
6. **Overdue Report**: List all books past their due date
7. **Delete Book**: Mark as deleted (set ISBN to -1)
8. **Statistics**: Total books, available, borrowed, overdue, most borrowed author
9. **Sort Options**: By title, by author, by year (ascending/descending) using `qsort` or custom sort
10. **Save & Exit**: All changes persisted to binary file

### Data Structures
- Use a dynamic array (pointer to Book, allocated based on file record count)
- Binary file I/O with `fread`/`fwrite`
- Linear search for title/author, binary search for ISBN (keep sorted)

### Sample Menu
```
=== LIBRARY MANAGEMENT SYSTEM ===
1. Add Book
2. Display All Books
3. Search Books
4. Borrow Book
5. Return Book
6. Overdue Report
7. Delete Book
8. Statistics
9. Sort Books
10. Exit
Choice: _
```

### Grading Criteria
| Feature | Points |
|---------|--------|
| Struct definitions and proper data organization | 10 |
| Binary file I/O (save/load) | 15 |
| CRUD operations (add, display, borrow, return, delete) | 25 |
| Search functionality (multi-criteria) | 15 |
| Sorting implementation | 10 |
| Overdue detection with date calculations | 10 |
| Error handling and input validation | 10 |
| Code organization and readability | 5 |

---

## Project 2: Sorting Algorithm Visualizer

A console-based visualizer that shows how different sorting algorithms work step by step.

### Requirements

Display an array of integers as vertical bars using characters. Show each swap/compare visually.

```cpp
// Bar representation
void displayArray(int arr[], int size, int highlight1 = -1, int highlight2 = -1);
```

### Example Output
```
Sorting Algorithm Visualizer
Array: [5, 3, 8, 1, 9, 2, 7, 4, 6]

Before sorting:
 5 | #####
 3 | ###
 8 | ########
 1 | #
 9 | #########
 2 | ##
 7 | #######
 4 | ####
 6 | ######

Step 1: Comparing 5 and 3 -> swap!
 3 | ###  <--
 5 | #####  <--
 ...
```

### Algorithms to Implement
1. **Bubble Sort** - Show each adjacent comparison and swap
2. **Selection Sort** - Show minimum finding and final swap
3. **Insertion Sort** - Show element being inserted
4. **Merge Sort** - Show divide and merge steps
5. **Quick Sort** - Show pivot selection and partitioning

### Features
1. **Step Mode**: Press Enter to advance one step (pause between operations)
2. **Auto Mode**: Run full sort with adjustable speed (milliseconds between steps)
3. **Statistics**: Count comparisons, swaps, and time elapsed
4. **Random Array**: Generate random array of configurable size (10-100)
5. **Preset Arrays**: Sorted, reverse-sorted, nearly sorted, few unique
6. **Comparison Table**: After running all 5 algorithms, show:
```
Algorithm      Comparisons   Swaps    Time(ms)
Bubble         45            20       2.3
Selection      45            9        1.8
Insertion      25            10       1.2
Merge          24            0        0.9
Quick          20            8        0.7
```

### Grading Criteria
| Feature | Points |
|---------|--------|
| Visual display of array as bars | 15 |
| Bubble sort with visualization | 10 |
| Selection sort with visualization | 10 |
| Insertion sort with visualization | 10 |
| Merge sort with visualization | 20 |
| Quick sort with visualization | 20 |
| Step mode / Auto mode | 5 |
| Statistics tracking (comparisons, swaps, time) | 5 |
| Algorithm comparison feature | 5 |

### Implementation Notes
- Use `system("cls")` on Windows or `system("clear")` on Linux to clear screen between steps
- Use `<chrono>` or `<ctime>` for timing
- Use `<thread>` and `<chrono>` for delays: `std::this_thread::sleep_for(std::chrono::milliseconds(ms));`
- Max array size of 50 for visual clarity (bars get too wide otherwise)
- Normalize bar heights to fit within 20 rows

### Starter Code (Bar Display)
```cpp
void displayArray(int arr[], int size, int h1, int h2) {
    // Find max for scaling
    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > maxVal) maxVal = arr[i];

    // Scale factor: max 20 rows
    double scale = 20.0 / maxVal;

    // Print bars top-to-bottom
    for (int row = 20; row >= 1; row--) {
        int threshold = (int)(row / scale);
        for (int i = 0; i < size; i++) {
            if (arr[i] >= threshold) {
                if (i == h1 || i == h2)
                    std::cout << " # ";  // Highlighted
                else
                    std::cout << " # ";
            } else {
                std::cout << "   ";
            }
        }
        std::cout << std::endl;
    }

    // Print separator
    for (int i = 0; i < size; i++)
        std::cout << "---";
    std::cout << std::endl;

    // Print values
    for (int i = 0; i < size; i++)
        std::cout << std::setw(3) << arr[i];
    std::cout << std::endl;
}
```

---

## Submission Requirements

For each project, submit:
- Source code (.cpp and .h files)
- Brief README explaining compilation and usage
- Sample input/output screenshots (optional)
- Self-assessment against the grading rubric

Both projects must compile without warnings using: `g++ -Wall -std=c++17 project.cpp -o project`