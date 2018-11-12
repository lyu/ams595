#include <iostream>

// Passing 1-D arrays to functions is simple, just use "<typename> <array_name>[]"
// However, you must tell the function about the lengths of the arrays
// Also, arrays are ALWAYS passed in as references, so if you modify arrays inside the
// callee, the caller will see the changes, so use const to protect the arrays if needed
int dot(const int a[], const int b[], const int len) {
    int result = 0;
    for (int i = 0; i < len; i++)
        result += a[i] + b[i];
    return result;
}

int main() {
    int N = 4;
    // Declaring arrays, the syntax is "<typename> <array_name>[<array_length>]"
    // You cannot change the size of an array
    // Also, unlike Python's lists, C/C++ arrays are homogeneous, one array can
    // only store one type of variables
    int my_array_1[N];
    int my_array_2[N];

    // Array indexing, just like Python
    for (int i = 0; i < N; i++) {
        my_array_1[i] = i + 1;
        my_array_2[i] = i + 1;
    }

    std::cout << "dot product: " << dot(my_array_1, my_array_2, N) << '\n';
    
    // Notice that you cannot assign one array to another directly, because
    // the = operator doesn't know about the length of your arrays. Instead you
    // will have to use a loop to copy the values one by one.
    // Try uncomment the following line and see what happens when you compile
    // this program.
    // my_array_2 = my_array_1;

    // Now let's go deeper.
    // Unlike Python, C/C++ does not warn you if you go out-of-bound, you can
    // overwrite something that does not belong to that array, and you are lucky
    // if your program crashes, because then you know something is wrong.
    // Here I will show you an example where your program doesn't crash, but
    // your data is silently corrupted.
    // If I write 6 elements to array 1, you would guess that I overwrite the
    // first half of array 2, because it is declared after array 1.
    for (int i = 0; i < N + 2; i++)
        my_array_1[i] = 0;

    for (int i = 0; i < N; i++)
        std::cout << my_array_1[i] << ' ';
    std::cout << '\n';

    for (int i = 0; i < N; i++)
        std::cout << my_array_2[i] << ' ';
    std::cout << '\n';
    // Turns out the first half of array 2 is untouched, this is because arrays
    // declared in this way are stored on the stack, and stack grows down. So
    // array 1 sits at a higher address because it is declared and allocated
    // earlier.
    // In our example, if the four elements of array 1 are at addresses: 95 96 97 98
    // the four elements of array 2 will be at: 91 92 93 94
    // Now let's write 6 elements to array 2, this time we should see array 1 being
    // overwritten
    for (int i = 0; i < N + 2; i++)
        my_array_2[i] = 1;

    for (int i = 0; i < N; i++)
        std::cout << my_array_1[i] << ' ';
    std::cout << '\n';

    for (int i = 0; i < N; i++)
        std::cout << my_array_2[i] << ' ';
    std::cout << '\n';
}
