#include <fstream>
#include <iostream>

#define read(x) uint8_t buffer[x]; for (auto i = x - 1; i >= 0; --i) buffer[i] = file.get()
#define as_u4 *reinterpret_cast<uint32_t*>(buffer)
#define as_u2 *reinterpret_cast<uint16_t*>(buffer)

using std::ifstream, std::ios, std::cout, std::endl, std::hex, std::dec;

int main() {
    ifstream file("resources/HelloWorld.class", ios::binary);

    { read(4); cout << hex << as_u4 << dec << endl; } // magic
    { read(2); cout << as_u2 << endl; } // minor_version
    { read(2); cout << as_u2 << endl; } // major_version
    { read(2); cout << as_u2 << endl; } // constant_pool_count

    return 0;
}
