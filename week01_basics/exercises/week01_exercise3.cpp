#include <iostream>
#include <iomanip>

int main(){

    double celsius;

    std::cout << "Enter the temperature in celsius: ";
    if (!(std::cin >> celsius)) {
        std::cerr << "Error: Invalid input." << std::endl;
        return 1;
    }

    double fahrenheit = (celsius * 9.0/5.0) +32;

    std::cout << std::fixed <<std::setprecision(2);
    std::cout << "Temperature in fahrenheit is: " << fahrenheit << std::endl;

return 0;
}
