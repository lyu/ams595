// std::thread is easier to use compared to the native threading library
// provided by your operating system, but having to manually protect each
// shared variable and distribute the work is still very boring and error-prone
//
// Scientists already have more than enough problems to worry about, they want
// to parallelize their code as easily as possible, OpenMP was created to help
// them
//
// OpenMP is not part of the C++ programming language, it is a compiler extention
// that could work for C/C++ and Fortran programs
//
// Recommended OpenMP tutorial: https://bisqwit.iki.fi/story/howto/openmp/
//
// For g++, add -fopenmp to the compiler flags
#include <iostream>


int main() {
    // To run a block of code in parallel, add #pragma omp parallel in front of it
    //
    // It is a compiler-directive that tells the compiler to generate code to
    // do the specified job
    //      #pragma: this is the beginning of any compiler-directive
    //          omp: this is an OpenMP directive
    //     parallel: run the following block of code in parallel
    //  num_threads: run with specified number of threads (optional)
    #pragma omp parallel num_threads(3)
    std::cout << "Hello, OpenMP world!\n";

    std::cout << "Back to serial\n";

    // Stuff run in parallel, so the output could be messed up in order
    #pragma omp parallel num_threads(3)
    {
        std::cout << 1 << 2 << 3 << 4 << '\n';
        std::cout << 1 << 2 << 3 << 4 << '\n';
    }

    // Now let's do a parallel dot product, the result is obviously 1024
    const size_t N = 1024;

    int* v1 = new int[N];
    int* v2 = new int[N];

    for (size_t i = 0; i < N; i++) {
        v1[i] = 1;
        v2[i] = 1;
    }

    int sum = 0;
    // Let's fire up 4 threads
    #pragma omp parallel num_threads(4)
    {
        // By default, everything between the curly brackets will be duplicated
        // to all the threads, so we will do the dot product 4 times if we don't
        // actually split up the work
        //
        // OpenMP provides the following directive to partition a for loop, it will
        // automatically split the iteration space equally and distribute the parts
        // to each of the threads
        // Try delete this line to see what happens
        #pragma omp for
        for (size_t i = 0; i < N; i++) {
            // Here we update the shared variable sum in parallel, and we need to
            // protect it with a mutex
            // OpenMP provides the critical directive to protect the code block that
            // follows that directive, only one thread can execute that block at any
            // given time
            // Try delete this line to see what happens
            #pragma omp critical
            sum += v1[i] * v2[i];
        }
    }

    delete[] v1;
    delete[] v2;

    std::cout << "<v1, v2> = " << sum << '\n';
}
