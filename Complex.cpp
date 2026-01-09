#include "Complex.h"
#include <cmath>
#include <stdexcept>

Complex::Complex() : real(0), imag(0) {}
Complex::Complex(double r, double i) : real(r), imag(i) {}

Complex Complex::add(const Complex& other) {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::sub(const Complex& other) {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::mul(const Complex& other) {
    double r = real * other.real - imag * other.imag;
    double i = real * other.imag + imag * other.real;
    return Complex(r, i);
}

Complex Complex::div(const Complex& other) {
    double denom = other.real * other.real + other.imag * other.imag;
    if (denom == 0) throw runtime_error("Division by zero");
    double r = (real * other.real + imag * other.imag) / denom;
    double i = (imag * other.real - real * other.imag) / denom;
    return Complex(r, i);
}

double Complex::magnitude() const {
    return sqrt(real * real + imag * imag);
}
