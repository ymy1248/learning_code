#include <memory>
#include <unordered_map>
#include <string>
#include <list>

template<typename T>
class MyAlloc;

// typedef std::unique_ptr<std::unordered_map<std::string, std::string>> UPtrMapSS;
using UPtrMapSS = std::unique_ptr<std::unordered_map<std::string, std::string>>;

// easier understand for function pointer.
// typedef void(*FP)(int, const std::string&);
using FP = void (*)(int, const std::string&);

// for compiling reason, alias templates
template<typename T>
using MyAllocList = std::list<T, MyAlloc<T>>;

template<typename T>
struct MyAllocList_t {
  typedef std::list<T, MyAlloc<T>> type;
};

template<typename T>
class Widget {
private:
  typename MyAllocList_t<T>::type list; // typename is necessary
  MyAllocList<T> lw;    // using is more convenient
};

int main() 
{
  MyAllocList<int> lw;
  MyAllocList<int>::type lw;
}
