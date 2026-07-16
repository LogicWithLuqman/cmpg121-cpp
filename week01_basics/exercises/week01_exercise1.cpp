#include <iostream>
#include <string>

int main()
{
    std::string name;
    int studentNum;

    // 1. Ask user for their name
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // 2. Ask for their student number
    std::cout << "Enter your student number: ";
    std::cin >> studentNum;

    // 3. Print the welcome message
    std::cout << "Welcome " << name << ", Student #: " << studentNum << std::endl;

    return 0;
}
