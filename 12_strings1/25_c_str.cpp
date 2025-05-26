#include <iostream>
#include <string>

int main() {
    std::string str = "hello";
    const char* cstr = str.c_str();

    std::cout << "Original string: " << str << std::endl;
    std::cout << "C-style string: " << cstr << std::endl;

    return 0;
}

// print to dono hello hi karenge..
