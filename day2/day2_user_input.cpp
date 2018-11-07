#include <iostream>
#include <string>   // For std::string

int main() {
    // To get user's input, we use the input stream std::cin from the standard library
    // and the extraction operator ">>", which operates like the "<<" operator
    // We have only used string literals like "foo", to store a string in a variable
    // explicitly, we use the std::string type from the standard library

    std::string name;                               // Declare a variable called name, with type std::string
    std::cout << "Tell me your first name: ";       // Prompt user input
    std::cin >> name;                               // Extract user input from the cin input stream, and store it in name
    std::cout << "Hello, " << name << '\n';         // Check the result

    // We can get multiple inputs at once, and it looks like what we did for multiple
    // outputs
    // The cin object splits user input by spaces and/or newlines, so you can separate
    // your responses by either of them
    std::string firstname, lastname;
    std::cout << "Now tell me your fist name and your last name, separated by a space or by an enter key: ";
    std::cin >> firstname >> lastname;
    std::cout << "Hello, " << firstname << ' ' << lastname << '\n';

    // Numbers also work, the >> operator is smart enought to convert your input string
    // according to the type of its right hand side
    double age;
    std::cout << "How old are you? (you may try a floating point number): ";
    std::cin >> age;
    std::cout << "So you are " << age << " years old\n";
}
