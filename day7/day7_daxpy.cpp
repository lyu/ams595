// A simple daxpy program that computes double-precision a * x + y
// This example shows what the optimizaiton flags do, and the concept
// of the memory wall
//
// Obviously, this operation is memory-bound, so even if you have an x86 CPU
// that is produced after 2013, which can do this operation in one clock cycle
// (FMA: g++ enables it when -march=native is used), you still won't get a good
// speedup, because you are limited by the memory's speed.
#include <iostream>


void daxpy(const double a, double* x, double* y, const size_t N) {
    for (size_t i = 0; i < N; i++)
        y[i] = a * x[i] + y[i];
}


int main() {
    // Danger: make this number smaller when you run the program on your machine
    const size_t N = 1 << 29;

    double* x = new double[N];
    double* y = new double[N];

    for (size_t i = 0; i < N; i++) {
        x[i] = double(i);
        y[i] = -double(i);
    }

    daxpy(1.2, x, y, N);

    std::cout << y[1] << '\n';

    delete[] x;
    delete[] y;
}
