#include <iostream>

using namespace std;

class Widget {
public:
  // declare as public
  // comparing with undefined private funciton, delete functions report error in compile time instead
  // of link-time for friend class.
  Widget& operator=(const Widget &w) = delete;

  // any function can be deleted, prevent implicitly converting
  bool isLucky(int number) { return number == 7; }
  bool isLucky(char) = delete;
  bool isLucky(bool) = delete;
  bool isLucky(double) = delete;
};

template<typename T>
void processPointer(T *ptr);

// delete a template specialization function
template<>
void processPointer<void>(void*) = delete;
// delete const void* is necessary
template<>
void processPointer<const void>(const void*) = delete;

int main() {
  Widget w;
  // compile error if double function is deleted
  // w.isLucky(10.3); 
  w.isLucky(10);
}
