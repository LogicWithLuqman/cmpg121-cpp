#include <iostream>
#include <cstdlib> // for rand()
#include <ctime>   // for time()

// Example 1: If-Else If-Else Grade Calculator
void gradeCalculator()
{
    int mark;
    std::cout << "Enter mark (0-100): ";
    std::cin >> mark;

    if (mark >= 90)
    {
        std::cout << "Grade: A" << std::endl;
    }
    else if (mark >= 80)
    {
        std::cout << "Grade: B" << std::endl;
    }
    else if (mark >= 70)
    {
        std::cout << "Grade: C" << std::endl;
    }
    else if (mark >= 60)
    {
        std::cout << "Grade: D" << std::endl;
    }
    else
    {
        std::cout << "Grade: F" << std::endl;
    }
}

// Example 2: Switch Statement Menu
void switchMenu()
{
    int choice;
    double a, b;

    do
    {
        std::cout << "\n--- Calculator Menu ---" << std::endl;
        std::cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit" << std::endl;
        std::cout << "Choice: ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 4)
        {
            std::cout << "Enter two numbers: ";
            std::cin >> a >> b;
        }

        switch (choice)
        {
        case 1:
            std::cout << "Result: " << a + b << std::endl;
            break;
        case 2:
            std::cout << "Result: " << a - b << std::endl;
            break;
        case 3:
            std::cout << "Result: " << a * b << std::endl;
            break;
        case 4:
            if (b != 0)
                std::cout << "Result: " << a / b << std::endl;
            else
                std::cout << "Error: Cannot divide by zero!" << std::endl;
            break;
        case 5:
            std::cout << "Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 5);
}

// Example 3: Number Guessing Game (Do-While)
void guessingGame()
{
    std::srand(std::time(0));           // Seed random
    int secret = std::rand() % 100 + 1; // 1-100
    int guess;
    int attempts = 0;

    std::cout << "I'm thinking of a number between 1 and 100..." << std::endl;

    do
    {
        std::cout << "Your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess > secret)
        {
            std::cout << "Lower!" << std::endl;
        }
        else if (guess < secret)
        {
            std::cout << "Higher!" << std::endl;
        }
        else
        {
            std::cout << "Correct! You got it in " << attempts << " attempts." << std::endl;
        }
    } while (guess != secret);
}

// Example 4: Prime Number Check
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

void primeChecker()
{
    int n;
    std::cout << "Enter number to check: ";
    std::cin >> n;

    if (isPrime(n))
    {
        std::cout << n << " is Prime" << std::endl;
    }
    else
    {
        std::cout << n << " is NOT Prime" << std::endl;
    }
}

// Example 5: FizzBuzz
void fizzBuzz()
{
    for (int i = 1; i <= 100; i++)
    {
        if (i % 15 == 0)
        {
            std::cout << "FizzBuzz";
        }
        else if (i % 3 == 0)
        {
            std::cout << "Fizz";
        }
        else if (i % 5 == 0)
        {
            std::cout << "Buzz";
        }
        else
        {
            std::cout << i;
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Uncomment one to test:
    gradeCalculator();
    switchMenu();
    guessingGame();
    primeChecker();
    fizzBuzz();

    return 0;
}