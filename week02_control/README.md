# Week 2: Control Structures

Control structures allow you to control the flow of your program. In C++, they are almost identical to Python in logic, but syntax differs.

## 1. Selection Structures

### `if` / `else if` / `else`
```cpp
int score = 85;

if (score >= 90) {
    std::cout << "A";
} else if (score >= 80) {
    std::cout << "B";
} else if (score >= 70) {
    std::cout << "C";
} else {
    std::cout << "F";
}
```

### `switch` Statement
Great for multiple discrete values (like menus).
```cpp
char grade = 'B';

switch (grade) {
    case 'A':
        std::cout << "Excellent";
        break; // VITAL! Without break, it "falls through" to next case
    case 'B':
        std::cout << "Good";
        break;
    case 'C':
        std::cout << "Average";
        break;
    default:
        std::cout << "Invalid grade";
}
```

## 2. Repetition Structures (Loops)

### `while` Loop
Check condition **before** executing.
```cpp
int i = 0;
while (i < 5) {
    std::cout << i << " ";
    i++;
}
```

### `do-while` Loop
Executes **at least once**, checks condition after.
```cpp
int choice;
do {
    std::cout << "1. Start\n2. Exit\nChoice: ";
    std::cin >> choice;
} while (choice != 2);
```

### `for` Loop
Best when you know the number of iterations.
```cpp
// Standard
for (int i = 0; i < 5; i++) {
    std::cout << i << " ";
}

// Range-based (C++11) - for arrays/vectors
int arr[] = {1, 2, 3};
for (int num : arr) {
    std::cout << num << " ";
}
```

## 3. Logical Operators
| Operator | Meaning | Example |
|----------|---------|---------|
| `&&` | AND | `(age >= 18 && hasID)` |
| `||` | OR | `(isStudent || isStaff)` |
| `!` | NOT | `!isLoggedIn` |

## 4. The Conditional (Ternary) Operator
Short-hand for simple if/else.
```cpp
int age = 20;
std::string status = (age >= 18) ? "Adult" : "Minor";
```

---
## Exercises

1. **Grade Calculator**: Input a mark (0-100), output the grade (A, B, C, D, F) using `if/else if`.
2. **Menu System**: Use `switch` to create a calculator menu (1=Add, 2=Subtract, 3=Multiply, 4=Divide, 5=Exit). Loop until exit.
3. **Number Guessing Game**: Computer picks random 1-100. User guesses. Give hints "Higher"/"Lower". Count attempts. Use `do-while`.
4. **Prime Checker**: Input a number. Check if prime using `for` loop.
5. **FizzBuzz**: Print 1 to 100. If divisible by 3 print "Fizz", by 5 print "Buzz", by both print "FizzBuzz".