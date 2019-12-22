#include <iostream>

using namespace std;

class Base {
public:
    virtual ~Base(){};
    void func() {
        cout << "func()" << endl;
    }
    virtual void funcA() {
        cout << "Base::funcA()" << endl;
    }
    virtual void funcB() = 0;
};

class Derived : public Base {
public:
    ~Derived(){};
    // void funcA() {
    //     cout << "funcA()" << endl;
    // }

    virtual void funcB() = 0;
    // void funcB() {
    //     cout << "funcB()" << endl;
    // }
};

int main() {
    Derived d;

    d.funcA();
}
