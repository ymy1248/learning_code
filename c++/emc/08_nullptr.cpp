#include <iostream>
#include <thread>
#include <memory>

using namespace std;
using MuxGuard = std::lock_guard<std::mutex>;

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

int f1(std::shared_ptr<Widget> spw) { return 0; }
int f2(std::unique_ptr<Widget> upw) { return 0; }
bool f3(Widget *pw) { return false; }

template<typename Func,
         typename Mux,
         typename Ptr>
decltype(auto) lockAndCall(Func func,
                           Mux &mutex,
                           Ptr ptr)
{
  MuxGuard g(mutex);
  return func(ptr);
}

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
  {
    MuxGuard g(f1m);
    auto result = f1(0);
  }
  {
    MuxGuard g(f2m);
    auto result = f2(NULL);
  }
  {
    MuxGuard g(f3m);
    auto result = f3(nullptr);
  }
  // TODO why error?
  // auto result1 = lockAndCall(f1, f1m, 0);        // error
  // auto result2 = lockAndCall(f2, f2m, NULL);     // error
  auto result3 = lockAndCall(f3, f3m, nullptr);
}
