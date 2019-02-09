// Predict the output of this program
#include <iostream>


class Foo {
    public:
        int x;

        Foo(int val = 0) {
            x = val;
            std::cout << "Construct " << x << '\n';
        }

        Foo(const Foo &obj) {
            x = obj.x;
            std::cout << "Copy construct " << x << '\n';
        }

        ~Foo() {
            std::cout << "Destruct " << x << '\n';
        }

        void operator++() { x++; }

        friend Foo operator+(const Foo& a, const Foo& b) {
            Foo tmp;
            tmp.x = a.x + b.x;
            return tmp;
        }
};


void bar(const Foo i) {
    static Foo s3 = i + 1;
    ++s3;
}


int main() {
    Foo s1, s2(1);
    bar(s1);
    bar(2);
}
