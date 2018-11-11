#include <iostream>
#include <cmath>

// In day 2, we have learned that both int64_t and double use 8 Bytes to store a number
// But the type double can store numbers up to 1.78e308, which is much much bigger than
// what int64_t or even uint64_t can do. So, can we use a double as a loop variable and
// thus supporting much longer loops?
// The answer is no. You can only store so much information in 8 Bytes (64 bits),
// floating-point types sacrificed a lot to support bigger ranges, making them
// unsuitable for counting.
// This is not C++'s flaw, if you translate this program to Python, you should see the
// same results
int main() {
    // This should work
    if (1 + 2 == 3) {
        std::cout << "1 + 2 == 3? Yes!\n";
    } else {
        std::cout << "1 + 2 == 3? No!\n";
    }

    // This also works
    if (1.0 + 2.0 == 3.0) {
        std::cout << "1.0 + 2.0 == 3.0? Yes!\n";
    } else {
        std::cout << "1.0 + 2.0 == 3.0? No!\n";
    }

    // And this fails
    if (1.1 + 2.2 == 3.3) {
        std::cout << "1.1 + 2.2 == 3.3? Yes!\n";
    } else {
        std::cout << "1.1 + 2.2 == 3.3? No!\n";
    }

    // When you write 1.1, the computer will store a number that is very very close
    // to it, due to hardware limitations. Because of this, you should never expect
    // == to work for floating pointer numbers.
    // The correct way to do it is to use the fp-absolute value function fabs to get
    // the absolute value of their difference, and compare that difference with an
    // error tolerance
    if (std::fabs(1.1 + 2.2 - 3.3) < 1e-10) {
        std::cout << "|1.1 + 2.2 - 3.3| ~ 0.0? Yes!\n";
    } else {
        std::cout << "|1.1 + 2.2 - 3.3| ~ 0.0? No!\n";
    }

    // Now that we know how not to compare floating-point numbers, let me show you
    // why they are not suited for counting
    for (int i = 0; i < 50; i++) {
        // Let x be 10^i
        double x = std::pow(10, i);

        // If we have exact math, ((x + 1) - x) = 1 > 1e-10 is always true
        // Nothing should be printed
        if (std::fabs((x + 1.0) -x) < 1e-10) {
            std::cout << "Your CPU cannot tell the difference between " << x
                      << " + 1.0 and " << x << '\n';
            break;
        }
    }
    // The test will fail, in fact, if you remove "break;", you will see a lot of fails,
    // if you let x be a float instead of a double, even more fails will appear
    // Therefore, if a dobule is used as a loop variable, adding one to it will have no
    // effect after a certain number of iterations, and so you loop never terminates
}
// Lessons:
//  1. Never use == to compare two fp numbers, unless you are testing for the underlying bit representations
//  2. If one fp number is many orders of magnitude larger than the other one, do not add/subtract them,
//     otherwise the smaller one will be thrown away
