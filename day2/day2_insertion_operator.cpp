#include <iostream>

int main() {
    // What exactly is the "<<" thing?
    // In the context of performing I/O, it is a binary operator called the insertion operator
    // It takes two operands: the left hand side must be an output stream of some form
    //                        the right hand side must be something it knows how to perform I/O on
    // It returns one thing: its left hand side (i.e, the same output stream that passed to it)
    // So when I print multiple strings to my terminal using the cout output stream, what really
    // happens is that the first << operator will send the string "hello" to cout, then return
    // cout to the second << operator, which will return the cout object to the third <<
    // operator after sending " world" to cout
    // Below I used parentheses to make this process clear
    (((std::cout << "hello" ) << " world" ) << "\n");

    // If you don't believe me, try uncomment the following line and compile the program,
    // see if you can understand the error message
    // std::cout << ("hello" << " world" << "\n");
}
