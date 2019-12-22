#include <iostream>

class Widget{
private:
  int d_n;

  // error in c++98, not an error begins c++11. non-trival functions are not supported in union.
  Widget() : d_n(0) {}; 
};

union U {
  Widget w;
  float f;
  int i;
}__attribute__((packed));

int main() {
  U u;
}
