#include <iostream>

using namespace std;

// enum color;
// can't do forward-declared

enum class Scoped_Color : std::uint8_t; 
// forward declaring can reduce compile time if we add a new enumerator.
// extend std::uint8_t specifyies the type of enum

enum Color {
  Black,
  White,
  Red
};

Color c = Black;
// auto White = false;
// error: redefine name already been used

enum class Scoped_Color : std::uint8_t{
  black,
  white,
  red
};

Scoped_Color sc = Scoped_Color::black;
auto white = false;

int main() {
  if (c < 12.4) {
  }
  if (static_cast<float>(sc) < 12.4) { // have to use static cast!!!
  }
}
