#include <iostream>

int main() {
    // The use of if-else-elseif is demonstrated by the famous FizzBuzz problem
    // Description of the problem: http://wiki.c2.com/?FizzBuzzTest
    // This should look very similar to Python, except you put the checks in parentheses
    // and you use curly brackets instead of indentations
    for (int i = 1; i <= 20; i++) {             // Let's only test the first 20 integers
        if (i % 3 == 0) {                       // First we test if 3 divides i
            if (i % 5 == 0) {                   // If it does, how about division by 5?
                std::cout << "FizzBuzz\n";      // Both works, so print FizzBuzz
            } else {                            // If we are here, i is only divisible by 3
                std::cout << "Fizz\n";          // So we print Fizz
            }
        } else if (i % 5 == 0) {                // If 3 does not divide i, we still need to test for 5 (you can't use elif)
            std::cout << "Buzz\n";              // So it is only divisible by 5, print Buzz
        } else {                                // Nothing works, just print i
            std::cout << i << '\n';
        }
    }

    // Another version that looks better b/c it does not use nested if-else pairs
    // But is more error-prone for more complicated conditions
    // For example: test for divisibility by 2/3/5/7/11/13
    for (int i = 1; i <= 20; i++) {
        // First we test for that case that has the most overlapping conditions
        if ((i % 3 == 0) && (i % 5 == 0)) {     // && is the C++ equivalent of Python's "and" operator
            std::cout << "FizzBuzz\n";
        } else if (i % 3 == 0) {
            std::cout << "Fizz\n";
        } else if (i % 5 == 0) {
            std::cout << "Buzz\n";
        } else {
            std::cout << i << '\n';
        }
    }
}
