// This example is used to show how the compiler compiles C++ code
// and how the debugger work
//
// Use "g++ -std=c++11 -E day6_test.cpp > day6_test_new.cpp" to see how the preprocessor work
// Use "clang++ -std=c++11 -S -emit-llvm day6_test.cpp" to see the generated LLVM IR (you need clang++)
// Use "g++ -std=c++11 -S -masm=intel -fverbose-asm day6_test.cpp" to see what the generated x86 assembly

#include <iostream>

void foo(int a[], int len) {
    for (int i = 0; i < len; i++)
        a[i] = i;
}

int bar(int a[], int len) {
    int result = 0;

    if (a[len - 1] < 5) {
        result = -1;
    } else if (a[len - 1] > 7) {
        result = 0;
    } else {
        result = 1;
    }
    return result;
}

int main() {
    int N = 8;
    int a[N];
    foo(a, N);

    std::cout << bar(a, N) << '\n';
}
