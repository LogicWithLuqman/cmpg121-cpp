# Week 5: Strings & Structs

## Part 1: Strings

C++ has two ways to handle strings. You MUST know both for CMPG121.

### C-Style Strings (Character Arrays)
```cpp
char str1[] = "Hello";     // Array: {'H','e','l','l','o','\0'}
char str2[20] = "World";   // Fixed size, safer
const char* str3 = "Text"; // String literal (read-only)

// Key functions from <cstring>
#include <cstring>
strlen(str);                // Length (excluding \0)
strcpy(dest, src);         // Copy string
strcat(dest, src);         // Concatenate
strcmp(a, b);              // Compare (0 if equal, <0 if a<b, >0 if a>b)
strchr(str, ch);           // Find first occurrence of char
strstr(str, sub);          // Find substring
```

### C++ std::string (Recommended)
```cpp
#include <string>
std::string s1 = "Hello";
std::string s2 = "World";

s1.length();             // or .size()
s1 + " " + s2;           // Concatenation: "Hello World"
s1 == s2;                // Comparison (==, !=, <, >, <=, >=)
s1.find("ell");          // Find substring (returns index or npos)
s1.substr(1, 3);         // Extract "ell" (pos, length)
s1.insert(5, "!!");      // Insert at position
s1.erase(5, 2);          // Erase 2 chars at pos 5
s1.replace(0, 5, "Hi");  // Replace "Hello" with "Hi"
s1.c_str();              // Convert to const char* (for C functions)
```

## Part 2: Structs

A `struct` groups related data of different types into a single unit.

```cpp
struct Student {
    int studentNumber;
    std::string name;
    double marks[5];
    char grade;
    bool isActive;
};

// Usage
Student s1;                    // Declare
s1.studentNumber = 12345;      // Access via dot operator
s1.name = "Alice";
s1.marks[0] = 85.0;

// Aggregate initialization (C++11)
Student s2 = {54321, "Bob", {70, 80, 90, 85, 75}, 'B', true};

// Init with designated initializers (C++20)
Student s3 = {.studentNumber = 11111, .name = "Charlie", .isActive = true};
```

### Structs with Functions
```cpp
// Pass by value (copy)
void printStudent(Student s) {
    std::cout << s.name << " (" << s.studentNumber << ")" << std::endl;
}

// Pass by reference (efficient, modifiable)
void updateMarks(Student &s, double newMarks[]) {
    for (int i = 0; i < 5; i++) s.marks[i] = newMarks[i];
}

// Return a struct
Student createStudent(int num, std::string name) {
    Student s;
    s.studentNumber = num;
    s.name = name;
    return s;
}
```

### Arrays of Structs
```cpp
Student classroom[30];               // Array of 30 students
Student lab[] = {s1, s2, s3};        // Initialize array of structs

// Traverse
for (int i = 0; i < 3; i++) {
    std::cout << lab[i].name << std::endl;
}
```

### Nested Structs
```cpp
struct Date {
    int day, month, year;
};

struct Enrolment {
    Student student;
    Date enrolmentDate;
    std::string courseCode;
};

Enrolment e = {s1, {15, 7, 2024}, "CMPG121"};
std::cout << e.student.name << " enrolled on "
          << e.enrolmentDate.day << "/"
          << e.enrolmentDate.month << "/"
          << e.enrolmentDate.year << std::endl;
```

### Typedef and Using
```cpp
typedef struct { int x; int y; } Point;   // C-style
using Point = struct { int x; int y; };   // C++11 (preferred)
```

---
## Exercises

1. **String Reverser**: Take a sentence input. Reverse each word individually (not the whole sentence). E.g., "Hello World" → "olleH dlroW".
2. **Student Database**: Array of 5 `Student` structs. Input data. Calculate average mark per student. Print students sorted by average.
3. **Date Calculator**: Create `Date` struct. Function `daysBetween(Date d1, Date d2)` returns number of days. Function `addDays(Date d, int n)` returns new Date.
4. **Book Library**: Struct `Book` (title, author, ISBN, year, isBorrowed, borrowerName). Array of books. Functions: add, search by title, borrow/return, display available.
5. **Palindromes**: Read strings until "quit". For each, check if palindrome (ignore spaces/case). Use `std::string` functions.