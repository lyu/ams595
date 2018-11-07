#include <iostream>

int main() {
    int j = 10;

    // A while loop, not very different from the Python equivalent
    while (j > -1) {
        std::cout << j << ' ';
        j -= 1;
    }

    std::cout << '\n';
}
