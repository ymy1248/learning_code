#include <iostream>
#include <vector>

using namespace std;

class Num {
public:
  int n;
};

// for avoiding the mistype if (a * b = c)
const int operator*(const Num& a, const Num& b) {
  return a.n * b.n;
}

int main(){
  char greeting[] = "Hello";

  char * p1 = greeting;                 // non-const pointer, non-const data
  const char * p2 = greeting;           // non-const pointer, const data
  char * const p3 = greeting;           // const pointer, non-const data
  const char * const p4 = greeting;     // const pointer, const data

  const char * p5 = greeting;
  char const * p6 = greeting;           // these two are the same

  vector<int> v1(10);
  const vector<int> v2(10);
  const vector<int>::iterator it1 = v1.begin();
  vector<int>::const_iterator it2 = v1.begin();
  // vector<int>::iterator it3 = v2.begin();      // error for non-const
  vector<int>::const_iterator it4 = v2.begin();
}
