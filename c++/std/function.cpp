#include <iostream>
#include <functional>

using namespace std;
int myminus(int i, int j)
{
  return i - j;
}

int main() 
{
  function<int(int, int)> foo = myminus;
  cout << foo(1, 1) << endl;
  return 1;
}
