// It’s useful to approach std::move and std::forward in terms of what they don’t do. std::move 
// doesn’t move anything. std::forward doesn’t forward anything. At run‐ time, neither does anything 
// at all. They generate no executable code. Not a single byte.

#include <iostream>
#include <string>

using namespace std;

class MemoryChunk {
public:
  MemoryChunk() :
    _ptr(nullptr),
    _size(0)
  {
    cout << "Default ctor" << endl;
  }

  MemoryChunk(size_t size) :
    _size(size) 
  {
    _ptr = new char[size];
  }

  MemoryChunk(MemoryChunk &&that) noexcept:
    _size(that._size) {
      cout << "Move ctor" << endl;
      _ptr = that._ptr;
      that._size = 0;
      that._ptr = nullptr;
  }

  MemoryChunk(MemoryChunk &that) :
    _size(that._size)
  {
    cout << "Copy ctor" << endl;
    _ptr = new char[_size];
    std::copy
  }


  char *_ptr;
  size_t _size;
};

int main() {
}
