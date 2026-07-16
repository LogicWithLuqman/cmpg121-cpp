#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>   // For C-style file I/O
#include <cstring>

// ============================================
// 1. TEXT FILE WRITING
// ============================================

void writeTextFile() {
    std::cout << "=== Text File Writing ===\n";

    std::ofstream out("students.txt");
    if (!out) {
        std::cerr << "Failed to create file!\n";
        return;
    }

    out << "ID,Name,Mark,Grade\n";
    out << 101 << "," << "Alice" << "," << 85 << "," << 'B' << std::endl;
    out << 102 << "," << "Bob" << "," << 92 << "," << 'A' << std::endl;
    out << 103 << "," << "Charlie" << "," << 76 << "," << 'C' << std::endl;

    out.close();
    std::cout << "Written students.txt\n";
}

// ============================================
// 2. TEXT FILE READING
// ============================================

void readTextFile() {
    std::cout << "\n=== Text File Reading ===\n";

    std::ifstream in("students.txt");
    if (!in) {
        std::cerr << "Failed to open file!\n";
        return;
    }

    std::string line;
    int lineNum = 0;
    while (std::getline(in, line)) {
        std::cout << "Line " << lineNum++ << ": " << line << std::endl;
    }
    in.close();
}

// ============================================
// 3. STRUCT TO/FROM TEXT FILE
// ============================================

struct Student {
    int id;
    char name[50];
    double marks[4];
    double average;
};

void writeStudentsText(const Student* students, int count, const char* filename) {
    std::ofstream out(filename);
    if (!out) return;

    // Header
    out << "ID,Name,Mark1,Mark2,Mark3,Mark4,Average\n";

    for (int i = 0; i < count; i++) {
        out << students[i].id << ","
            << students[i].name << ","
            << students[i].marks[0] << ","
            << students[i].marks[1] << ","
            << students[i].marks[2] << ","
            << students[i].marks[3] << ","
            << students[i].average << std::endl;
    }
    out.close();
    std::cout << "Written " << count << " students to " << filename << std::endl;
}

int readStudentsText(Student* students, int maxCount, const char* filename) {
    std::ifstream in(filename);
    if (!in) return 0;

    std::string header;
    std::getline(in, header); // Skip header

    int count = 0;
    std::string line;
    while (std::getline(in, line) && count < maxCount) {
        // Simple CSV parsing
        char comma;
        // Using C-style for simplicity
        Student s;
        sscanf(line.c_str(), "%d,%49[^,],%lf,%lf,%lf,%lf,%lf",
               &s.id, s.name,
               &s.marks[0], &s.marks[1], &s.marks[2], &s.marks[3],
               &s.average);
        students[count++] = s;
    }
    in.close();
    return count;
}

// ============================================
// 4. BINARY FILE I/O (C-style)
// ============================================

void writeBinaryFile() {
    std::cout << "\n=== Binary File Writing ===\n";

    Student students[] = {
        {101, "Alice",  {85, 90, 78, 92}, 86.25},
        {102, "Bob",    {70, 75, 80, 72}, 74.25},
        {103, "Charlie",{95, 88, 91, 87}, 90.25}
    };

    FILE* file = fopen("students.bin", "wb");
    if (!file) {
        std::cerr << "Failed to create binary file!\n";
        return;
    }

    fwrite(students, sizeof(Student), 3, file);
    fclose(file);
    std::cout << "Written 3 students to students.bin (" << 3 * sizeof(Student) << " bytes)\n";
}

void readBinaryFile() {
    std::cout << "\n=== Binary File Reading ===\n";

    FILE* file = fopen("students.bin", "rb");
    if (!file) {
        std::cerr << "Failed to open binary file!\n";
        return;
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    int count = fileSize / sizeof(Student);
    rewind(file); // Back to start

    Student* students = new Student[count];
    fread(students, sizeof(Student), count, file);
    fclose(file);

    std::cout << "Read " << count << " records:\n";
    for (int i = 0; i < count; i++) {
        std::cout << "ID: " << students[i].id
                  << ", Name: " << students[i].name
                  << ", Avg: " << students[i].average << std::endl;
    }
    delete[] students;
}

// ============================================
// 5. RANDOM ACCESS (Binary)
// ============================================

void randomAccessDemo() {
    std::cout << "\n=== Random Access ===\n";

    FILE* file = fopen("students.bin", "rb");
    if (!file) return;

    // Seek to record #2 (0-indexed)
    int recordNum = 1;
    Student s;
    fseek(file, recordNum * sizeof(Student), SEEK_SET);
    fread(&s, sizeof(Student), 1, file);
    std::cout << "Record " << recordNum << ": " << s.name
              << " (ID: " << s.id << ")\n";

    // Seek to last record
    fseek(file, -sizeof(Student), SEEK_END);
    fread(&s, sizeof(Student), 1, file);
    std::cout << "Last record: " << s.name
              << " (ID: " << s.id << ")\n";

    fclose(file);
}

// ============================================
// 6. FILE COPY (any format)
// ============================================

bool copyFile(const char* src, const char* dest) {
    FILE* source = fopen(src, "rb");
    FILE* destination = fopen(dest, "wb");

    if (!source || !destination) {
        if (source) fclose(source);
        if (destination) fclose(destination);
        return false;
    }

    char buffer[4096];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytesRead, destination);
    }

    fclose(source);
    fclose(destination);
    return true;
}

void fileCopyDemo() {
    std::cout << "\n=== File Copy ===\n";
    if (copyFile("students.bin", "students_backup.bin"))
        std::cout << "File copied successfully!\n";
    else
        std::cerr << "Copy failed!\n";
}

// ============================================
// 7. ERROR HANDLING
// ============================================

void errorHandlingDemo() {
    std::cout << "\n=== Error Handling ===\n";

    // Try opening non-existent file
    std::ifstream in("nonexistent.txt");

    if (in.fail()) {
        std::cout << "State: failbit = " << in.fail()
                  << ", badbit = " << in.bad()
                  << ", eofbit = " << in.eof() << std::endl;
    }

    // Clear and try again
    in.clear();

    // C-style error
    FILE* f = fopen("nonexistent.dat", "rb");
    if (!f) {
        std::cout << "C-style error: " << strerror(errno) << std::endl;
    }
}

// ============================================
// MAIN
// ============================================

int main() {
    writeTextFile();
    readTextFile();

    // Demo struct I/O
    Student testStudents[] = {
        {201, "David",  {88, 76, 95, 82}, 85.25},
        {202, "Eve",    {91, 93, 89, 94}, 91.75}
    };
    writeStudentsText(testStudents, 2, "test_students.csv");

    Student readStudents[10];
    int count = readStudentsText(readStudents, 10, "test_students.csv");
    std::cout << "Read back " << count << " students from CSV\n";

    // Binary operations
    writeBinaryFile();
    readBinaryFile();
    randomAccessDemo();
    fileCopyDemo();
    errorHandlingDemo();

    return 0;
}