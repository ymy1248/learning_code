#include <iostream>

using namespace std;

int main() {
  // these three auto types act like template function T
  // three cases:
  // 1: The type specifier is a pointer or reference, but not a universal reference.
  // 2: The type specifier is a universal reference.
  // 3: The type specifier is neither a pointer nor a reference.
  auto x = 27;              // case 3
  const auto cx = x;        // case 3
  const auto &rx = x;       // case 1

  auto&& uref1 = x;         // case 2, x is int and lvalue, uref1 is int&
  auto&& uref2 = cx;        // case 2, cx is const int and lvalue, uref2 is const int&
  auto&& uref3 = 27;        // case 2, 27 is int rvalue, so uref3 is int&&

  const char name[] = "Fun";
  auto arr1 = name;         // arr1 is const char*
  auto &arr2 = name;        // arr2 is const char (&)[3]

  void func(int, double);

  auto x1 = 27;             // type is int, value is 27
  auto x2(27);              // ditto
  auto x3 = {27};           // type is std::initializer_list<int>
  auto x4 {27};             // ditto
}

void func(int, double) {
}
