#include "../include/InsertionSort.h"

void InsertionSort::sort(Record* records, size_t count, int keyIndex) {
    for (size_t i = 1; i < count; ++i) {
        Record key = records[i];
        int j = i - 1;

        while (j >= 0 && records[j].values[keyIndex] > key.values[keyIndex]) {
            records[j + 1] = records[j];
            --j;
        }
        records[j + 1] = key;
    }
}
