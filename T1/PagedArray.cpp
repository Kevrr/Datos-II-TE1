#include "PagedArray.h"

PagedArray::PagedArray(std::string inputfile) {
    std::ifstream inFile(inputfile, std::ios::binary);
    this -> file = "temp.bin";
    std::ofstream outFile(this -> file, std::ios::binary);
    std::copy(std::istreambuf_iterator<char>(inFile), 
            std::istreambuf_iterator<char>(),
            std::ostreambuf_iterator<char>(outFile));
    inFile.close();
    outFile.close();
    this -> pagehits = 0;
    this -> pagefaults = 0;
    this -> firstload();
}

void PagedArray::firstload() {
    std::ifstream inFile(this -> file, std::ios::binary);
    uint32_t load;
    for (int i = 0; i < 4; i++) {
        inFile.read((char*)&load, sizeof(load));
        this -> loaded[i] = load;
        this -> indexes[i] = i;
    }
}

int PagedArray::operator[](int index) {
    if (this -> pageHit(index)) {
        return this -> loaded[index];
    } else return this -> swapPages(index);
}

const int& PagedArray::operator [](int index) const {
    return this -> operator[](index);
}

bool PagedArray::pageHit(int index) {
    for (int i = 0; i < 4; i++) {
        if (this -> indexes[i] == index) {
            this -> pagehits += 1;
            return true;
        }
    }
    this -> pagefaults += 1;
    return false;
}



int PagedArray::getPageHits() {
    return this -> pagehits;
}

int PagedArray::getPageFaults() {
    return this -> pagefaults;
}

int PagedArray::swapPages(int index) {
    int discard = (rand() % 4) + 1;
    std::ofstream outFile(this -> file, std::ios::binary);
    outFile.seekp(this -> indexes[discard] * 4);
    outFile.write(reinterpret_cast<const char*>(&this -> loaded[discard]), sizeof(int));
    outFile.close();

    std::ifstream inFile(this -> file, std::ios::in | std::ios::binary);
    inFile.seekg(index * 4);
    uint32_t load;
    inFile.read((char*)&load, sizeof(load));
    inFile.close();

    this -> loaded[discard] = load;
    this -> indexes[discard] = index;
    return discard;
}