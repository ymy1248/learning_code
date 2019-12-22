#include <iostream>

struct C_s{
    int a;
    int b;
};

struct Cpp_s{
    int a;
    int b;
    Cpp_s() : a(0), b(0) {}

    void print() {
        printf("%d", a);
        printf("%d", b);
    }
};

int main(){
    C_s c_s;
    c_s.a = 1;
    c_s.b = 1;
    Cpp_s* cpp_s = reinterpret_cast<Cpp_s*>(&c_s);
    printf("%d", cpp_s->a);
}
