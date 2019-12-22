#include<iostream>

using namespace std;

class A {
public:
    int a;
    int b;
    A();
};

class B { 
public:
    int a;
    int b;
    virtual ~B();
};

int main() {
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
}
