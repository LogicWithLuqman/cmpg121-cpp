#include <iostream>
#include <string>

int main(){

    int age;
    double height;
    char initial;
    std::string degree;

    std::cout << "How old are you: ";
    std::cin >> age;

    std::cout << "How tall are you (cm): ";
    std::cin >> height;

    std::cout << "What is your first inital (A-Z): ";
    std::cin >> initial;

    std::string input;
    std::cout << "Are you a student (yes/no): ";
    std::cin >> input;
    std::cin.ignore();
    bool student = (input == "yes");

    if (student == true){
    std::cout << "What degree are you studying: "
    ;
    std::getline(std::cin, degree);
    }else{
    std::cout << std::endl;
    }

    std::cout << "Your first initial is: " << initial << std::endl;
    std::cout << "You are " << height << " cm tall and are " << age << " years old" << std::endl;

    if(student == true){
    std::cout << "You are a student, currently studying "<< degree << std::endl;
    }else{
    std::cout << "You are not a student" << std::endl;}


return 0;
}
