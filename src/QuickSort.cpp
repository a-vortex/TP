#include "../include/QuickSort.h"
#include <string>
#include <utility>

void QuickSort::sort(Record* records, int low, int high, int keyIndex) {
    if (low < high) {
        int pivotIndex = partition(records, low, high, keyIndex);

        sort(records, low, pivotIndex - 1, keyIndex);
        sort(records, pivotIndex + 1, high, keyIndex);
    }
}

int QuickSort::partition(Record* records, int low, int high, int keyIndex) {
    std::string pivot = records[high].values[keyIndex];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (records[j].values[keyIndex] <= pivot) {
            ++i;
            std::swap(records[i], records[j]);
        }
    }

    std::swap(records[i + 1], records[high]);
    return i + 1;
}
