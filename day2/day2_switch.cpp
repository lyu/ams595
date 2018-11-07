#include <iostream>

int main() {
    int i;
    std::cout << "Type an integer: ";
    std::cin >> i;

    // A switch statement compares a variable against several user-provided values
    // If a match is found, it will execute the statements under that case
    switch (i) {                                // Let's do a switch on the variable i
        case 0:                                 // If i == 0
            std::cout << i << '\n';             // Print i
        case 1:                                 // If i == 1
            std::cout << i << '\n';             // Print i
        default:                                // If no match can be found, we fallback to the default case
            std::cout << "A big number\n";      // Print something that is true in general
    }

    // When you run the program, the behavior will be wrong if you input 0 or 1
    // Reason: "case x:" and "default:" are merely labels, they are like the exit signs
    // on I-495, you can see them, but you have to steer your car to the exit yourself,
    // otherwise your car just keep riding down the road
    //
    // Here if i == 0, case 0 will be selected, and 0 will be printed. However, I didn't tell
    // the program to exit the switch statement, it will just continue its execution, print 0
    // again, and finally print "A big number\n"
    //
    // This behavior is called "implicit fall-through", and can cause a lot of trouble because the
    // program doesn't crash so you know something is wrong immediately
    //
    // Compilers can warn you about this issue, for g++, you can add "-Wall -Wextra" to the flags
    //
    // To make the switch behave like intended, we need to break from it when the matched case
    // has finished execution, and we will use the break statement for this

    std::cout << "A second try!\n";
    switch (i) {
        case 0:
            std::cout << i << '\n';
            break;
        case 1:
            std::cout << i << '\n';
            break;
        default:
            std::cout << "A big number\n";
            break;
    }
}
