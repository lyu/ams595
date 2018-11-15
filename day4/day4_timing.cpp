#include <algorithm>    // For std::sort
#include <iostream>
#include <vector>
#include <chrono>       // 0. For all the timing-related stuff

// In this example I will show you how to get the execution time of a block
// of C++ code using the standard library, in 4 lines of code

int main() {
    // Let's sort a long vector
    int N = 10000000;
    std::vector<int> v(N);

    for (int i = 0; i < N; i++)
        v[i] = N - i;

    // 1. Get a timestamp
    // I use auto because this timestamp has a pretty long type name and I don't
    // really care what it is
    auto t_start = std::chrono::steady_clock::now();

    // Perform the sort
    std::sort(v.begin(), v.end());

    // 2. Get another timestamp
    auto t_end = std::chrono::steady_clock::now();

    // 3. Compute the difference between the two timestamps and store it in a double
    double T = std::chrono::duration<double>(t_end - t_start).count();

    // There you go
    std::cout << "Sorting took: " << T << " seconds\n";
}
