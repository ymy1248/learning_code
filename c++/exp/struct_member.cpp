#include <iostream>

using namespace std;

struct STRUCT{
    int a;
    int b;
};

int main() {
    STRUCT s;
    cout << &s << endl;
    cout << &s.b << endl;
}
