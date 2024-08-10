#include <bits/stdc++.h>
#include "PagedArray.cpp"
/**
 * @brief algorithm to sort an array by checking two elements
 * next to each other and swaping them if necesary, repeating 
 * until no more swaps are necesary
 * 
 * @param arr array to sort
 * @param n length of the array
 */
void bubbleSort(PagedArray arr, int n) {
    bool swapped;
    int temp;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}