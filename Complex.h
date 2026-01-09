#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex();
    Complex(double r, double i);

    Complex add(const Complex& other);
    Complex sub(const Complex& other);
    Complex mul(const Complex& other);
    Complex div(const Complex& other);
    double magnitude() const;

    double getReal() const { return real; }
    double getImag() const { return imag; }
};

#endif
