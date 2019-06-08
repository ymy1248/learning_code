#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename IterT, typename DistT>
void advance(IterT& iter, DistT d)
{
  const type_info &id = typeid(typename std::iterator_traits<IterT>::iterator_category);
  if (id == typeid(std::random_access_iterator_tag)) {
    cout << "This is a random access iter: " <<d << endl;
  } else {
    cout << "This is NOT a random access iter: " << d << endl;
  }
}

int main (){
  vector<int> nums(10, 0);
  list<int> l;
  auto it_l = l.begin();
  auto it = nums.begin();
  advance<vector<int>::iterator, size_t>(it, 10);
  advance<list<int>::iterator, size_t>(it_l, 10);
  return 0;
};
