#include <iostream>

using namespace std;

class A {
public:
    int n;
    A(int num) :
        n (num) 
    {
        cout << "A (int num)" << endl;
    }
    // This default constructor is necessary, otherwise will be a compiler error.
    A() :
        n (0) 
    {
        cout << "Call A default constructor A()" << endl;
    }

    A(int num1, int num2) :
        n (num2)
    {
        cout << "A(int num1, int num2) constructor." << endl;
        cout << "num1:" << num1 << ", num2:" << num2 << endl;
    }

    explicit A(const A &a) :
        n (a.n) 
    {
        cout << "Call A copy constructor A(const A &a)" << endl;
    }
    ~A() {
        cout << "Destructor" << endl;
    }
};

class B {
public:
    A a;
    int n;

    B() :
        a() 
    {
        cout << "B ()" << endl;
    }

    B(int num1, int num2) :
        a(num1, num2)
    {}

    B(A &_a){
        cout << "Call B(A &a)" << endl;
        a = _a;
    }
};

static A a;

int main() {
    A a(10);
    A a2 = 10;
    // A a1 = a; explict for copy constructor! error
    A _a(a);
    B b(a);
    cout << b.a.n << endl;
    B b2(10, 11);
}
