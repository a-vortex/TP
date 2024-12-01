#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "EstruturaDeDados.h"

class InsertionSort {
public:
    static void sort(Record* records, size_t count, int keyIndex);
};

#endif
