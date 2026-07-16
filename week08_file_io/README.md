# Week 8: File I/O

File handling allows your program to persist data beyond runtime. Two main types: **text files** (human-readable) and **binary files** (efficient, compact).

## 1. C++ File Streams (`<fstream>`)

```cpp
#include <fstream>

std::ofstream outFile;  // Output (write)
std::ifstream inFile;   // Input (read)
std::fstream ioFile;    // Both (read + write)
```

### Opening Files
```cpp
outFile.open("data.txt");         // Default: truncate (overwrite)
outFile.open("data.txt", std::ios::app);  // Append mode

if (!outFile.is_open()) {
    std::cerr << "Failed to open file!" << std::endl;
}
```

## 2. Writing to Text Files
```cpp
std::ofstream out("students.txt");
if (out.is_open()) {
    out << "Name,Age,Grade" << std::endl;
    out << "Alice,20,A" << std::endl;
    out << "Bob,19,B" << std::endl;
    out.close(); // Always close!
}
```

## 3. Reading from Text Files
```cpp
std::ifstream in("students.txt");
std::string line;

// Read line by line
while (std::getline(in, line)) {
    std::cout << line << std::endl;
}

// Read word by word
std::string word;
while (in >> word) {
    std::cout << word << std::endl;
}
```

### Reading with error checking
```cpp
std::ifstream in("data.txt");
if (!in) {
    std::cerr << "Error opening file!" << std::endl;
    return 1;
}

int x;
while (in >> x) {  // Returns false when read fails (e.g., EOF)
    std::cout << x << " ";
}
```

## 4. File Open Modes

| Mode | Flag | Description |
|------|------|-------------|
| Read | `std::ios::in` | Open for reading |
| Write | `std::ios::out` | Open for writing (default truncate) |
| Append | `std::ios::app` | Write at end of file |
| Binary | `std::ios::binary` | Open in binary mode |
| Truncate | `std::ios::trunc` | Delete existing content |
| At end | `std::ios::ate` | Go to end after opening |

```cpp
std::fstream file("data.bin", std::ios::in | std::ios::out | std::ios::binary);
```

## 5. Binary Files (C-style)

Binary files store data in the same format as memory. Faster and more precise.

```cpp
#include <cstdio>

FILE* file = fopen("data.bin", "wb");  // Write binary

int numbers[] = {1, 2, 3, 4, 5};
fwrite(numbers, sizeof(int), 5, file); // Write 5 ints
fclose(file);

// Read
file = fopen("data.bin", "rb");
int buffer[5];
fread(buffer, sizeof(int), 5, file);
fclose(file);
```

### Writing Struct to Binary File
```cpp
struct Record {
    int id;
    char name[50];
    double salary;
};

Record r = {1, "Alice", 75000.0};
FILE* f = fopen("records.dat", "wb");
fwrite(&r, sizeof(Record), 1, f);
fclose(f);

// Read
Record r2;
f = fopen("records.dat", "rb");
fread(&r2, sizeof(Record), 1, f);
printf("ID: %d, Name: %s, Salary: %.2f\n", r2.id, r2.name, r2.salary);
fclose(f);
```

## 6. Sequential vs Random Access

```cpp
// File position
std::streampos pos = inFile.tellg();  // Get position (input)
outFile.tellp();                      // Get position (output)

inFile.seekg(0, std::ios::beg);       // Go to beginning
inFile.seekg(10, std::ios::cur);      // Skip 10 bytes from current
inFile.seekg(-5, std::ios::end);      // 5 bytes before end

// Binary: seek to specific record
int recordNum = 3;
fseek(file, recordNum * sizeof(Record), SEEK_SET);
fread(&r, sizeof(Record), 1, file);
```

## 7. C-style File I/O (`<cstdio>`)

| C++ Stream | C-style | Description |
|-----------|---------|-------------|
| `std::ifstream` | `fopen("r")` | Read |
| `std::ofstream` | `fopen("w")` | Write |
| `std::fstream` | `fopen("r+")` | Read+Write |
| `.close()` | `fclose()` | Close |
| `<<` | `fprintf()` | Formatted write |
| `>>` | `fscanf()` | Formatted read |
| `.read()` | `fread()` | Binary read |
| `.write()` | `fwrite()` | Binary write |

---
## Exercises

1. **CSV Parser**: Read CSV file with student data. Calculate and write summary.
2. **Binary Record Manager**: CRUD operations on binary file of records.
3. **File Copy**: Copy any file byte-by-byte (text or binary).
4. **Word Count**: Read text file, count words/lines/characters.
5. **Config File Parser**: Read `key=value` config file into struct array.