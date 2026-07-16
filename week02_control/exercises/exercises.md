# Week 2 Exercises: Control Structures

## Exercise 1: Grade Calculator (If-Else)
Write a program that:
1. Asks for 3 test marks (each out of 100)
2. Calculates the average
3. Outputs the letter grade based on average:
   - 90-100: A
   - 80-89: B
   - 70-79: C
   - 60-69: D
   - Below 60: F

**Challenge**: Validate that each mark is between 0-100.

---

## Exercise 2: Days in Month (Switch)
Write a program that:
1. Takes a month number (1-12) and a year
2. Uses a `switch` statement to print the number of days in that month
3. Handle February for leap years:
   - Leap year if: divisible by 4 AND (not divisible by 100 OR divisible by 400)

---

## Exercise 3: Number Guessing Game (Do-While)
Build a complete guessing game:
1. Generate random number 1-1000
2. Allow user max 10 attempts
3. After each guess, show "Higher", "Lower", or "Correct!"
4. If they run out of attempts, show the number
5. Ask if they want to play again (Y/N loop)

---

## Exercise 4: Pattern Printing (Nested Loops)
Print the following patterns using nested `for` loops:

**Pattern A:**
```
*
**
***
****
*****
```

**Pattern B:**
```
1
22
333
4444
55555
```

**Pattern C (Pyramid):**
```
    *
   ***
  *****
 *******
*********
```

---

## Exercise 5: Sum of Digits
Write a program that:
1. Takes an integer input (e.g., 12345)
2. Calculates the sum of its digits (1+2+3+4+5 = 15)
3. Uses a `while` loop

---

## Exercise 6: Rock Paper Scissors (Switch + Random)
Create a Rock-Paper-Scissors game:
1. User enters 1=Rock, 2=Paper, 3=Scissors
2. Computer randomly chooses
3. Use `switch` to determine winner
4. Keep score (Wins/Losses/Draws)
5. Play until user chooses to quit

---

## Exercise 7: Factorial Calculator
Calculate n! using a `for` loop.
Input: 5
Output: 5! = 120

**Challenge**: Handle large numbers using `unsigned long long` and detect overflow.

---

## Exercise 8: Multiplication Table
Print a formatted multiplication table 1-10:
```
   1  2  3  4  5 ...
1  1  2  3  4  5
2  2  4  6  8 10
...
```

Use `std::setw()` from `<iomanip>` for alignment.

---

## Solutions

### Exercise 1 Solution
```cpp
#include <iostream>

int main() {
    double m1, m2, m3;
    std::cout << "Enter 3 marks (0-100): ";
    std::cin >> m1 >> m2 >> m3;

    // Validation
    if (m1 < 0 || m1 > 100 || m2 < 0 || m2 > 100 || m3 < 0 || m3 > 100) {
        std::cout << "Invalid marks!" << std::endl;
        return 1;
    }

    double avg = (m1 + m2 + m3) / 3.0;

    if (avg >= 90) std::cout << "A";
    else if (avg >= 80) std::cout << "B";
    else if (avg >= 70) std::cout << "C";
    else if (avg >= 60) std::cout << "D";
    else std::cout << "F";

    std::cout << " (Average: " << avg << ")" << std::endl;
    return 0;
}
```

### Exercise 2 Solution
```cpp
#include <iostream>

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int month, year;
    std::cout << "Enter month (1-12): ";
    std::cin >> month;
    std::cout << "Enter year: ";
    std::cin >> year;

    int days;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days = 31; break;
        case 4: case 6: case 9: case 11:
            days = 30; break;
        case 2:
            days = isLeapYear(year) ? 29 : 28; break;
        default:
            std::cout << "Invalid month!" << std::endl;
            return 1;
    }
    std::cout << "Days: " << days << std::endl;
    return 0;
}
```

### Exercise 3 Solution
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    char playAgain = 'Y';

    do {
        int secret = std::rand() % 1000 + 1;
        int guess, attempts = 0;
        bool won = false;

        std::cout << "Guess the number (1-1000). Max 10 attempts.\n";

        do {
            std::cout << "Attempt " << attempts + 1 << ": ";
            std::cin >> guess;
            attempts++;

            if (guess == secret) {
                std::cout << "Correct! You won in " << attempts << " attempts!\n";
                won = true;
            } else if (guess < secret) {
                std::cout << "Higher!\n";
            } else {
                std::cout << "Lower!\n";
            }
        } while (attempts < 10 && !won);

        if (!won) {
            std::cout << "Out of attempts! Number was " << secret << "\n";
        }

        std::cout << "Play again? (Y/N): ";
        std::cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    return 0;
}
```

### Exercise 4 Solution (Pattern C - Pyramid)
```cpp
#include <iostream>

int main() {
    int rows = 5;

    for (int i = 1; i <= rows; i++) {
        // Print spaces
        for (int j = 1; j <= rows - i; j++) {
            std::cout << " ";
        }
        // Print stars
        for (int k = 1; k <= 2 * i - 1; k++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    return 0;
}
```

### Exercise 5 Solution
```cpp
#include <iostream>

int main() {
    int num, sum = 0;
    std::cout << "Enter number: ";
    std::cin >> num;

    int original = num;
    while (num > 0) {
        sum += num % 10; // Get last digit
        num /= 10;       // Remove last digit
    }
    std::cout << "Sum of digits of " << original << " = " << sum << std::endl;
    return 0;
}
```

### Exercise 6 Solution
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    int wins = 0, losses = 0, draws = 0;
    int choice;

    do {
        std::cout << "\n1. Rock\n2. Paper\n3. Scissors\n4. Quit\nChoice: ";
        std::cin >> choice;

        if (choice == 4) break;
        if (choice < 1 || choice > 3) continue;

        int comp = std::rand() % 3 + 1;

        std::string choices[] = {"", "Rock", "Paper", "Scissors"};
        std::cout << "You: " << choices[choice] << " | Computer: " << choices[comp] << std::endl;

        if (choice == comp) {
            std::cout << "Draw!";
            draws++;
        } else if ((choice == 1 && comp == 3) ||
                   (choice == 2 && comp == 1) ||
                   (choice == 3 && comp == 2)) {
            std::cout << "You Win!";
            wins++;
        } else {
            std::cout << "You Lose!";
            losses++;
        }
    } while (true);

    std::cout << "\nFinal Score - W:" << wins << " L:" << losses << " D:" << draws << std::endl;
    return 0;
}
```