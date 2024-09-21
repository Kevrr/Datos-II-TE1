#include <iostream>
#include <string>
#include <string.h>
#include <unordered_map>
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
    sizes["SMALL"] = 128000000;
    sizes["MEDIUM"] = 256000000;
    sizes["LARGE"] = 512000000;
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

    std::string output = argv[4];
    output.append("output.bin");
    std::ofstream outFile(output, std::ios::binary);
    int n;
    for (long i = 0; i < sizes[argv[2]]; i++) {
        n = rand() % 100;
        outFile.write(reinterpret_cast<const char*>(&n), sizeof(int));
    }
    outFile.close();
    return 0;
}