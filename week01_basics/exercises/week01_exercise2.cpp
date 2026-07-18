#include <iostream>

int main(){

    double num1;
    double num2;

    std::cout << " Enter number 1: ";
    std::cin >> num1;

    std::cout << " Enter number 2: ";
    std::cin >> num2;

    std::cout << std::endl;

    std::cout << " Sum: " << num1 + num2 << std::endl;
    std::cout << " Difference: " << num1 - num2 << std::endl;
    std::cout << " Product: " << num1 * num2 << std::endl;

    if (num2 == 0){
        std::cout << " Error division by 0 not possible.";
    }else{
    std::cout << " Quotient: " << num1 / num2 << std::endl;}

return 0;
}
