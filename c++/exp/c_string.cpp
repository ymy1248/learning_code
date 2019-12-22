#include<iostream>
#include<string>

typedef char* string;

// const string = char* const != const char*
void func1(string str)
{
    std::cout << "char* : " << str << std::endl;
}

void func2(std::string str)
{
    std::cout << "std::string: " << str << std::endl;
}

int main()
{
    func1("func1");
    func2("func2");
    return 0;
}

