#include <iostream>
#include <vector>

using namespace std;
class Widget 
{
public:
    Widget()
    {
        cout << "default constructor" << endl;
    }
    Widget(int i, bool b)
    {
        cout << "ctor int, bool" << endl;
    }
    Widget(int i, double d)
    {
        cout << "ctor int, double" << endl;
    }
    Widget(const Widget &w)
    {
        cout << "copy constructor" << endl;
    }
    Widget(initializer_list<long double> il)
    {
        cout << "ctor initializer_list\n" << endl;
    }
    
    void operator=(const Widget &w) 
    {
        cout << "assignment" << endl;
    }
    operator float() const
    {
        printf("float converted\n");
        return 1.0;
    }
};
class Widget_str 
{
public:
    Widget_str()
    {
        cout << "default constructor" << endl;
    }
    Widget_str(int i, bool b)
    {
        cout << "ctor int, bool" << endl;
    }
    Widget_str(int i, double d)
    {
        cout << "ctor int, double" << endl;
    }
    Widget_str(const Widget &w)
    {
        cout << "copy constructor" << endl;
    }
    Widget_str(initializer_list<string> il)
    {
        cout << "ctor initializer_list\n" << endl;
    }
    
    void operator=(const Widget_str &w) 
    {
        cout << "assignment" << endl;
    }
    operator float() const
    {
        printf("float converted\n");
        return 1.0;
    }
};

int main() 
{
    int x(0);
    int y = 0;
    int z {0}; // which is equal to int z = {0};
    
    cout << x << "," << y << "," << z << endl;
    Widget w1;
    Widget w2 = w1;
    w1 = w2;
    
    // advantage:
    // uniform initialization, in concept, it should be used everywhere
    vector<int> v {1,3,5};
    
    // prohibits implicit narrowing conversions
    double a = 1.1, b = 1.2, c = 3.2;
    // int sum1 {a + b + c}; // got warning: narrowing conversion
    int sum2 = a + b + c;
    int sum3 (a + b + c);
    printf("%d %d\n", sum2, sum3);
    
    Widget w3(); // declaring a function instead of calling constructor
    Widget w4{}; // call Widget ctor with no args instead of init list
    Widget w11({}); // call initializer_list ctor with empty
    Widget w12{{}}; // ditto
    
    printf("braced init initializer_lists disadvantage!!!\n");
    Widget w5(10, true);
    Widget w6{10, true}; // now calls initializer_list ctro, 10 true are converted to long double
    Widget w7(10, 5.0);
    Widget w8{10, 5.0}; // ditto
    Widget w9(w5);
    Widget w10{w5}; // first w5 is converted to float, then float calls the initializer_list ctro
    // compilers prefer initializer_list, as long as it can covert to template types, more than any other ctor if we use braces initialization
    Widget_str s1{10, true}; // can't convert int and bool to string

	// First, as a class author, you need to be aware that if your set of overloaded constructors 
 	// includes one or more functions taking a std::initializer_list, client code using braced 
	// initialization may see only the std::initializer_list overloads. 
	// std::initializer_list overload doesn’t just compete with other overloads, it overshadows them 
	// to the point where the other overloads may hardly be considered

	// The second lesson is that as a class client, you must choose carefully between parentheses 
	// and braces when creating objects. 
}
