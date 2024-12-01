#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "EstruturaDeDados.h"

class QuickSort {
public:
    static void sort(Record* records, int low, int high, int keyIndex);

private:
    static int partition(Record* records, int low, int high, int keyIndex);
};

#endif 
