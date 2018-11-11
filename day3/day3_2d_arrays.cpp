#include <iostream>
#include <cstdint>

// Passing 2D arrays to functions does not work as expected
// Uncomment all the commented lines (including the line in the main function),
// and compile the program to see the error.
// Personally, I never use this way to create 2D arrays
// int foo(int16_t mat[][], int M, int N) {
//     return mat[0][0];
// }

int main() {
    int N = 4;
    // Declaring 2D arrays, the syntax is "<typename> <array_name>[<height>][<width>]
    int16_t matrix[N][N];

    // Array indexing, as expected
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            matrix[i][j] = i * N + j;

    // Print our matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            std::cout << matrix[i][j] << ' ';

        std::cout << '\n';
    }

    // C/C++ stores arrays in the row-major order, which means:
    //      Store each row in consecutive memory locations

    // Print the address of matrix[0][0], the & operator takes the memory address
    // of a variable
    std::cout << &matrix[0][0] << '\n';
    // matrix[0][0] and matrix[0][1] are neighbors in the same row, so the difference
    // between their addresses is only 2 (2 Bytes to store an int16_t)
    std::cout << &matrix[0][1] << '\n';
    // matrix[0][0] and matrix[1][0] are neighbors in the same column, so in the memory,
    // there are three more int16_t's from row 0 between them, therefore the difference
    // between their addresses is 8 (4 * 2 Bytes to store 4 int16_t)
    std::cout << &matrix[1][0] << '\n';

    // std::cout << foo(matrix) << '\n';
}
