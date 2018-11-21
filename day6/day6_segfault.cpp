#include <iostream>

int main() {
    // Here we create a pointer pointing to a string literal
    // This string literal is anonymous, it will be stored in a special section
    // of the memory which is read-only, and the pointer will point to the
    // start of that string
    char* msg = "Hello, world!\n";

    // Try to print the string, it will only print the first letter
    std::cout << *msg << '\n';

    // Try to write to read-only memory, segmentation fault
    msg[0] = 'h';
}
