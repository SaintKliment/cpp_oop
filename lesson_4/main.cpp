#include <iostream>

using std::cout;
using std::endl;

class Complex {
    double re;
    double im;

public:
    Complex() : re(0.0), im(0.0) { }
    Complex(double real) : re(real), im(0.0) { } // конструктор преобразования
    Complex(double real, double imag) : re(real), im(imag) { }
    
    void get_data(double& re, double& im) {
        re = this->re;
        im = this->im;
    }
    const Complex& add(const Complex& other) {
        this->re += other.re;
        this->im += other.im;
        return *this;
    }  
};

int main() {
    Complex c1; // {} equi c();
    Complex c2 = 0.5; // {0.5} equi c3(0.5);
    Complex c3 {-5.4, 7.8}; // equi c3(-5.4, 7.8);

    c2.add(c3);
    c2.add(123.123); // работает конструктор преобразования if add explicit, то конструктор не будет преобразовывать (не явно) вещ число во временный обьект

    double re, im;
    c2.get_data(re, im);
    cout << re << "\t" << im << endl;

    return 0;
}