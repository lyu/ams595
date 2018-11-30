// Here I am going to show a more subtle bug that doesn't affect the output
// but kills the performance
//
// Recall that each CPU core has their own L1 data cache, and every time you
// read or write to a variable, the CPU will load that variable and its
// neighbors to the cache, hoping to save time if you access those neighbors
// immediately after the current value
//
// Programmers don't control the cache, so it's the CPU's responsibility to
// make sure all CPU see the same values by copying the cache to the affected
// cores if multiple cores loaded the same variable into their caches and one
// core modifies that variable
//
// This is the concept of cache coherence
//
// This example shows you how you could get heavily punished if you don't
// understand this concept
#include <iostream>

int main() {
    // Huge number of iterations
    const size_t N = 1000000000;
    // Intel & AMD x86 cache line size is 64 Bytes, which means 64 Bytes will
    // be loaded into the cache if you access the memory, even for just 1 Byte
    const size_t cache_line_len = 64;

    // Let's create an array of 128 1-Byte non-negative integers
    uint8_t v[2 * cache_line_len];

    // See explanation below
    // alignas(cache_line_len) uint8_t v[2 * cache_line_len];

    // Let's print the starting address of v
    std::cout << &v << '\n';

    // Let's create two threads, each will pick a section of code to run
    #pragma omp parallel sections num_threads(2)
    {
        // In the following section, we read from the 64th element of the array
        // This section will run exclusively on a CPU core
        #pragma omp section
        {
            size_t tmp = 0;
            for (size_t i= 0; i < N; i++)
                tmp += v[cache_line_len - 1];
        }

        // In the following section, we write to the 65th element of the array
        // This section will run exclusively on another CPU core
        #pragma omp section
        {
            for (size_t i = 0; i < N; i++)
                v[cache_line_len] = 1;
        }
    }

    // In theory, the two sections won't affect each other, they don't even touch
    // the same memory location
    //
    // In practice, if you run the program, it either take T amount of time,
    // or 2T amount of time (Use the lowest level of optimization please)
    //
    // Reason: cache lines are actually fixed locations in the memory, and they
    // align to address 0, for example:
    //  Load Byte from address 0  -> Bytes  0 ~ 63  gets loaded to L1 cache
    //  Load Byte from address 1  -> Bytes  0 ~ 63  gets loaded to L1 cache
    //  Load Byte from address 19 -> Bytes  0 ~ 63  gets loaded to L1 cache
    //  Load Byte from address 63 -> Bytes  0 ~ 63  gets loaded to L1 cache
    //  Load Byte from address 64 -> Bytes 64 ~ 127 gets loaded to L1 cache
    //  You get the idea
    //
    // We didn't define the alignment of our array v, so the 64th & 65th element
    // may or may not be on the same cache line. If the address of v ends with
    // 0x00, 0x40, 0x80 or 0xc0, they won't be (decimal -> hexadecimal: 64 -> 0x40)
    //
    // If they are not on the same cache line, cache coherence won't affect you,
    // your program will take T to finish
    //
    // If they are on the same cache line, every time core 0 modifies v[64], the CPU
    // will detect the change and stop all the cores that have the same cache line
    // loaded, copy the new cache line over, and resume their execution. Both threads
    // will be paused over and over again, your program will effectively run in serial,
    // and take ~2T to finish
    //
    // This is called false sharing, it absolutely kills performance
    //
    // You can use alignas to make sure our v array is always aligned to addresses that
    // are multiples of the cache line size, and so v[63] and v[64] are always on two
    // different cache lines

    std::cout << v[cache_line_len] << '\n';
}
