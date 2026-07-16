#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <algorithm>

// ============================================
// STRUCT DEFINITIONS
// ============================================

struct Date {
    int day, month, year;
};

struct Student {
    int studentNumber;
    std::string name;
    double marks[5];
    double average;
    char grade;
};

struct Book {
    std::string title;
    std::string author;
    std::string isbn;
    int year;
    bool isBorrowed;
    std::string borrowerName;
};

// ============================================
// STRING EXAMPLES
// ============================================

void cStringExamples() {
    std::cout << "=== C-Style Strings ===\n";

    char str1[] = "Hello";
    char str2[20] = "World";

    std::cout << "str1: " << str1 << " (length: " << strlen(str1) << ")\n";
    std::cout << "str2: " << str2 << " (length: " << strlen(str2) << ")\n";

    // Concatenate
    char result[50];
    strcpy(result, str1);
    strcat(result, " ");
    strcat(result, str2);
    std::cout << "strcat result: " << result << std::endl;

    // Compare
    if (strcmp(str1, str2) == 0)
        std::cout << "Strings are equal\n";
    else if (strcmp(str1, str2) < 0)
        std::cout << "str1 < str2\n";
    else
        std::cout << "str1 > str2\n";

    // Find character
    char* pos = strchr(result, 'W');
    if (pos) std::cout << "Found 'W' at index " << (pos - result) << std::endl;
}

void stdStringExamples() {
    std::cout << "\n=== C++ std::string ===\n";

    std::string s1 = "Hello";
    std::string s2 = "World";

    // Concatenation
    std::string s3 = s1 + " " + s2;
    std::cout << "Concatenated: " << s3 << std::endl;
    std::cout << "Length: " << s3.length() << std::endl;

    // Access
    std::cout << "First char: " << s3[0] << std::endl;
    std::cout << "Last char: " << s3[s3.length() - 1] << std::endl;

    // Find
    size_t found = s3.find("World");
    if (found != std::string::npos)
        std::cout << "\"World\" found at index " << found << std::endl;

    // Substring
    std::string sub = s3.substr(6, 5);
    std::cout << "Substring (6,5): " << sub << std::endl;

    // Replace
    std::string s4 = s3;
    s4.replace(0, 5, "Hi");
    std::cout << "After replace: " << s4 << std::endl;

    // Insert & erase
    s4.insert(3, " there");
    std::cout << "After insert: " << s4 << std::endl;
    s4.erase(3, 6);
    std::cout << "After erase: " << s4 << std::endl;

    // Convert to C-string
    const char* cstr = s3.c_str();
    std::cout << "As C-string: " << cstr << std::endl;

    // Iterate
    std::cout << "Characters: ";
    for (char c : s3) std::cout << c << " ";
    std::cout << std::endl;
}

// ============================================
// STRUCT EXAMPLES
// ============================================

double calculateAverage(double marks[], int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) sum += marks[i];
    return sum / count;
}

void printStudent(const Student& s) {
    std::cout << std::left << std::setw(10) << s.studentNumber
              << std::setw(20) << s.name
              << std::setw(8) << std::fixed << std::setprecision(1) << s.average
              << s.grade << std::endl;
}

char determineGrade(double avg) {
    if (avg >= 90) return 'A';
    if (avg >= 80) return 'B';
    if (avg >= 70) return 'C';
    if (avg >= 60) return 'D';
    return 'F';
}

void studentExamples() {
    std::cout << "\n=== Struct: Students ===\n";

    const int NUM_STUDENTS = 3;
    Student students[NUM_STUDENTS];

    // Input
    for (int i = 0; i < NUM_STUDENTS; i++) {
        std::cout << "Enter student " << i + 1 << " number: ";
        std::cin >> students[i].studentNumber;
        std::cin.ignore(); // Clear buffer
        std::cout << "Enter name: ";
        std::getline(std::cin, students[i].name);

        std::cout << "Enter 5 marks: ";
        for (int j = 0; j < 5; j++)
            std::cin >> students[i].marks[j];

        students[i].average = calculateAverage(students[i].marks, 5);
        students[i].grade = determineGrade(students[i].average);
    }

    // Display header
    std::cout << "\nStudent Records:\n";
    std::cout << std::left << std::setw(10) << "Number"
              << std::setw(20) << "Name"
              << std::setw(8) << "Average"
              << "Grade\n";
    std::cout << std::string(45, '-') << std::endl;

    for (int i = 0; i < NUM_STUDENTS; i++)
        printStudent(students[i]);
}

// ============================================
// NESTED STRUCTS
// ============================================

void nestedStructExamples() {
    std::cout << "\n=== Nested Structs ===\n";

    struct Enrolment {
        Student student;
        Date enrolmentDate;
        std::string courseCode;
    };

    Student s = {12345, "Alice", {85, 90, 78, 92, 88}, 86.6, 'B'};
    Enrolment e = {s, {12, 2, 2024}, "CMPG121"};

    std::cout << e.student.name << " enrolled in "
              << e.courseCode << " on "
              << e.enrolmentDate.day << "/"
              << e.enrolmentDate.month << "/"
              << e.enrolmentDate.year << std::endl;
}

// ============================================
// ARRAYS OF STRUCTS + SORTING
// ============================================

bool compareByName(const Student& a, const Student& b) {
    return a.name < b.name;
}

void sortStudents() {
    std::cout << "\n=== Sorting Structs ===\n";

    Student classList[4] = {
        {54321, "Xavier", {70, 75, 72, 78, 80}},
        {11111, "Alice",  {90, 88, 92, 85, 95}},
        {22222, "Bob",    {65, 70, 68, 72, 60}},
        {33333, "Charlie",{80, 82, 78, 85, 88}}
    };

    for (int i = 0; i < 4; i++) {
        classList[i].average = calculateAverage(classList[i].marks, 5);
        classList[i].grade = determineGrade(classList[i].average);
    }

    std::cout << "Before sorting:\n";
    for (int i = 0; i < 4; i++) printStudent(classList[i]);

    std::sort(classList, classList + 4, compareByName);

    std::cout << "After sorting by name:\n";
    for (int i = 0; i < 4; i++) printStudent(classList[i]);
}

// ============================================
// MAIN
// ============================================

int main() {
    cStringExamples();
    stdStringExamples();
    studentExamples();
    nestedStructExamples();
    sortStudents();

    return 0;
}