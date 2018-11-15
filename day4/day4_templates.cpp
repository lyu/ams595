#include <iostream>

// A function template is a template for the compiler to generate function(s) at
// compile time, for different input types
// Suppose you have a function that take three numbers as the input:
//      Integer types: int, unsigned, int8_t, int16_t, int32_t, int64_t, uint8_t, uint16_t, uint32_t, uint64_t, (and more)
//      FP types: float, double, long double
// If you write a function for each possible combination of the types I listed
// above, you need to write 13^3 = 2,197 functions
//
// Using templates, you only need to write one
// Template is part of the C++ language, you don't need to include a header to use it
// "T" stands for a type identifier
template <typename T>
T plus(T a, T b) {
    return a + b;
}


int main() {
    double x = 1.1;
    double y = 2.2;
    // When compiler sees this line, it will generate double plus(double a, double b)
    std::cout << plus(x, y) << '\n';

    int16_t u = 3;
    int16_t v = 4;
    // When compiler sees this line, it will generate int16_t plus(int16_t a, int16_t b)
    std::cout << plus(u, v) << '\n';
}
