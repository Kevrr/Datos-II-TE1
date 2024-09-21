void merge (int arr[], int low, int mid, int high) {
    int l = mid - low + 1;
    int r = high - mid;
    int size = high / 2;

    int arrL[size], arrR[size];
    for (int i = 0; i < l; i++) {
        arrL[i] = arr[low + i];
    }
    for (int j = 0; j < r; j++) {
        arrR[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = low;
    while (i < l && j < r) {
        if (arrL[i] <= arrR[j]) {
            arr[k] = arrL[i];
            i++;
        }
        else {
            arr[k] = arrR[j];
            j++;
        }
        k++;
    }
    while (i < l) {
        arr[k] = arrL[i];
        i++;
        k++;
    }
    while (j < r) {
        arr[k] = arrR[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}