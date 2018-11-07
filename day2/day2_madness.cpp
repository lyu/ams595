#include <iostream>

int main() {
    // Self-increment/decrement operator
    // ++a: increase a BEFORE read the value of a
    // a++: increase a AFTER read the value of a
    // --a: decrease a BEFORE read the value of a
    // a--: decrease a AFTER read the value of a
    int a = 0;
    std::cout << "a = " << a << '\n';           // Print a, should be 0
    std::cout << "a++ = " << a++ << '\n';       // Print a, then increase it, should print 0, but a is 1 now
    std::cout << "a = " << a << '\n';           // Print a, should be 1
    std::cout << "++a = " << ++a << '\n';       // Increase a, then print it, should print 2, and a is 2 now
    std::cout << "a = " << a << '\n';           // Print a, should be 2
    std::cout << "a-- = " << a-- << '\n';       // You get the idea
    std::cout << "a = " << a << '\n';
    std::cout << "--a = " << --a << '\n';
    std::cout << "a = " << a << '\n';

    std::cout << "Let's make it a little harder\n";
    // Now, can you guess what this part prints?
    int x = 4;
    int y = ++x-++x+x---x++-x--;
    std::cout << "x = " << x << '\n';
    std::cout << "y = " << y << '\n';

    // It is OK if you cannot predict the final values of x and y
    // Nobody should write code like this
    // Cute one-liners are often hard to understand, don't write them
    // If you compile with -Wall -Wextra, even the compiler complains about
    // this piece of code
}
