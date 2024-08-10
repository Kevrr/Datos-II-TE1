#include <iostream>
#include <string>
#include <string.h>
#include <unordered_map>
#include <vector>
#include <filesystem>
#include <fstream>

int main(int argc, char** argv) {
    if (argc < 5) {
        std::cout << "arguments missing" << std::endl;
        return -1;
    } else if (argc > 5) {
        std::cout << "too many arguments" << std::endl;
        return -1;
    }

    if (strcmp(argv[1], "-size") != 0) {
        std::cout << argv[1] << ": command not found" << std::endl;
        return -1;
    }

    std::unordered_map<std::string, long> sizes;
    sizes["test"] = 10;
    sizes["SMALL"] = 12800000000;
    sizes["MEDIUM"] = 25600000000;
    sizes["LARGE"] = 51200000000;
    if (sizes.find(argv[2]) == sizes.end()) {
        std::cout << argv[2] << " is not a valid size" << std::endl;
        return -1;
    }

    if (strcmp(argv[3], "-output") != 0) {
        std::cout << argv[3] << ": command not found" << std::endl;
        return -1;
    }

    if (!std::filesystem::exists(argv[4])) {
        std::cout << argv[4] << std::endl;
        std::cout << "Path not found" << std::endl;
        return -1;
    }

    std::ofstream outFile("output.bin", std::ios::binary);
    int n;
    for (long i = 0; i < sizes[argv[2]]; i++) {
        n = rand() % 100;
        std::cout << n << std::endl;
        outFile.write(reinterpret_cast<const char*>(&n), sizeof(int));
    }
    outFile.close();
    return 0;
}