# Week 1 Exercises: C++ Basics

## Exercise 1: The Greeting
Write a program that:
1. Asks the user for their name (string)
2. Asks for their student number (int)
3. Prints: "Welcome [name], Student #: [number]"

**Expected Output:**
```
Enter name: Alice
Enter student number: 12345
Welcome Alice, Student #: 12345
```

---

## Exercise 2: Simple Calculator
Create a program that:
1. Takes two `double` numbers as input
2. Calculates and prints:
   - Sum
   - Difference (first - second)
   - Product
   - Quotient (first / second) - *check for division by zero!*

---

## Exercise 3: Temperature Converter
Write a program that converts Celsius to Fahrenheit.
Formula: `F = (C * 9/5) + 32`

Input: Celsius (double)
Output: Fahrenheit (double, formatted to 2 decimal places)

**Hint:** Use `<iomanip>` and `std::fixed << std::setprecision(2)`

---

## Exercise 4: Type Explorer
Create variables for each of the following types and print them:
1. `int` - your age
2. `double` - your height
3. `char` - your first initial
4. `bool` - are you a student? (true/false)
5. `std::string` - your degree name

Print each variable with a descriptive label.

---

## Exercise 5: Fix the Code (Debugging)
The following code has **5 errors**. Fix them:

```cpp
#include <iostream>

main() {
    int x = 10
    int y = 5;
    cout << "Sum: " << x + y << endl;
    return 0
}
```

**Errors to find:**
1. Missing return type for main
2. Missing semicolon
3. Missing namespace for cout/endl
4. Missing semicolon at return
5. Missing include for iostream (actually included, but check syntax)

---

## Solutions

### Exercise 1 Solution
```cpp
#include <iostream>
#include <string>

int main() {
    std::string name;
    int studentNum;

    std::cout << "Enter name: ";
    std::getline(std::cin, name);

    std::cout << "Enter student number: ";
    std::cin >> studentNum;

    std::cout << "Welcome " << name << ", Student #: " << studentNum << std::endl;

    return 0;
}
```

### Exercise 2 Solution
```cpp
#include <iostream>

int main() {
    double a, b;
    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Enter second number: ";
    std::cin >> b;

    std::cout << "Sum: " << a + b << std::endl;
    std::cout << "Difference: " << a - b << std::endl;
    std::cout << "Product: " << a * b << std::endl;

    if (b != 0) {
        std::cout << "Quotient: " << a / b << std::endl;
    } else {
        std::cout << "Quotient: Undefined (division by zero)" << std::endl;
    }

    return 0;
}
```

### Exercise 3 Solution
```cpp
#include <iostream>
#include <iomanip>

int main() {
    double celsius;
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;

    double fahrenheit = (celsius * 9.0 / 5.0) + 32;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << celsius << "C = " << fahrenheit << "F" << std::endl;

    return 0;
}
```

### Exercise 5 Solution
```cpp
#include <iostream>

int main() {
    int x = 10;           // Missing semicolon added
    int y = 5;
    std::cout << "Sum: " << x + y << std::endl;  // Added std::
    return 0;             // Added semicolon
}
```