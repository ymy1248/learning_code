#include<iostream>

using namespace std;

class Rational {
public:
    Rational(int num = 0, int den = 1) :
        n(num),
        d(den)
    {
        cout << "constructor" << endl;
        cout << "n: " << n << ", d: " << den << endl;
    };
    int numerator() const;
    int denominator() const;
    // const Rational operator*(const Rational &r) const {
    //     cout << "Operator*" << endl;
    //     return r;
    // };
private:
    int n;
    int d;
};

const Rational operator*(const Rational &l, const Rational &r) {
    cout << "operator*(const Rational &l, const Rational &r)" << endl;
    return l;
}
int operator*(const Rational &l, const int &r) {
    cout << "operator*(const Rational &l, const int &r)" << endl;
    return r;
}

int main() {
    Rational r1 (1, 2);
    r1 * 2;
    2 * r1;
}
