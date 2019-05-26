#include <iostream>

using namespace std;

void* operator new(std::size_t size) throw (std::bad_alloc) 
{
  void *p;
  if (size ==  0) {
    size = 1;
  }

  while (true) {
    cout << "alloc size: " << size << endl;
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

int main() {
  A *a = new A();
}
