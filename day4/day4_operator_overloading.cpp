#include <iostream>
#include <cstdint>
#include <vector>

// I hate typing a for loop every time I want to print a vector, and you should too
// By using operator overloading, we can let the built-in operators like "<< >> + - * /"
// work for types that they didn't know how to operate on

// Like I said, << is a binary operator that takes two inputs, and it returns the LHS
// Here I use references as inputs and output, because why would I copy the variables
// when I don't have to? Save time, save memory.
std::ostream& operator<<(std::ostream& os, std::vector<double>& v) {
    for (auto e : v)
        os << e << ' ';
    return os;
}

// Overloading + for "vector + vector", and the return type is obviously another vector
// Here I assume the programmer is sane, a.size() == b.size()
// Notice that I return the actual vector instead of just a reference!
std::vector<double> operator+(const std::vector<double>& a, const std::vector<double>& b) {
    std::vector<double> w(a.size());
    for (uint64_t i = 0; i < a.size(); i++)
        w[i] = a[i] + b[i];
    return w;
}

// Overload * for "double * vector"
// Notice that I return the actual vector instead of just a reference!
std::vector<double> operator*(const double alpha, const std::vector<double>& a) {
    std::vector<double> w(a.size());
    for (uint64_t i = 0; i < a.size(); i++)
        w[i] = alpha * a[i];
    return w;
}

int main() {
    std::vector<double> v(5, 1.0);
    std::vector<double> u(5, 1.0);
    // After we defined + and *, this works
    auto w = u + 3.0 * v;
    // This will not work because we didn't define * for "vector * double"
    // auto z = u + v * 3.0;

    // Printing to ostream works b/c we overloaded <<
    std::cout << w << '\n';
}
