#include <iostream>

// This is my function that can allocate arrays on the heap and initialize
// them with 1's.
// Notice that it returns a pointer pointing to the beginning of the array (int*)
int* my_allocator(const int nelems) {
    // To allocate an array on the heap, we use the new keyword
    // Syntax: <typename>* <pointer_name> = new <typename>[<array_length>]
    int* result = new int[nelems];
    for (int i = 0; i < nelems; i++)
        result[i] = 1;
    // Just return the pointer(address of the beginning of the array)
    return result;
}

int main() {
    int a = 1;
    std::cout << "a = " << a << '\n';

    // We have seen the use of the & operator in the 2D array example
    // The & operator returns the memory address of a variable, this memory address
    // can be stored in a pointer
    // To declare a pointer point to a variable with type T, the syntax is "T* <pointer_name>"
    int* a_ptr = &a;
    std::cout << "The address of a is " << a_ptr << '\n';

    // To get the value at the memory address a pointer is pointing to (de-reference),
    // you can use the * operator
    std::cout << "The value stored at this address is: " << *a_ptr << '\n';

    // A pointer can also point to an array, and doesn't have to point to its beginning
    int v[4];
    int* array_ptr_0 = &v[0];       // Point to the 0th element of v
    int* array_ptr_2 = &v[2];       // Point to the 2nd element of v

    // Two ways to de-reference pointers, * and []
    if (array_ptr_0[2] == *array_ptr_2)
        std::cout << "Yes, v[2] == v[2]\n";

    // A very important use of the pointers is to store an address on the heap
    // When a function terminates, all its local variables that are stored on the
    // stack will be deleted, like "int a" and "double vec[10]".
    // However, heap-allocated objects are persistent: as long as your program
    // is still running, those objects won't be deleted until the programmer
    // manually remove them.
    // Suppose for some reason, I need a lot of arrays that are all initialized
    // with 1's. I do not want to repeat the process of declaring arrays and
    // fill them with ones using a for loop over and over again, so I will
    // create a function to do it, and obviously I do not want the array to be
    // deleted when this function returns.
    int N = 4;
    int* my_array = my_allocator(N);

    // Print the allocated array
    for (int i = 0; i < N; i++)
        std::cout << my_array[i] << ' ';
    std::cout << '\n';

    // You may have noticed that the longer you use some software, the slower
    // it becomes (web browsers are the most likely to have this problem), and
    // restarting the software can usually solve it.
    // This is partly because such mult-million line software projects are very
    // complicated, some heap-allocated objects are not properly released when
    // the programmers are done with them, and so the longer you use the
    // software, the more memory it occupies because of all the uncollected
    // garbage. Restarting the software will release everything on the heap and
    // so everything is fast again.
    // To release a heap-allocated array using the new keyword, let's use the
    // delete keyword.
    delete [] my_array;

    // The [] is needed if the pointer is pointing to an array, otherwise just
    // use "delete pointer;".
}
