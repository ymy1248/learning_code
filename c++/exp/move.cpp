#include <iostream>
#include <vector>

using namespace std;
template <unsigned int size>
class MemoryChunk {
public:
    char chunk[size];
};

class MemoryChunkMove {
public:
    size_t _size;
    char *_ptr;
    
    MemoryChunkMove() : _size(0), _ptr(nullptr)
    {
        // cout << "Default ctor." << endl;
    }
    
    MemoryChunkMove(size_t size) : _size(size)
    {
        // cout << "ctor size:" << _size << endl;
        _ptr = new char[_size];
    }

    MemoryChunkMove(const MemoryChunkMove &that) : _size(that._size)
    {
        // cout << "copy ctor." << endl;
        _ptr = new char[_size];
        // memcpy(_ptr, that._ptr, _size);
        std::copy(that._ptr, that._ptr + _size, _ptr);
    }
    
    MemoryChunkMove(MemoryChunkMove &&that) noexcept : _size(that._size), _ptr(that._ptr)
    {
        // cout << "move ctor." << endl;
        that._size = 0;
        that._ptr = nullptr;
    }
    ~MemoryChunkMove()
    {
        // cout << "dtor" << endl;
        delete[] _ptr;
    }
    
};

static const unsigned int MEM_SIZE = 2048;
int main() {
    // vector<MemoryChunkMove> v;
    // MemoryChunkMove m (10);
    // v.push_back(m);
    // v.push_back(m);
    
    using milli = std::chrono::milliseconds;
    auto start = std::chrono::high_resolution_clock::now();
    
    MemoryChunk<MEM_SIZE> m;
    vector<MemoryChunk<MEM_SIZE>> v1;
    for (int i = 0; i < 100000; ++i) {
        v1.push_back(m);
    }
    
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << "Without move took "
              << std::chrono::duration_cast<milli>(finish - start).count()
              << " milliseconds\n";
    
    
    start = std::chrono::high_resolution_clock::now();
    vector<MemoryChunkMove> v2;
    MemoryChunkMove mcm(MEM_SIZE);
    for (int i = 0; i < 100000; ++i) {
        v2.push_back(mcm);
    }
    finish = std::chrono::high_resolution_clock::now();
    std::cout << "With move took "
              << std::chrono::duration_cast<milli>(finish - start).count()
              << " milliseconds\n";
}
