#include <iostream>

using namespace std;

class Foo {
public:
  // compiler still makes a default constructor.
  Foo() = default;
  Foo(int a) : _a(a) {};

  // this copy constructor is deleted not callable.
  Foo(const Foo &f) = delete;
  int _a;
};

int main() {
  Foo f;
  cout << f._a << endl;

  // error due to deleted copy constructor.
  // Foo f1(f);
  // Foo f1 = 1;
}
