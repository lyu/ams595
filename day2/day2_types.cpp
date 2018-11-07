#include <iostream>
#include <cmath>
#include <limits>       // The C++ way to get the max/min value a type can hold
#include <cstdint>      // To get types like uint64_t

// If you don't want to write std:: all the time, use this
// Because I used this, I must define my power functions below as my_pow
// otherwise it will conflict with the std::pow function from the standard
// library
// More on this later
using namespace std;

// We define a power funciton that computes base^exp
// Both base and the return value are integers
int my_pow(int base, int exp) {
    std::cout << "(Selecting the int version of my_pow) ";
    int result = 1;
    for (int e = 1; e <= exp; e++)
        result *= base;

    return result;
}

// We define another power function, this time both base and the return value are doubles
// Try delete this function, see what the program prints for 3.3^3
// What happens if you delete the function above?
double my_pow(double base, int exp) {
    std::cout << "(Selecting the double version of my_pow) ";
    double result = 1.0;
    for (int e = 1; e <= exp; e++)
        result *= base;

    return result;
}


int main() {
    // This should print 2
    cout << "4 / 2 = " << 4 / 2 << '\n';

    // Different from Python, this will print 1 instead of 1.5
    //   1. Both 2 & 3 looks like integers, so C++ assume you will want an integer as the result
    //   2. The standard says that C++ compilers should just take the integer part of 1.5 as the result
    cout << "3 / 2 = " << 3 / 2 << '\n';

    // Method 1 to avoid this problem: make at least one operand looks like a float
    cout << "3 / 2.0 = " << 3 / 2.0 << '\n';

    // Method 2 to avoid this problem: force the type conversion using the syntax "(desired_type)"
    cout << "(double) 3 / 2 = " << (double) 3 / 2 << '\n';

    // The base is 3, it looks like an integer, so the compiler will select the first pow function
    cout << "3^3 = " << my_pow(3, 3) << '\n';

    // The base is 3.3, it looks like an floating-point number
    //  If the double version of the pow function is available, the compiler will select that as the best match
    //  If not, since the compiler knows how to convert a double to an int, so the int version works
    cout << "3.3^3 = " << my_pow(3.3, 3) << '\n';

    // Unlike Python, the integer types in C++ has limited ranges
    cout << "The type int can hold a value in the range ["
         << numeric_limits<int>::min() << ", "
         << numeric_limits<int>::max() << "]\n";

    // Why those numbers?
    // The sizeof function will tell you how many Bytes are used to store a type
    // in THIS PARTICULAR compiler on THIS PARTICULAR machine
    cout << "sizeof(int) = " << sizeof(int) << '\n';

    // 1 Byte = 8 bits = 8 0's or 1's
    // x Bytes = 8x bits, it can store 2^(8x) different combinations of 0's and 1's
    // So it can store 2^(8x) different numbers
    cout << "So it can hold " << "2 ^ " << sizeof(int) * 8 << " = "
         << pow(2, sizeof(int) * 8) << " integers\n";

    // What will happen if we go beyond the limit?
    int z = numeric_limits<int>::max() + 1;
    cout << "[int max] + 1 = " << z << '\n';
    // The result is a negative number, this is called an integer overflow

    // If you are sure you don't need negative numbers, you can use the type unsigned
    cout << "The type unsigned can hold a value in the range ["
         << numeric_limits<unsigned>::min() << ", "
         << numeric_limits<unsigned>::max() << "]\n"
         << "sizeof(unsigned) = " << sizeof(unsigned) << '\n';

    // After including <cstdint>, you can use types that are explicit in how many
    // bits they use
    cout << "The type uint16_t can hold a value in the range ["
         << numeric_limits<uint16_t>::min() << ", "
         << numeric_limits<uint16_t>::max() << "]\n"
         << "sizeof(uint16_t) = " << sizeof(uint16_t) << '\n';

    cout << "The type int64_t can hold a value in the range ["
         << numeric_limits<int64_t>::min() << ", "
         << numeric_limits<int64_t>::max() << "]\n"
         << "sizeof(int64_t) = " << sizeof(int64_t) << '\n';

    cout << "The type float can hold a value in the range ["
         << numeric_limits<float>::min() << ", "
         << numeric_limits<float>::max() << "]\n"
         << "sizeof(float) = " << sizeof(float) << '\n';

    cout << "The type double can hold a value in the range ["
         << numeric_limits<double>::min() << ", "
         << numeric_limits<double>::max() << "]\n"
         << "sizeof(double) = " << sizeof(double) << '\n';
}
