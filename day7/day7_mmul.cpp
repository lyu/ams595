// Compute C = A x B, all square matrices
// This example shows the concept of cache-aware algorithms
#include <iostream>

int main() {
    // You can make N bigger so the matrices won't fit into your L2/L3 cache
    const size_t N = 1024;

    double A[N][N];
    double B[N][N];
    double C[N][N];

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            A[i][j] = 0.001 * (i * N + j);
            B[i][j] = 0.001 * (i * N + j + 1);
            C[i][j] = 0.0;
        }
    }

    // This is the simplest matrix multiplication algorithm
    //
    // The inner most loop iterate over k, this means when reading entries from
    // the B matrix, you will be reading from different rows in each iteration
    //
    // C/C++ uses row-major storage, when you read the first entry of a row, the
    // next 7 entries will also be loaded into the cache (Intel x86 cache line size is 64 Bytes)
    //
    // But in the next iteration, you are reading data from the next row, so you
    // will have another cache miss, and have to fetch 8 doubles from the memory
    // again, the performance suffers
    //
    // A simple fix is to swap the j-loop and the k-loop, then in the inner most
    // loop, A[i][k] will be a constant, B[k][j] will iterate over the same row,
    // you can see a big performance jump and a smaller number of L1 cache misses.
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            for (size_t k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];

    // This trick will only improve the L1 cache hit ratio, to improve L2 & L3
    // cache utilization, you need: https://en.wikipedia.org/wiki/Loop_nest_optimization

    // Print something from the matrix, b/c if the compiler finds out you don't use the
    // result of your computation, under -O2 it will simply delete all related code.
    std::cout << C[0][0] << '\n';
}
