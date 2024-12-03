#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "Mecanismo.h"

class MergeSort
{
public:
    static modelo *sort(const modelo *arrayModelos, size_t tamanho, int keyIndex);

private:
    static void sortInternal(modelo *arrayModelos, int left, int right, int keyIndex);
    static void merge(modelo *arrayModelos, int left, int mid, int right, int keyIndex);
    static std::string getKey(const modelo &m, int keyIndex);
};

#endif // MERGE_SORT_H