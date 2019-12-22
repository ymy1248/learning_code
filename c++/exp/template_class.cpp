#include <iostream>

using namespace std;

static const unsigned int MAX_MSB = 8;

template<int MSB = 8, int LSB = 0>
class Ptr
{
  static_assert(MSB <= MAX_MSB, "TOO LARGE");
public:
  static const int m;
  static const int l;
  static const uintptr_t msb;
  static const uintptr_t lsb;
};

template<int MSB, int LSB>
const int Ptr<MSB, LSB>::m = MSB;

template<int MSB, int LSB>
const int Ptr<MSB, LSB>::l = LSB;

template<int MSB, int LSB>
const uintptr_t Ptr<MSB, LSB>::msb = (((uintptr_t)1 << MSB) - 1) << (64  - MSB);

template<int MSB, int LSB>
const uintptr_t Ptr<MSB, LSB>::lsb = (((uintptr_t)1 << LSB) - 1);

int main() {
  cout << Ptr<10, 5>::m << endl;
  cout << hex << Ptr<8, 4>::msb << "," << Ptr<8,4>::lsb << endl;
}
