#include <stdio.h>
#include <string.h>

void foo (const char** strs) {
}

int main() {
    // c string in cpp is const char* instread of char *, we can't directlly write into it.
    char* str = const_cast<char*>("Hello World!");
    // Don't do this, SIGV
    // str[1] = 'a';
    // printf("%s\n", str);
    char str_arr[] = "Hello World!";
    str_arr[0] = 'A';
    printf("%s\n", str_arr);

    const int n = 0;
    int *ptr = &n;
    const char* test = str;
    char * test2 = test;
    printf("%s\n", test);

    const char** strs = new const char* [2];
    const char** s = strs;
    foo(strs);
    return 0;
}

