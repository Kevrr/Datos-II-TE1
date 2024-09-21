#include <iostream>
#include <chrono>
#include <cmath>
#include "bubbleSort.cpp"
#include "selectionSort.cpp"
#include "mergeSort.cpp"
#include "LinkedList.cpp"
#include "BST.cpp"

void DescendingIntArray(int arr[], int size) {
    int n = size;
    for (int i = 0; i < size; i++) {
        n -= i;
        arr[i] = n;
    }
}

int main() {;
    double BSbigO[10], SSbigO[10], MSbigO[10], LLbigO[10], BSTbigO[10];
    std::chrono::nanoseconds BStimes[10], SStimes[10], MStimes[10], LLtimes[10], BSTtimes[10];
    int arr[50];

    int num;
    for (int i = 0; i < 10; i++) {
        num = 5 + i * 5;
        BSbigO[i] = num * num;
        SSbigO[i] = num * num;
        MSbigO[i] = num * std::log2(num);
        LLbigO[i] = num;
        BSTbigO[i] = num;
    }

    for (int n = 5; n < 55; n += 5) {
        DescendingIntArray(arr, 50);
        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(arr, n);
        auto stop = std::chrono::high_resolution_clock::now();
        BStimes[n / 5 - 1] = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    }

    for (int n = 5; n < 55; n += 5) {
        DescendingIntArray(arr, 50);
        auto start = std::chrono::high_resolution_clock::now();
        selectionSort(arr, n);
        auto stop = std::chrono::high_resolution_clock::now();
        SStimes[n / 5 - 1] = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    }
    
    for (int n = 5; n < 55; n += 5) {
        DescendingIntArray(arr, 50);
        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(arr, 0, n);
        auto stop = std::chrono::high_resolution_clock::now();
        MStimes[n / 5 - 1] = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    }

}