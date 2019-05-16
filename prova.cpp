#include <iostream>
<<<<<<< HEAD

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
=======
using namespace std;

struct Data {
    int giorno, mese, anno;

    Data(int giorno_, int mese_, int anno_) {
        giorno = giorno_;
        mese = mese_;
        anno = anno_;
    }
};
ostream &operator<<(ostream &s, const Data &d) {
    s << d.giorno << "/" << d.mese << "/" << d.anno;
    return s;
};

int main() {
    Data a = Data(22, 12, 2019);
    cout << a;
>>>>>>> c72c98138cbbe9ae6d338fe260f428c687fcb0cc
}
