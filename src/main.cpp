#include <iostream>
#include <fstream>

#define fget(x) int buffer[x]; for (auto &i : buffer) i = file.get()

using std::ios;

std::ifstream file("resources/HelloWorld.class", ios::binary);

uint32_t read_u4() {
    static_assert(sizeof(uint32_t) == 4);
    fget(4);

    return (buffer[0] << 24 | buffer[1] << 16 | buffer[2] << 8 | buffer[3]);
}

uint16_t read_u2() {
    static_assert(sizeof(uint16_t) == 2);
    fget(2);

    return (buffer[0] << 8 | buffer[1]);
}

int main() {
    std::cout << std::hex << read_u4() << "\n"; // magic

    std::cout << std::dec << read_u2() << "\n"; // minor_version
    std::cout << std::dec << read_u2() << "\n"; // major_version

    const auto constant_pool_count = read_u2();
    std::cout << std::dec << constant_pool_count << "\n";
    {
        fget(2 * sizeof(uint8_t) * (constant_pool_count - 1)); // skipping the constant_pool (cp_info)
    }

    std::cout << std::hex << read_u2() << "\n"; // access_flags

    // ... etc

    return 0;
}
