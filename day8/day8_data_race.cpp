#include <iostream>
#include <thread>
#include <vector>
#include <mutex>    // To use mutex objects

// A variable declared outside of any function is a global variable
// it is globally visible, all functions can see it just like all
// functions can see each other (functions are declared outside of any
// other functions right?)
//
// Here is a globally-visible mutex, all functions in all threads can see
// and use it
std::mutex mtx;

// This time we update the shared variable sum many many times in each thread
// Because there is no coordination, they will overwrite each other's result
// So the final result is almost always going to be smaller than 4096
//
// This phenomenon is called a data race, it occurs when two or more threads
// access the same memory location concurrently, and at least one of the threads
// writes to that location
//
// You can have access control by using mutex (mutual exclusion) objects
// They act like a lock with only one key: every thread must obtain the key
// before they can access the stuff behind that lock, any thread without
// the key will have to wait for the previous owner to release the key
void helper(uint64_t& sum) {
    // To protect the shared variable sum, we try to acquire access right
    // to the mutex by creating a lock_guard object at the beginning of each
    // thread
    // If the mutex is available, the guard object will be created successfully,
    // and we can proceed to modify sum
    // If the mutex is unavailable, that means some other thread is modifying
    // sum, and the thread will pause until mutex is released and available
    //
    // Uncomment the following line to see 4096 getting printed
    // std::lock_guard<std::mutex> guard(mtx);
    const size_t N = 1024;
    for (size_t i = 0; i < N; i++)
        sum++;
    // Here at the end of the helper function, the thread terminates and joins
    // with the main process, the guard object gets destroyed and so the mutex
    // becomes available for other threads
    //
    // Effectively, this program runs in serial, because all we did was
    // modifying a shared variable and so we had to ensure ordered access.
    //
    // If your program do computations that are actually useful, then update a
    // shared variable, those parts will run in parallel and you get a speedup
}

int main() {
    const size_t n_threads = 4;
    std::vector<std::thread> tv;

    uint64_t sum = 0;
    for (size_t i = 0; i < n_threads; i++)
        tv.emplace_back(helper, std::ref(sum));

    for (auto& t : tv)
        t.join();

    std::cout << sum << '\n';
}
