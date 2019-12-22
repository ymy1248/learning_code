#include <boost/functional/hash.hpp>
#include <unordered_map>

using namespace std;

class Point {
public:
  int d_x;
  int d_y;

  Point(int x, int y) :
    d_x(x),
    d_y(y) {};

  bool operator==(const Point& that) const {
    return d_x == that.d_x && d_y == that.d_y;
  }

};

std::size_t hash_value(const Point &p) {
  std::size_t seed = 0;
  boost::hash_combine(seed, p.d_x);
  boost::hash_combine(seed, p.d_y);
  return seed;
}

int main() {
  unordered_map<Point, int, function<size_t( const Point& p )>> memo;
  memo[Point(0,1)] = 1;
  memo[Point(0,0)] = 1;
}
