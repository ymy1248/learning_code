#include <memory>
#include <functional>
#include <unordered_map>

using namespace std;
class A {
public:
  int count;
  bool operator<(const A &rhs) { return count < rhs.count; }
};

int main()
{
  // use less memory and faster than std function.
  auto derefUPLess1 = [](const std::unique_ptr<A> &p1,
                        const std::unique_ptr<A> &p2)
                        { return *p1 < *p2; };

  // although this std::function can still get lambda, but the memory it used is not optimized, it is
  // generally bigger and slower than auto
  std::function<bool (const std::unique_ptr<A>&, std::unique_ptr<A> &)>
  derefUPLess2 = [](const std::unique_ptr<A> &p1,
                        const std::unique_ptr<A> &p2)
                        { return *p1 < *p2; };
  unordered_map<string, int> m;

  // should be pair<const string, int> this will make a copy of pair
  // explicitly specifying types can lead to implicit conversions that you neither want nor expect
  for (const std::pair<string, int> &p : m) {
  }

  // auto is an option instead of a mandate. for readability, we can explicitly declare type.
}
