#include <iostream>

enum class Color : uint8_t;


int main() {
  Color c = Color::black;
}

enum class Color : uint8_t{
  white = 0,
  black,
  red
};
