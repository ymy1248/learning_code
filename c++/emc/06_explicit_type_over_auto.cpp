#include <iostream>
#include <vector>

using namespace std;
void printFlag(bool);
vector<bool> getFlags(bool);

int main()
{
  // The flag_auto is proxy object (vector<bool>::reference) instead of bool. And it is depends on
  // the temporary return object which already destroyed.
  auto flag_auto = getFlags(false)[5];
  printFlag(flag_auto);
  auto flag_auto_b = static_cast<bool>(getFlags(true)[5]);
  // undefined behavior due to temporary return object was already destroyed, but we use the copy of
  // the proxy object as input.
  printFlag(flag_auto);
  printFlag(flag_auto_b);

  vector<bool> vec (10, true);
  for (auto b : vec) {
    // We expect to get a copy bool and not a reference. Same reason as previous example, a proxy
    // object is got in this for loop. And we changed the content of this vector.
    b = false;
  }

  for (auto b : vec) {
    cout << b << " ";
  }
  cout << endl;
}

void printFlag(bool flag)
{
  cout << "printFlag: " << flag << endl;
}

vector<bool>  getFlags(bool flag)
{
  return vector<bool> (10, flag);
}
