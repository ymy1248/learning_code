#include <iostream>

using namespace std;

void* operator new(std::size_t size) throw (std::bad_alloc) 
{
  cout << "customized global operator new, size: " << size << endl;

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

void operator delete(void *rawMemory) throw()
{
  cout << "customized global operator delete" << endl;
  if (!rawMemory) return;
  free(rawMemory);
}

class A {
  int num;
};

class Base {
public:
  static void* operator new(std::size_t size) throw(std::bad_alloc)
  {
    if (size != sizeof(Base))
      return ::operator new(size);
    cout << "Base::new" << endl;
    return ::operator new(size);
  }

  static void operator delete(void* rawMemory, size_t size) throw() // size_t is necessary
  {
    cout << "cutomized member operator delete" << endl;
    if (rawMemory == 0) return;
    if (size != sizeof(Base)) {       // check memory size
      ::operator delete(rawMemory);
      return;
    }
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
  delete a;

  cout << endl << "Test member new" << endl;
  Base *b = new Base();
  delete b;

  cout << endl << "Test deried" << endl;
  Derived *d = new Derived();
  delete d;
}
