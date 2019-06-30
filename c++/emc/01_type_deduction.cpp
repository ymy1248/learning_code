#include <iostream>

template <typename T>
void fRef(T& param) {}

template <typename T>
void fConstRef(const T& param) {}

template <typename T>
void fPtr(T* param) {}

template <typename T>
void fUR(T&& param) {}

int main()
{
  int x = 27;
  const int cx = x;
  const int &rx = x;
  const int *px = &x;

  fRef(x);          // T is int, param's type is int&
  fRef(cx);         // T is const int, param's type is const int&
  fRef(rx);         // T is const int, param's type is const int&

  fConstRef(x);     // T is int, parm's type is const int&
  fConstRef(cx);    // T is int, parm's type is const int&
  fConstRef(rx);    // T is int, parm's type is const int&
  // No need to for *const* to be deduced as part of T
  

  fPtr(&x);         // T is int, param's type is int*
  fPtr(px);         // T is const int, param's type is const int*

  fUR(x);           // x is lvalue, T is int&
                    // param's type is int&
  fUR(cx);          // cx is lvalue, so T is const int&
                    // param's type is also const int&
  fUR(rx);          // rx is lvalue, so T is const int&
                    // params's type is also const int&
  fUR(27);          // 27 is rvalue, so T is int,
                    // param's type is therefore int&&
}
