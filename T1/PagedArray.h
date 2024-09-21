#include <string>
#include <fstream>

#ifndef PAGEDARRAY_H
#define PAGEDARRAY_H

class PagedArray {
    private:
        std::string file;
        int loaded[4];
        int indexes[4];
        int pagehits;
        int pagefaults;

    public:
        PagedArray(std::string inputfile);
        void firstload();
        int operator [](int index);
        const int& operator [](int index) const;
        bool pageHit(int index);
        int getPageHits();
        int getPageFaults();
        int swapPages(int index);
};

#endif