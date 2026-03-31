#include <iostream>
#include "src.hpp"

int main() {
    // Test 1: Default constructor
    str s1;
    std::cout << "Empty string length: " << s1.len() << std::endl;

    // Test 2: Constructor from char
    str s2('A');
    std::cout << "Char 'A' length: " << s2.len() << " value: " << s2[0] << std::endl;

    // Test 3: Constructor from char*
    str s3("Hello");
    std::cout << "String 'Hello' length: " << s3.len() << " value: ";
    for (size_t i = 0; i < s3.len(); i++) {
        std::cout << s3[i];
    }
    std::cout << std::endl;

    // Test 4: Copy constructor
    str s4(s3);
    std::cout << "Copy of 'Hello' length: " << s4.len() << " value: ";
    for (size_t i = 0; i < s4.len(); i++) {
        std::cout << s4[i];
    }
    std::cout << std::endl;

    // Test 5: Assignment operator
    str s5;
    s5 = s3;
    std::cout << "Assigned 'Hello' length: " << s5.len() << " value: ";
    for (size_t i = 0; i < s5.len(); i++) {
        std::cout << s5[i];
    }
    std::cout << std::endl;

    // Test 6: slice
    str s6 = str("12345").slice(0, 2);
    std::cout << "Slice '12345'[0:2] length: " << s6.len() << " value: ";
    for (size_t i = 0; i < s6.len(); i++) {
        std::cout << s6[i];
    }
    std::cout << std::endl;

    // Test 7: join
    std::vector<str> vec;
    vec.push_back(str('1'));
    vec.push_back(str('2'));
    vec.push_back(str('3'));
    str s7 = str(", ").join(vec);
    std::cout << "Join ['1', '2', '3'] with ', ': length: " << s7.len() << " value: ";
    for (size_t i = 0; i < s7.len(); i++) {
        std::cout << s7[i];
    }
    std::cout << std::endl;

    return 0;
}
