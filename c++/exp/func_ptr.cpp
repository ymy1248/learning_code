#include <iostream>

void (*func)(int);

void testPrint(int n) {
    printf("%d\n", n);
}

int main() {
    func = testPrint;
    func(1);
}
