#include <iostream>

int main() {
    // A simple for loop with only one statement in its body
    // Three parts in the parentheses:
    //      1. What is the loop variable and what is its initial value
    //      2. An expression that determines whether the loop should continue
    //          True -> Keep going
    //          False -> Stop
    //      3. How the loop variable should be modified in each iteration
    //          In this particular example, we increase i by one in every iter
    //          The ++ operator is called the self-increment operator, it will
    //          be explained further in day2_madness.cpp
    for (int i = 0; i <= 10; i++)
        std::cout << i << ' ';

    std::cout << '\n';

    // This will only print multiples of 3
    for (int i = 0; i <= 10; i += 3)
        std::cout << i << ' ';

    std::cout << '\n';

    // A loop with multiple statements, you must enclose all the statements
    // with curly brackets, this is because C++ does not care about indentations
    // like Python does
    // Try remove the brackets, the compiler will tell you that it does not know what
    // i & i_2 is, that is because the variables are only defined inside the loop body
    for (int i = 10; i > -1; i--) {
        int i_2 = i * 2;
        std::cout << i << " * 2 = " << i_2 << '\n';
    }
}
