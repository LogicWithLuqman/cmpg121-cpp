# Week 5 Exercises: Strings & Structs

## Exercise 1: Word Reverser
Write a program that reads a sentence and reverses each word individually.
```cpp
Input:  "Hello World from C++"
Output: "olleR dlroW morf ++C"
```
**Requirements**:
- Use `std::string`
- Words separated by single spaces
- No extra libraries, just `<string>` and `<iostream>`

---

## Exercise 2: Student Database System
Create a student database using an array of `Student` structs:
```cpp
struct Student {
    int id;
    std::string name;
    double marks[4]; // 4 assessments
    double finalMark;
    char grade;
};
```
Functions to implement:
1. `void inputStudents(Student arr[], int count)` - Input all data
2. `void calculateResults(Student arr[], int count)` - Final mark = average of 4
3. `void printStudent(const Student& s)` - Print one student row
4. `void displayAll(const Student arr[], int count)` - Table format
5. `void sortByFinalMark(Student arr[], int count)` - Descending
6. `Student* findByName(Student arr[], int count, std::string name)` - Return pointer or nullptr

**Menu**: 1=Input, 2=Display, 3=Sort, 4=Search, 5=Exit

---

## Exercise 3: Date Calculator Library
```cpp
struct Date {
    int day, month, year;
};
```
Implement:
```cpp
bool isLeapYear(int year);
int daysInMonth(int month, int year);
Date createDate(int d, int m, int y);
void printDate(const Date& d);
bool isValidDate(const Date& d);
int dayOfYear(const Date& d);          // Day number within the year
int daysBetween(Date d1, Date d2);     // Days between two dates
Date addDays(Date d, int n);           // Add n days to a date
std::string dayOfWeek(const Date& d);  // "Monday", "Tuesday", etc.
```

**Test**: Calculate how many days until your next birthday.

---

## Exercise 4: Book Library Manager
```cpp
struct Book {
    std::string title;
    std::string author;
    std::string isbn;
    int year;
    bool isBorrowed;
    std::string borrowerName;
    Date borrowDate;  // Reuse Date struct
};
```
Library with max 100 books. Functions:
- `void addBook(Book lib[], int& count)` - Add new book
- `void displayAll(const Book lib[], int count)` - All books
- `void displayAvailable(const Book lib[], int count)` - Only not borrowed
- `int searchByTitle(const Book lib[], int count, std::string title)` - Return index or -1
- `int searchByISBN(const Book lib[], int count, std::string isbn)` - Return index or -1
- `bool borrowBook(Book lib[], int count, std::string isbn, std::string borrower, Date date)`
- `bool returnBook(Book lib[], int count, std::string isbn)`
- `void displayOverdue(const Book lib[], int count, Date currentDate)` - Overdue = >14 days

---

## Exercise 5: Palindrome Checker
Read strings until "quit". For each:
```cpp
Input:  "A man a plan a canal Panama"
Output: Palindrome: Yes

Input:  "C++ is fun"
Output: Palindrome: No
```
Rules:
- Ignore spaces, punctuation, and case
- Use only `std::string` functions
- Write `bool isPalindrome(const std::string& s)`

---

## Exercise 6: Text Analyzer
Read a paragraph of text. Produce:
- Word count
- Character count (total, excluding spaces)
- Most frequent word
- Longest word
- Shortest word
- Average word length

Use an array of structs to track word frequencies:
```cpp
struct WordFreq {
    std::string word;
    int count;
};
```

---

## Exercise 7: Morse Code Converter
```cpp
struct MorseCode {
    char letter;
    std::string code;
};
```
Create a lookup table (array of `MorseCode`) for A-Z and 0-9.
Write functions:
- `std::string toMorse(const std::string& text)` - Convert to Morse
- `std::string fromMorse(const std::string& morse)` - Convert back

---

## Solutions

### Exercise 1 Solution
```cpp
#include <iostream>
#include <string>

std::string reverseWord(const std::string& word) {
    std::string reversed = word;
    int i = 0, j = reversed.length() - 1;
    while (i < j) {
        std::swap(reversed[i], reversed[j]);
        i++; j--;
    }
    return reversed;
}

int main() {
    std::string sentence;
    std::cout << "Enter sentence: ";
    std::getline(std::cin, sentence);

    std::string word, result;
    for (char c : sentence) {
        if (c == ' ') {
            result += reverseWord(word) + " ";
            word.clear();
        } else {
            word += c;
        }
    }
    result += reverseWord(word); // Last word

    std::cout << "Result: " << result << std::endl;
    return 0;
}
```

### Exercise 5 Solution
```cpp
#include <iostream>
#include <string>
#include <cctype>

bool isPalindrome(const std::string& s) {
    std::string cleaned;
    for (char c : s) {
        if (std::isalnum(c))
            cleaned += std::tolower(c);
    }

    int i = 0, j = cleaned.length() - 1;
    while (i < j) {
        if (cleaned[i] != cleaned[j]) return false;
        i++; j--;
    }
    return true;
}

int main() {
    std::string input;
    while (true) {
        std::cout << "Enter text (or 'quit'): ";
        std::getline(std::cin, input);
        if (input == "quit") break;
        std::cout << "Palindrome: " << (isPalindrome(input) ? "Yes" : "No") << std::endl;
    }
    return 0;
}
```

### Exercise 3 - Day of Week (Zeller's Congruence)
```cpp
std::string dayOfWeek(const Date& d) {
    static const char* days[] = {
        "Saturday", "Sunday", "Monday", "Tuesday",
        "Wednesday", "Thursday", "Friday"
    };
    int q = d.day;
    int m = (d.month < 3) ? d.month + 12 : d.month;
    int k = d.year % 100;
    int j = d.year / 100;
    if (d.month < 3) k--;
    int h = (q + 13*(m+1)/5 + k + k/4 + j/4 + 5*j) % 7;
    return days[h];
}
```