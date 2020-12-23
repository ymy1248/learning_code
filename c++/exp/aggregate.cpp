#include <iostream>
#include <array>

using namespace std;

class ArrMmrf : public array<float, 4>
{
  public:
  ArrMmrf(float a, float b, float c, float d) {
    operator[](1) = a;
    operator[](2) = b;
    operator[](3) = c;
    operator[](4) = d;

  }
};

int main() {
  // for std array it is aggregate class, aggregate initialization can be used.
  array<float, 4> a {0, 1, 2, 3};
  array<float, 4> a1 = {0, 1, 2, 3};
  // but for derived class, in c++14, aggregate initialization is not allowed.
  ArrMmrf b {0, 1, 2, 3};
}
