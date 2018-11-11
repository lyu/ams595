#include <iostream>
#include <vector>

// In C++11 you can use the using keyword to define type aliases
// Here I let iMat represent a vector of integer vectors (a 2D integer matrix)
using iMat = std::vector<std::vector<int>>;


// If you think arrays and pointers are too primitive compared to Python's
// lists, it's because they were invented even before C was born.
// A modern replacement is std::vector, include <vector> to use it.

// It is strongly suggested to use std::vector whenever you need arrays, as the
// performance difference is barely noticable, and it is much much more feature-rich
// than C arrays.
int main() {
    int N = 4;
    // To declare a vector, the syntax is:
    //      "std::vector<typename> <vector_name>(<vector_length>)"
    // Again, vectors are homogeneous, the can only store one type of variables
    std::vector<int> v1(N);

    // You can use an intialization list to initialize a vector
    std::vector<int> v2 = {7, 5, 16, 8};

    // Assignment works as expected, a new vector will be created and all the
    // values will be copied over
    std::vector<int> v3 = v2;

    // Again, vector indexing, same syntax everywhere
    for (int i = 0; i < N; i++)
        v2[i] = 0;

    // If you are lazy, in C++11 you can use this new way to write for loops
    // Syntax: for (<typename> <element_name> : <vector_name>)
    for (int e : v3)
        std::cout << e << ' ';
    std::cout << '\n';

    // To get the number of elements in a vector, use <vector_name>.size()
    std::cout << "size is: " << v2.size() << '\n';

    // Creating 2D matrices is easier, it will be a vector of integer vectors
    // Type: std::vector<std::vector<int>>
    // This is too long to type, so we create an alias for it at the top of
    // this cpp file
    // Initialization list still works
    iMat mat = {{1, 2}, {3, 4}};

    // The same lazy for loop. This time, each row will be a std::vector<int>,
    // and I don't want to type that, so I will use the keyword auto to tell
    // the compiler: I don't really care the type name of a row, just extract
    // it from the matrix and let me use it.
    // The second for loop also uses the auto keyword, although I could have
    // just used int.
    for (auto row : mat) {
        for (auto e : row)
            std::cout << e << ' ';
        std::cout << '\n';
    }

    // Let's create another vector
    std::vector<int> vec;

    // Initially, the length of the vector is zero
    std::cout << "size = " << vec.size()
              << ", capacity = " << vec.capacity() << '\n';

    // You can change the size of vectors
    vec.reserve(12);

    // After the reserve, we have 12 slots that are available to store
    // size() still returns the number of elements stored in vec, which is still 0
    // capacity() will return the space vec occupies, whis is 12 now
    std::cout << "After reserve(12), size = " << vec.size()
              << ", capacity = " << vec.capacity() << '\n';

    // If I write more than the vector can hold, vec.at(<index>) will catch the
    // error, while the usual vec[<index>] cannot.
    for (int i = 0; i < 14; i++)
        vec.at(i) = i;

    // There are many many more useful member functions for vectors, check
    // https://en.cppreference.com/w/cpp/container/vector for details
}
