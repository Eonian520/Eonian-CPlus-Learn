// 计算二进制数的十进制值
// 使用元编程技术，在编译时计算二进制数的十进制值

#pragma once

// 基于递归模板的元编程实现
template<unsigned long N>
struct binary {
    static unsigned const value = binary<N / 10>::value * 2 + N % 10;
};

template <>
struct binary<0> {
    static unsigned const value = 0;
};

unsigned const one = binary<1>::value;
unsigned const three = binary<11>::value;
unsigned const five = binary<101>::value;
unsigned const seven = binary<111>::value;
unsigned const nine = binary<1001>::value;

// 基于运行时计算的实现
inline unsigned BinaryFunction(unsigned long n) {
    unsigned result = 0;
    for (unsigned bit = 0x1; n; n /= 10, bit <<= 1) {
        if (n % 10) {
            result += bit;
        }
    }
    return result;
}

// 基于递归函数的实现
inline unsigned BinaryRe(unsigned long n) {
    return n == 0 ? 0 : n % 10 + 2 * BinaryRe(n / 10);
}
