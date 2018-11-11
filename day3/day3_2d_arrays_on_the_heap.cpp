#include <iostream>

// This function takes a 1D array of pointers, each of the pointer point to an
// array on the heap, so it can use mat as a matrix
// Using this trick, you can pass 2D, 3D or higher dimension arrays using the
// same syntax of passing 1D arrays
void print_matrix(int* mat[], int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << mat[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

// Now let's try to pass a 2D array to a function, but using a 1D array as the
// input
int main() {
    int N = 4;
    // Here I declare an array of 4 pointers, each of the pointer will point
    // to an array of 4 integers on the heap
    int* mat[N];

    // Allocate those 4 arrays on the heap
    for (int i = 0; i < N; i++)
        mat[i] = new int[N];

    // Now assign values to the entries of the matrix, the syntax is the same
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            mat[i][j] = i * N + j;

    // Pass the 1D array of 4 pointers to a function
    print_matrix(mat, N, N);

    // Proper cleanup
    for (int i = 0; i < N; i++)
        delete [] mat[i];
}
