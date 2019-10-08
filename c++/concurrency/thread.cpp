#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m1;

void func1()
{
  m1.lock();
  for (int i = 0; i < 100; ++i) {
    cout << "*";
  }
  cout << endl;
  m1.unlock();
}

void func2()
{
  m1.lock();
  for (int i = 0; i < 100; ++i) {
    cout << "-";
  }
  cout << endl;
  m1.unlock();
}

int main()
{
  thread t1(func1);
  thread t2(func2);

  t1.join();
  t2.join();
}
