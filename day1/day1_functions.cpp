#include <iostream>
#include <cmath>        // The C math library, we import this for the std::pow power function

// Here we create a square function, that takes one integer as the input (hence the (int x))
// and returns an integer as the output
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
}
