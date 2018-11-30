// When you run a program, the operating system runs it as a process on a CPU
//
// It's basically an isolated run time environment that contains the variables
// and library functions required for the program to run
//
// A process is a single execution stream that can only use one CPU core at any
// given time
//
// To accelerate computation with multiple CPU cores, you can run several processes
// and let them talk to each other to coordinate the work, but inter-process
// communication is more involved than reading a value from a variable
//
// Threads were invented to help programmers write program that use multiple CPU
// cores, they are mini-processes that spawn from a process, and can share data
// with each other easily
//
// To use threads in C++, include the <thread> header, and pass the "-pthread"
// flag to g++
#include <iostream>
#include <thread>
#include <vector>


uint64_t fib(uint64_t n) {
    if (n < 2)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}


// A helper function as the entry point of the threads (akin to the main function)
// It must has the return type of void, and so if you want to return something
// from your thread, you need to use pointers/references
void helper(size_t id, uint64_t& sum) {
    uint64_t result = fib(43);  // Waste some time
    sum += result;              // Accumulate data using the sum output parameter
    std::cout << "Thread ID " << id << ": fib(43) = " << result << '\n';
}
// Normally you pass a unique ID to your thread, so the thread can use it to
// identify the portion of work it will be working on
// For example: do a dot product of two vectors of length 4096, using 4 CPU cores
//      Thread with ID 0 will work on [ID * (4096/4), (ID + 1) * (4096 / 4)) = [0, 1024)
//      Thread with ID 1 will work on [ID * (4096/4), (ID + 1) * (4096 / 4)) = [1024, 2048)
//      and so on ...


int main() {
    const size_t n_threads = 4;

    // It's a good idea to manage thread objects in some data structure
    std::vector<std::thread> tv;

    uint64_t sum = 0;

    // Create thread objects at the end of our thread vector using emplace_back
    // The constructor of std::thread take one or more arguments
    //    std::thread(<function_to_execute>, <arg_1>, <arg_2>, ... )
    // emplace_back will take the arguments you passed to it and construct new
    // objects with them
    for (size_t i = 0; i < n_threads; i++)
        tv.emplace_back(helper, i, std::ref(sum));  // Notice the use of std::ref

    std::cout << "The computation threads have started, the main process will wait for them to join\n";

    // By calling the join() method on a thread object, the calling process will
    // wait for the completion of the thread managed by that object
    // join() will block the execution of the caller, it is the most basic way
    // to make sure the callee has finished it execution and the result is ready
    // to use
    for (auto& t : tv)
        t.join();

    // Now that we have joined all 4 threads, we can print the result
    std::cout << "All threads terminated, sum = " << sum << '\n';
}
