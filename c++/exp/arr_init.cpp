#include <iostream>

int main() {
    // specify length, no init.
    int a1[10];
    // init a2[0] = 1 others 0
    int a2[10] = {1};
    // init all
    int a3[] = {0,1,2,3,4};
    // specify length and init all to 0
    int *a4 = new int [10] ();
    // specify length and no iniit
    int *a5 = new int [10];
}
