#include <iostream>
#include <cstdint>

// So far we have learned simple data types like arrays/vectors, and how to
// pass them to functions.
//
// This "passing data through a chain of functions" approach won't scale when
// you work on non-trivial software projects that is written by multiple people.
//
// Imagine writing a video game, where you have multiple characters interacting
// with each other. A naive approach would be: create a huge global state that
// stores all the characters' attributes and other data in arrays, and pass
// everything through a series of functions that modifies the attributes according
// to the user's input.
//
// This approach won't scale because:
//  1. It wastes a lot of time, even if a character is not being attacked, you still
//  need to pass it through all the attack-related functions.
//  2. It is very hard to extend. Adding a new character with a new ability probably
//  means that you need to modify tens to thousands of functions at different locations,
//  and introduce new bugs during the process.
//
//  C++ was created to support something called object-oriented programming. It's
//  basic idea is: bundle data and operation on that data together. So instead of
//  composing a chain of function calls, the programmer should think about a bunch
//  of objects interacting with each other by calling different "methods" that are
//  bundled to each of the objects. This abstraction models many problems very
//  accurately.
//
//  To create an object, first you need to say which class it belongs to, just like
//  you need to choose float or double before you declare a variable that stores 3.14.
//  For example
//      class:  human being
//      object: a human
//      class:  University
//      object: SUNY Stony Brook
// Essentially, defining a new class is defining your own data type.
// You specify what kind of elementary data type can your class store, and how
// can programmers modify them through "methods".

// Let's define our own vector class that stores doubles
// Syntax: "class <class_name> {};"
class myVec {
    // Private data & methods cannot be accessed outside of this class, this is
    // used to prevent other programmers from modifying the internal data in
    // unexpected ways.
    private:
        uint64_t _size;     // First, our vector need an integer to store its length
        double* _data;      // Second, our vector need a pointer that point to the actual array of doubles on the heap
    // Public data & methods can be used by anyone, they should provide a stable
    // interface that doesn't surprise other programmers even if you change the internal
    // implementation of your class
    public:
        // Constructors, they literally construct a new object when you say "myVec new_vec"
        // You need them because often the time you want to initialize objects to a proper state
        // For this constructor we only provide the size of the vector
        myVec(uint64_t size) {
            _size = size;               // Store the provided size
            _data = new double[_size];  // Allocate storage on the heap
        }

        // Another constructor, this time we provide both size and an initial value
        myVec(uint64_t size, double init) {
            _size = size;
            _data = new double[_size];
            // We fill the array with the provided init value
            for (uint64_t i = 0; i < _size; i++)
                _data[i] = init;
        }

        // Wikipedia: https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)
        // Rule of Three: Copy Constructor
        // This is needed for "myVec new_vec = old_vec"
        // If you don't define this, C++ will generate a dumb one, which will
        // only copy the _size and _data over, so you end up with two vectors
        // that point to the same array on the heap, so they overwrite each
        // other when you use them. This is called shallow copy. It will also
        // cause a double-free error when the objects are destroyed.
        // Here we define our own copy constructor that allocates another array
        // and we copy the values over manually, this is called deep copy and
        // is the right way to do it.
        myVec(myVec& other) {
            _size = other.size();
            _data = new double[_size];
            for (uint64_t i = 0; i < _size; i++)
                _data[i] = other[i];
        }

        // Rule of Three: Destructor
        // When your program terminates, objects will be destroyed, so we need
        // destructors to do the clean up, in this case, free heap memory.
        ~myVec() {
            delete [] _data;
        }

        // Rule of Three: Copy Assignment Operator
        // This is needed for "some_vec = another_vec"
        // Again, if you don't define this yourself, C++ will only copy the
        // pointer over, resulting in a shallow copy.
        myVec& operator=(myVec& other) {
            _size = other.size();
            _data = new double[_size];
            for (uint64_t i = 0; i < _size; i++)
                _data[i] = other[i];

            // I won't explain this very deep, but you can think of it as:
            //  = is an operator that need to return something
            //  This is not a constructor, the vector being modified already exists
            //  So return a reference to myself, instead of a new vector
            //  And at last, "this" is a pointer that points to the current object
            return *this;
        }

        // Like std::vector, let's create a member function that returns the size
        uint64_t size() {
            return _size;
        }

        // Array indexing operator [], notice a return a reference to an element,
        // so I can say v[i] = some_value;
        double& operator[](uint64_t idx) {
            return _data[idx];
        }

        // Overload <<, the friend keyword is need for this particular operator
        friend std::ostream& operator<<(std::ostream& os, myVec& v) {
            for (uint64_t i = 0; i < v.size(); i++)
                std::cout << v[i] << ' ';
            return os;
        }
};

int main() {
    myVec v(5);
    std::cout << v.size() << '\n';

    // Prove that array indexing works
    for (uint64_t i = 0; i < v.size(); i++)
        v[i] = 3.3;

    // Prove that << works
    std::cout << v << '\n';

    // Prove that the two-parameter constructor works
    myVec u(5, 7.1);
    std::cout << u << '\n';

    // Copy construction, delete the copy constructor and you will
    // see that w will also be modified, and a double-free error
    myVec w = v;
    v[1] = 99.9;
    std::cout << w << '\n';

    // Copy assignment, delete the copy assignment operator and you will
    // see the double-free error again
    w = u;
    std::cout << w << '\n';
}
