#include <iostream>

using namespace std;

void* operator new(std::size_t size) throw (std::bad_alloc) 
{
  cout << "customized operator new, size: " << size << endl;

  void *p;
  if (size ==  0) {
    size = 1;
  }

  while (true) {
    p = malloc(size);
    if (p) return p;

    new_handler globalHandler = set_new_handler(0);
    set_new_handler(globalHandler);

    if (globalHandler) (*globalHandler)();
    else throw std::bad_alloc();
  }
}

class A {
  int num;
};

class Base {
public:
  static void* operator new(std::size_t size) throw(std::bad_alloc) {
    if (size != sizeof(Base))
      return ::operator new(size);
    cout << "Base::new" << endl;
    return ::operator new(size);
  }

private:
  int num;
};

class Derived : public Base {
private:
  int num;
  float f;
};



int main() {
  cout << "Test global new" << endl;
  A *a = new A();

  cout << endl << "Test member new" << endl;
  Base *b = new Base();

  cout << endl << "Test deried" << endl;
  Derived *d = new Derived();
}
