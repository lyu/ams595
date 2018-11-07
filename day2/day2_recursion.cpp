#include <iostream>

// This function computes the nth Fibonacci number using recursion
// It takes one input: integer n
// It returns one value: the nth Fibonacci number, as an integer
// I define it before I call it in the main function
int fib(int n) {
    if (n < 2) {                        // fib(0) = 0, fib(1) = 1, so this works
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int N = 40;
    std::cout << "fib(" << N << ") = " << fib(N) << '\n';
}
