#include <iostream>
#include <thread>

using namespace std;

void func(int) {
  cout << "call func(int)" << endl;
}

void func(bool) {
  cout << "call func(bool)" << endl;
}

void func(void*) {
  cout << "call func(void*)" << endl;
}

void *func() {
  return nullptr;
}

class Widget{
};

int f1(std::shared_ptr<Widget> spw);
int f2(std::unique_ptr<Widget> upw);
bool f3(Widget *pw);

int main()
{
  cout << "func(0):" << endl;
  func(0);
  // cout << "func(NULL):" << endl;
  // error due to ambiguous overload, NULL is 0 instead of a pointer
  // func(NULL);
  cout << "func(nullptr):" << endl;
  func(nullptr);
  // nullptr is std::nullptr_t
  
  auto result = func();
  // no ambiguous for auto nullptr
  // if (result == 0) don't know result is int or ptr
  if (result == nullptr) {
    cout << "result == nullptr" << endl;
  }

  std::mutex f1m, f2m, f3m;
  using MuxGuard = std::lock_guard<std::mutex>;
  {
    MuxGuard g(f1m);
    auto result = f1(0);
  }
}
