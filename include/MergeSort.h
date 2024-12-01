#ifndef MERGESORT_H
#define MERGESORT_H

#include "EstruturaDeDados.h"

class MergeSort {
public:
    static void sort(Record* records, int low, int high, int keyIndex);

private:
    static void merge(Record* records, int low, int mid, int high, int keyIndex);
};

#endif 
