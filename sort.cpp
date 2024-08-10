#include <iostream>
#include <string>
#include <string.h>
#include <unordered_map>
#include <filesystem>
#include "PagedArray.cpp"
#include "quicksort.cpp"
#include "insertionsort.cpp"
#include "bubblesort.cpp"

int main(int argc, char** argv) {
    if (argc < 5) {
        std::cout << "arguments missing" << std::endl;
        return -1;
    } else if (argc > 5) {
        std::cout << "too many arguments" << std::endl;
        return -1;
    }

    if (strcmp(argv[1], "-input") != 0) {
        std::cout << argv[1] << ": command not found" << std::endl;
        return -1;
    }

    if (!std::filesystem::exists(argv[2])) {
        std::cout << argv[2] << std::endl;
        std::cout << "Path not found" << std::endl;
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

    if (strcmp(argv[5], "-alg") != 0) {
        std::cout << argv[3] << ": command not found" << std::endl;
        return -1;
    }

    std::unordered_map<std::string, int> sorters;
    sorters["QS"] = 1;
    sorters["IS"] = 2;
    sorters["BS"] = 5;
    if (sorters.find(argv[6]) == sorters.end()) {
        std::cout << argv[2] << " is not a valid size" << std::endl;
        return -1;
    }
    PagedArray* arr = new PagedArray(argv[2]);
    switch (sorters[argv[2]])
    {
    case 1:
        quickSort(arr, 0, 9);
        break;
    case 2:
        insertionSort(arr, 9);
        break;
    case 3:
        bubbleSort(arr, 9);
        break;
    default:
        break;
    }
    