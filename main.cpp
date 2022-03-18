#include "intArr.hpp"
#include <stdint.h>

int main(int argc, char** argv) {
    bitArray<int> test(3);
    std::cout << test[0] << std::endl;
    std::cout << bit(1, 0) << std::endl;
    test = test + 4;
    std::cout << test << std::endl;
    std::cout << sizeof(test) * 8 << std::endl;
    std::cout << test[0] << std::endl;
    return 0;
}