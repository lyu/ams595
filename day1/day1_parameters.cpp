#include <iostream>


// When you do not need your function to return something, use the void keyword
// It means that the function has no return value
void foo(int bar) {
    // This foo function copies the content of the bar variable
    // into its own scope
    bar = 6;
    std::cout << "callee: foo(my_bar) prints " << bar << '\n';
    // When the function terminates, this copy of the variable
    // is destroyed, and so the modification doesn't affect that
    // variable of its caller
}

void foo_ref(int& bar) {
    // This version uses the reference of the bar variable passed by its caller,
    // so when it modifies the variable, all the changes are visible to the caller
    bar = 6;
    std::cout << "callee: foo_ref(my_bar) prints " << bar << '\n';
    // References can save the time to copy the variable, and save the memory
    // required to save the copied variables, but if you are not careful,
    // you could do unintended modifications and mess up your data
}

void foo_const_ref(const int& bar) {
    // The const modifier prevents any write to a referenced
    // variable. Try uncomment the following line and compile
    // the program
    // bar = 7;
    std::cout << "callee: foo_const_ref(my_bar) prints " << bar << '\n';
    // When you want to use the reference to save time and space, but
    // do not want to modify that variable, use the const keyword to
    // protect it
}

int main() {
    // Here we declear a variable of type int (integer), and give it a name
    // my_bar, but the value is unspecified
    // C++ is statically typed so you must say the type of the variable when
    // creating it, this is very different from Python
    int my_bar;

    // Here we assign 5 to the variable by using the assignment operator
    my_bar = 5;

    // Print the initial value of my_bar, should be 5, no surprises
    std::cout << "caller: my_bar = " << my_bar << '\n';

    // Invoke the foo() function by passing my_bar to it
    foo(my_bar);

    // Check, have we modified the caller's my_bar?
    std::cout << "caller: after calling foo(my_bar), my_bar = " << my_bar << '\n';

    // Invoke the foo_ref() function by passing my_bar to it
    foo_ref(my_bar);

    // Check again, have we modified the caller's my_bar?
    std::cout << "caller: after calling foo_ref(my_bar), my_bar = " << my_bar << '\n';

    // This is just for showing how to use the const keyword, try uncomment the line in the funciton
    foo_const_ref(my_bar);
}
