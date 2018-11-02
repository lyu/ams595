// Like the import keyword of python, here we import the iostream library for performing input/output
#include <iostream>

// Every C++ program must have one and only one main function
// It is the entry point of your program (execution starts here)
// int means this function returns an integer (required for the main function)
// () means that this function does not take any arguments
// {} encloses the function body
// Don't forget the ; after every statement!!!
int main() {
    // The 'std::' part means that it is part of the standard library
    // cout is the out put stream that can be used to print stuff to the
    // console/terminal, we imported iostream for it
    // "<<" is one operator (not two!) that basically means "redirect the
    // stuff on the right hand side to the left hand side (more on this later)
    std::cout << "hello world\n";           // \n is needed because C++ doesn't automatically insert a newline
    std::cout << "hello" << "world\n";      // Multiple outputs looks like this, again, no auto-inserted white space like python does
    std::cout << "five = " << 5 << '\n';     // numbers work as well

    // Notice that I didn't return any value here, I will explain this later
}
