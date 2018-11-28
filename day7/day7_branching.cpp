// This example shows you how to help the CPU's branch predictor to guess
// the right branch, and therefore improve the throughput
//
// Sometimes it is a good idea to sort an array before using it, especially
// if you have if-else branches that depends on the sizes of the values in v
//
// Do not compile this program with high level of optimization, use -O0 if
// you are using g++
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>


int main() {
    const size_t N = 65536;
    std::vector<int> v(N);

    std::mt19937_64 rng(0);
    std::uniform_int_distribution<> dis(0, 4096);

    // Fill a long vector with random values between 0 and 255
    for (size_t i = 0; i < N; i++)
        v[i] = dis(rng) % 256;

    // Uncomment this line to save time!
    // std::sort(v.begin(), v.end());

    size_t counter = 0;

    // In the if statement below, 50% of the time the expression will evaluate
    // to false. The values in v have no pattern so the CPU cannot predict the
    // value of the next entry of v using previous values.
    //
    // When the result of v[i] < 128 is clear, counter++ has already entered
    // the CPU's pipeline. If the result is false, the CPU must pause its
    // execution, flush the pipeline, do cleanup work and proceed to the next
    // iteration, branch-misses like this kills performance.
    //
    // A simple fix is to sort the vector before using it, so values in v has
    // a clear patter, the CPU can predict which branch of the if statement to
    // take, and the performance more than doubles
    for (size_t n = 0; n < 100000; n++) {
        counter = 0;
        for (size_t i = 0; i < N; i++) {
            if (v[i] < 128)
                counter++;
        }
    }

    std::cout << counter << '\n';
}
