#include "PagedArray.cpp"

/**
 * @brief function to sort an array by moving the elements 
 * in the left of a position to the right if they are greater 
 * than the element in that position
 * 
 * @param arr array to sort
 * @param n length of the array
 */
void insertionSort(PagedArray arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        // Move elements of array.get(0..i-1),
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}