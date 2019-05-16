#include <iostream>

using namespace std;

struct Complex {
    int real;
    int imaginary;

    Complex(int a, int b) {
        real = a;
        imaginary = b;
    }
};

ostream &operator<<(ostream &s, const Complex &t) {
    if (t.real != 0) {
        s << t.real;
        if (t.imaginary > 0) {
            s << " + ";
        }
        if (t.imaginary < 0) {
            s << " - ";
        }
    }

    if (t.imaginary > 0) {
        s << t.imaginary << "i";
    } else if (t.imaginary < 0) {
        if (t.real == 0) {
            s << t.imaginary << "i";
        } else {
            s << t.imaginary * -1 << "i";
        }
    }

    return s;
}

Complex operator+(const Complex &x, const Complex &y) {
    return Complex(x.real + y.real, x.imaginary + y.imaginary);
}
Complex operator-(const Complex &x, const Complex &y) {
    return Complex(x.real - y.real, x.imaginary - y.imaginary);
}
Complex operator*(const Complex &x, const Complex &y) {
    return Complex(x.real * y.real - x.imaginary * y.imaginary,
                   x.real * y.imaginary + y.real * x.imaginary);
}

int main() {
    Complex a = Complex(10, 10);
    Complex b = Complex(1, 10);
    Complex v = Complex(1, 3);
    Complex e = Complex(0, 3);
    Complex f = Complex(2, 0);
    Complex g = Complex(2, -20);
    Complex h = Complex(0, -20);
    cout << e << endl;
    cout << f << endl;
    cout << g << endl;
    cout << h << endl;
}
