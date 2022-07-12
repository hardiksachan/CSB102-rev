#include <stdio.h>

int partition(int arr[], int lo, int hi) {
    int pivotIdx = hi;
    int storeIdx = lo - 1;
    for (int i = lo; i < hi; i++) {
        if (arr[i] <= arr[pivotIdx]) {
            storeIdx++;

            int temp = arr[storeIdx];
            arr[storeIdx] = arr[i];
            arr[i] = temp;
        }
    }

    int temp = arr[storeIdx + 1];
    arr[storeIdx + 1] = arr[pivotIdx];
    arr[pivotIdx] = temp;

    return storeIdx + 1;
}

void sort(int arr[], int lo, int hi) {
    if (lo >= hi) {
        return;
    }

    int pivot = partition(arr, lo, hi);
    sort(arr, lo, pivot - 1);
    sort(arr, pivot + 1, hi);
}

int main() {
    int arr[] = {4, 2, 3, 1, 5};
    sort(arr, 0, 4);
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}