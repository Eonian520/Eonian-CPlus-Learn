#include <iostream>

int main() {
    std::cout << binary<5>::value << std::endl; // Output: 101
    std::cout << binary<10>::value << std::endl; // Output: 1010
    std::cout << binary<15>::value << std::endl; // Output: 1111
    return 0;
}