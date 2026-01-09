#include <iostream>
#include <iomanip>
#include <regex>
#include "Complex.h"
using namespace std;

bool parseComplex(const string &s, Complex &c) {
    regex pattern(R"(^([+-]?\d+(\.\d+)?)([+-]\d+(\.\d+)?)i$)");
    smatch match;

    if (!regex_match(s, match, pattern))
        return false;

    double r = stod(match[1].str());
    double i = stod(match[3].str());
    c = Complex(r, i);
    return true;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "ERROR: Invalid arguments";
        return 0;
    }

    string op = argv[1];
    Complex c1, c2;

    if (op == "magnitude") {
        if (argc != 3) {
            cout << "ERROR: Invalid arguments";
            return 0;
        }
        if (!parseComplex(argv[2], c1)) {
            cout << "ERROR: Invalid complex number";
            return 0;
        }
        cout << fixed << setprecision(6) << c1.magnitude();
        return 0;
    }

    if (argc != 4) {
        cout << "ERROR: Invalid arguments";
        return 0;
    }

    if (!parseComplex(argv[2], c1) || !parseComplex(argv[3], c2)) {
        cout << "ERROR: Invalid complex number";
        return 0;
    }

    try {
        Complex result;
        if (op == "add") result = c1.add(c2);
        else if (op == "sub") result = c1.sub(c2);
        else if (op == "mul") result = c1.mul(c2);
        else if (op == "div") result = c1.div(c2);
        else {
            cout << "ERROR: Unknown operation";
            return 0;
        }

        double r = result.getReal();
        double i = result.getImag();

        cout << fixed << setprecision(6) << r
             << ((i >= 0) ? "+" : "") << fixed << setprecision(6) << i << "i";
    }
    catch (...) {
        cout << "ERROR: Division by zero";
    }

    return 0;
}
