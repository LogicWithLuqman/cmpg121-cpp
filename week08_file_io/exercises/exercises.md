# Week 8 Exercises: File I/O

## Exercise 1: CSV Grade Book
Given a CSV file `grades.csv`:
```
StudentID,Name,Assignment1,Assignment2,Exam
101,Alice,85,90,78
102,Bob,70,75,82
103,Charlie,95,88,91
104,Diana,60,65,58
```
Write a program that:
1. Reads the CSV and calculates final mark (A1=30%, A2=30%, Exam=40%)
2. Assigns grade (A>=80, B>=70, C>=60, D>=50, F<50)
3. Writes a new file `results.csv`:
```
StudentID,Name,FinalMark,Grade
101,Alice,83.4,B
...
```
4. Prints class average to console

---

## Exercise 2: Binary Record Manager
```cpp
struct Record {
    int id;
    char name[50];
    double balance;
};
```
Create a menu-driven banking system that stores records in `accounts.bin`:
1. **Add**: Append new record at end
2. **Display**: Show all records
3. **Search by ID**: Use random access (seek to `id * sizeof(Record)`)
4. **Update**: Modify balance for a given ID
5. **Delete**: Mark record as deleted (set id = -1) — no actual removal
6. **Exit**

---

## Exercise 3: File Copy Utility
Write a program that:
1. Asks for source and destination filenames
2. Copies the file byte-by-byte
3. Reports: source size, bytes copied, and if checksums match
4. Works with ANY file type (text, binary, image)

**Challenge**: Implement a progress indicator.

---

## Exercise 4: Word Count
Write a program that reads a text file and reports:
- Total lines
- Total words
- Total characters (with and without spaces)
- Longest line length
- Most frequently used word

Test on a sample text file.

---

## Exercise 5: Config File Parser
Parse a configuration file `config.ini`:
```
# Server Configuration
server_name=MyServer
port=8080
max_connections=100
debug_mode=true

# Database
db_host=localhost
db_name=students
db_user=admin
```
Create a struct:
```cpp
struct ConfigEntry {
    char key[50];
    char value[100];
};
```
Functions:
- `int parseConfig(const char* filename, ConfigEntry* entries, int maxSize)`
- `const char* getValue(const ConfigEntry* entries, int count, const char* key)`

Ignore comments (#) and blank lines. Trim whitespace around values.

---

## Exercise 6: Merge Sorted Files
Given two sorted text files (each containing one integer per line), merge them into a third sorted file.

```
file1.txt:     file2.txt:     merged.txt:
1              2              1
4              3              2
6              5              3
8              7              4
10             9              5
                              6
                              7
                              8
                              9
                              10
```

---

## Exercise 7: Student Object Serialization
Implement a full binary serialization system:
```cpp
struct Course {
    char code[10];
    char name[50];
    int credits;
};

struct Student {
    int id;
    char name[50];
    Course courses[10];
    int courseCount;
};
```
- `void saveStudent(const Student* s, const char* filename)`
- `void loadStudent(Student* s, const char* filename)`
- Test: Create a student with 3 courses, save, load, and verify data integrity by comparing all fields.

---

## Exercise 8: Log File Analyzer
Parse a server log file `server.log`:
```
2024-01-15 10:30:45 [INFO] Server started
2024-01-15 10:31:02 [WARN] Memory usage high: 85%
2024-01-15 10:32:10 [ERROR] Connection timeout: 192.168.1.1
2024-01-15 10:33:00 [INFO] Request received: /api/users
```
Report:
- Total entries
- Count by log level (INFO, WARN, ERROR)
- Most common error message
- Entries between two timestamps (user input)

---

## Solutions

### Exercise 1 Solution
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

struct GradeRecord {
    int id;
    std::string name;
    double a1, a2, exam;
    double finalMark;
    char grade;
};

char calcGrade(double mark) {
    if (mark >= 80) return 'A';
    if (mark >= 70) return 'B';
    if (mark >= 60) return 'C';
    if (mark >= 50) return 'D';
    return 'F';
}

int main() {
    std::ifstream in("grades.csv");
    std::ofstream out("results.csv");

    if (!in || !out) {
        std::cerr << "File error!\n";
        return 1;
    }

    std::string header;
    std::getline(in, header);
    out << "StudentID,Name,FinalMark,Grade\n";

    std::string line;
    double totalSum = 0;
    int count = 0;

    while (std::getline(in, line)) {
        std::stringstream ss(line);
        GradeRecord r;
        char comma;

        ss >> r.id >> comma;
        std::getline(ss, r.name, ',');
        ss >> r.a1 >> comma >> r.a2 >> comma >> r.exam;

        r.finalMark = r.a1 * 0.3 + r.a2 * 0.3 + r.exam * 0.4;
        r.grade = calcGrade(r.finalMark);

        out << r.id << "," << r.name << ","
            << std::fixed << std::setprecision(1) << r.finalMark << ","
            << r.grade << std::endl;

        totalSum += r.finalMark;
        count++;
    }

    in.close();
    out.close();

    if (count > 0)
        std::cout << "Class average: " << totalSum / count << std::endl;

    return 0;
}
```

### Exercise 3 Solution
```cpp
#include <cstdio>

bool copyFile(const char* src, const char* dest) {
    FILE* source = fopen(src, "rb");
    FILE* destF = fopen(dest, "wb");

    if (!source || !destF) {
        if (source) fclose(source);
        if (destF) fclose(destF);
        return false;
    }

    // Get source size
    fseek(source, 0, SEEK_END);
    long totalSize = ftell(source);
    rewind(source);

    char buffer[8192];
    long totalCopied = 0;
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytesRead, destF);
        totalCopied += bytesRead;

        // Progress (no carriage return needed in terminal)
        int percent = (int)((double)totalCopied / totalSize * 100);
        printf("\rProgress: %d%%", percent);
        fflush(stdout);
    }
    printf("\n");

    fclose(source);
    fclose(destF);
    return totalCopied == totalSize;
}
```

### Exercise 6 Solution
```cpp
#include <iostream>
#include <fstream>

void mergeFiles(const char* f1, const char* f2, const char* output) {
    std::ifstream in1(f1), in2(f2);
    std::ofstream out(output);

    int val1, val2;
    bool has1 = (bool)(in1 >> val1);
    bool has2 = (bool)(in2 >> val2);

    while (has1 && has2) {
        if (val1 <= val2) {
            out << val1 << std::endl;
            has1 = (bool)(in1 >> val1);
        } else {
            out << val2 << std::endl;
            has2 = (bool)(in2 >> val2);
        }
    }

    while (has1) { out << val1 << std::endl; has1 = (bool)(in1 >> val1); }
    while (has2) { out << val2 << std::endl; has2 = (bool)(in2 >> val2); }

    in1.close(); in2.close(); out.close();
}
```