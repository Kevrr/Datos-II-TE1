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

void add10(LinkedList* list, int size) {
    for (int i = 1; i < 11; i++) {
        list -> insertAtEnd(i + size);
    }
}

void insert9(BST* tree, int size) {
    for (int i = 1; i < 10; i++) {
        tree -> insert(i + size);
    }
}

int main() {;
    double BSbigO[5], SSbigO[5], MSbigO[5], LLbigO[5], BSTbigO[5];
    std::chrono::nanoseconds BStimes[5], SStimes[5], MStimes[5], LLtimes[5], BSTtimes[5];
    int arr[50];

    int num;
    for (int i = 0; i < 5; i++) {
        num = 10 + i * 10;
        BSbigO[i] = num * num;
        SSbigO[i] = num * num;
        MSbigO[i] = num * std::log2(num);
        LLbigO[i] = num;
        BSTbigO[i] = num;
    }

    std::cout << "Tiempos teoricos (Big O)" << std::endl;
    std::cout << "N  | " << "    10    |"  << "     20    |" "     30    |";
    std::cout << "     40    |" << "     50" << std::endl;
    std::cout << "BS |    " << BSbigO[0] << "    |    " << BSbigO[1] << "    |    " << BSbigO[2] << "    |    " << BSbigO[3] << "   |   " << BSbigO[4] << std::endl;
    std::cout << "SS |    " << SSbigO[0] << "    |    " << SSbigO[1] << "    |    " << SSbigO[2] << "    |    " << SSbigO[3] << "   |   " << SSbigO[4] << std::endl;
    std::cout << "MS |  " << MSbigO[0] << "  |  " << MSbigO[1] << "  |  " << MSbigO[2] << "  |  " << MSbigO[3] << "  |  " << MSbigO[4] << std::endl;
    std::cout << "LL |     " << LLbigO[0] << "    |     " << LLbigO[1] << "    |     " << LLbigO[2] << "    |     " << LLbigO[3] << "    |     " << LLbigO[4] << std::endl;
    std::cout << "BST|     " << BSTbigO[0] << "    |     " << BSTbigO[1] << "    |     " << BSTbigO[2] << "    |     " << BSTbigO[3] << "    |     " << BSTbigO[4] << std::endl;
    std::cout << std::endl;
    
    for (int n = 10; n < 60; n += 10) {
        DescendingIntArray(arr, 50);
        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(arr, n);
        auto stop = std::chrono::high_resolution_clock::now();
        BStimes[n / 10 - 1] = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    }

    for (int n = 10; n < 60; n += 10) {
        DescendingIntArray(arr, 50);
        auto start = std::chrono::high_resolution_clock::now();
        selectionSort(arr, n);
        auto stop = std::chrono::high_resolution_clock::now();
        SStimes[n / 10 - 1] = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    }
    
    for (int n = 10; n < 60; n += 10) {
        DescendingIntArray(arr, 50);
        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(arr, 0, n);
        auto stop = std::chrono::high_resolution_clock::now();
        MStimes[n / 10 - 1] = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    }

    LinkedList* list = new LinkedList();
    add10(list, 0);
    for (int n = 10; n < 60; n += 10) {
        auto start = std::chrono::high_resolution_clock::now();
        list -> find(n);
        auto stop = std::chrono::high_resolution_clock::now();
        LLtimes[n / 10 - 1] = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        add10(list, n);
    }

    BST* tree = new BST();
    insert9(tree, 0);
    tree -> insert(10);
    for (int n = 10; n < 60; n += 10) {
        auto start = std::chrono::high_resolution_clock::now();
        tree -> insert(n + 1);
        auto stop = std::chrono::high_resolution_clock::now();
        LLtimes[n / 10 - 1] = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        insert9(tree, n + 1);
    }

    std::cout << "Tiempos empiricos (ns)" << std::endl;
    std::cout << "N  | " << "    10    |"  << "     20    |" "     30    |";
    std::cout << "     40    |" << "     50" << std::endl;
    std::cout << "BS |   " << BStimes[0].count() << "    |   " << BStimes[1].count() << "    |   " << BStimes[2].count() << "    |    " << BStimes[3].count() << "   |   " << BStimes[4].count() << std::endl;
    std::cout << "SS |   " << SStimes[0].count() << "    |   " << SStimes[1].count() << "    |   " << SStimes[2].count() << "    |    " << SStimes[3].count() << "   |   " << SStimes[4].count() << std::endl;
    std::cout << "MS |   " << MStimes[0].count() << "    |   " << MStimes[1].count() << "    |   " << MStimes[2].count() << "    |    " << MStimes[3].count() << "   |   " << MStimes[4].count() << std::endl;
    std::cout << "LL |   " << LLtimes[0].count() << "    |   " << LLtimes[1].count() << "    |   " << LLtimes[2].count() << "    |    " << LLtimes[3].count() << "   |  " << LLtimes[4].count() << std::endl;
    std::cout << "BST|   " << BSTtimes[0].count() << "    |   " << BSTtimes[1].count() << "    |   " << BSTtimes[2].count() << "    |   " << BSTtimes[3].count() << "    |   " << BSTtimes[4].count() << std::endl;

}