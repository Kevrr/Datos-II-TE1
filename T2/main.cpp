#include <iostream>

int main() {
    int a = 5;
    int* ptr = &a;

    if (!ptr) {
        std::cout << "null";
    } else
        std::cout << "notnull";

}