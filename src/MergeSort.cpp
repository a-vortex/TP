#include "../include/MergeSort.h"

void MergeSort::sort(Record* records, int low, int high, int keyIndex) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        sort(records, low, mid, keyIndex);
        sort(records, mid + 1, high, keyIndex);
        merge(records, low, mid, high, keyIndex);
    }
}

void MergeSort::merge(Record* records, int low, int mid, int high, int keyIndex) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    Record* left = new Record[n1];
    Record* right = new Record[n2];

    for (int i = 0; i < n1; ++i) left[i] = records[low + i];
    for (int j = 0; j < n2; ++j) right[j] = records[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i].values[keyIndex] <= right[j].values[keyIndex]) {
            records[k++] = left[i++];
        } else {
            records[k++] = right[j++];
        }
    }

    while (i < n1) records[k++] = left[i++];
    while (j < n2) records[k++] = right[j++];

    delete[] left;
    delete[] right;
}
