#include <iostream>
#include <vector>

using namespace std;


template<typename Container, typename Index>
decltype(auto) authAndAccess(Container &&c,     // universal reference to avoid rvalue copy
                             Index i)
// deduced return type in C++14. It returns exactly the same type as c[i]. In vector<int>, it is int &.
{
  return std::forward<Container>(c)[i];         // forward to avoid copying further
}

auto func() -> int
{
// the "auto ->" thing is C++11’s trailing return type 
  return 10;
} 

int main ()
{
  // In C++11, perhaps the primary use for decltype is declaring function templates where the 
  // function’s return type depends on its parameter types. for example, and it’s almost always the 
  // case for std::vector. For std::vector<bool>, however, operator[] does not return a bool&. 
  // Instead, it returns a brand new object. 
  cout << func() << endl;

  vector<int> v (10, 0);
  cout << authAndAccess(v, 9) << endl;

  int n = 10;
  const int &cn = n;
  auto my_n = cn;            // int
  decltype(auto) my_cn = cn; // const int &

  // for lvalue expressions, decltype ensures that the type reported is always an lvalue reference.
  decltype((n)) a = n;      // a is int&
}
