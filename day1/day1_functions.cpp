#include <iostream>
#include <cmath>        // The C math library, we import this for the std::pow power function


// Let's create a function that takes an integer, multiply it by 2, and returns the result
// Almost everything in C++ is explicity typed, so we use the 'int' keyword twice to indicate
// the input and return types
int foo(int n) {
    return 2 * n;
}

// The foo function above only takes integer arguments, if you call it with foo(6.1), C++
// will convert the floating point number 6.1 to integer 6 by discarding everything after
// the decimal point and you will get 12 as the result
// We can define another foo function with a different pair of input/return types
// C++ is smart enough to choose the right function for the right input type
// Try uncomment the function below and observe the different output!
// float foo(float f) {
//     return 2.0 * f;
// }

// Here we create a square function, that takes one integer as the input (hence the (int x))
// and returns an integer as the output
// Don't use Python's "**" operator in C++!
int square(int x) {
    return std::pow(x, 2);
}

int cubic(int x) {
    return std::pow(x, 3);
}

// The C++ compiler reads the source code from top to bottom, so you must first declear
// the two functions before using them in the main function
int main() {
    // Function invocation is straightforward, just like in math classes where you
    // write sin(pi/2), in C++ you pass parameters to functions using the parentheses
    std::cout << "square(2) = " << square(2) << '\n';
    std::cout << "cubic(2) = " << cubic(2) << '\n';
    std::cout << "cubic(square(2)) = (2^2)^3 = " << cubic(square(2)) << '\n';
    std::cout << "square(cubic(2)) = (2^3)^2 = " << square(cubic(2)) << '\n';

    int a = 5;
    float b = 6.1;
    std::cout << "foo(5) = " << foo(a) << '\n';
    std::cout << "foo(6.1) = " << foo(b) << '\n';
}
