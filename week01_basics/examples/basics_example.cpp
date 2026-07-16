#include <iostream>
#include <string>

int main() {
    // Variable declaration (MUST specify type in C++)
    std::string name;
    int age;
    double height;

    // Output to console
    std::cout << "--- Welcome to C++ ---" << std::endl;

    // Input from user
    std::cout << "Enter your name: ";
    std::getline(std::cin, name); // Use getline for strings with spaces

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Enter your height (m): ";
    std::cin >> height;

    // Output combined information
    std::cout << "\n--- Your Profile ---" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << " years" << std::endl;
    std::cout << "Height: " << height << "m" << std::endl;

    return 0;
}
