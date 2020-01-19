#include <fstream>
#include <iostream>

using std::ifstream, std::ios, std::cout, std::endl, std::hex, std::dec;

int main() {
    ifstream file("resources/HelloWorld.class", ios::binary);

    uint8_t buffer[4];
    for (auto i = 4 - 1; i >= 0; --i) {
        buffer[i] = file.get();
    }

    cout << hex << *reinterpret_cast<uint32_t*>(buffer) << dec << endl; // magic

    return 0;
}
