#include <iostream>

using namespace std;

struct Widget {
  char d_c;
  int d_n;
};

class Test {
  Widget d_w;
  int d_n;
}__attribute__((packed));

int main() {
  cout << sizeof(Test) << endl;
}
