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

template<typename IterT, typename DistT>
void advance(IterT& iter, DistT d, std::random_access_iterator_tag)
{
  cout << "random_access_iterator_tag function" << endl;
  iter += d;
}

template<typename IterT, typename DistT>
void advance(IterT& iter, DistT d, std::bidirectional_iterator_tag)
{
  cout << "bidirectional_iterator_tag function" << endl;
  if (d >= 0) { while (d--) ++iter; }
  else {while (d++) --iter; }
}

template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d)
{
  advance(iter, d, typename std::iterator_traits<IterT>::iterator_category());
}


int main (){
  vector<int> nums(10, 0);
  list<int> l;
  auto it_l = l.begin();
  auto it = nums.begin();
  advance(it, 10);
  advance(it_l, 10);
  advance(it_l, 10, iterator_traits<list<int>::iterator>::iterator_category());
  doAdvance(it, 10);
  return 0;
};
