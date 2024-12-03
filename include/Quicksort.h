#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "Mecanismo.h"

class QuickSort
{
public:
    static modelo *sort(const modelo *arrayModelos, size_t tamanho, int keyIndex);

private:
    static void sortInternal(modelo *arrayModelos, int left, int right, int keyIndex);
    static int partition(modelo *arrayModelos, int left, int right, int keyIndex);
    static std::string getKey(const modelo &m, int keyIndex);
};

#endif // QUICK_SORT_H