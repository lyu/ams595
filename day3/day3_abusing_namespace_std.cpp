#include <iostream>

// To avoid writing std:: everywhere, you can put this at the beginning of a cpp file
// This means that look for functions/objects in the standard library's namespace by default
// It also means that all user-defined functions/objects will be stored in the std namespace
using namespace std;

int main() {
    // It works
    cout << "Hello, world!\n";

    // This does come with its downsides
    // Here I give a seemingly stupid example, I overwrite the cout output stream with an
    // integer
    int aout = 1;
    int bout = 2;
    int cout = 3;

    // Here I try to print the integers, if you compile and run the program, nothing will
    // be printed, but also, no warning/error will appear, this is because the << operator
    // is also defined for integers, just not for printing
    cout << aout << '\n';
    cout << bout << '\n';
    cout << cout << '\n';

    // You already know what cout is so you are unlikely to make this mistake, but one is also
    // unlikely to remember all the functions/objects in every header file of the standard
    // library.
    // For example, if this is a multi-thousand line program maintained by multiple people in
    // your company, you don't want someone define another floor(double x) function while
    // importing the <cmath> header, because doing so will overwrite std::floor and may have
    // unexpected effects.
}
