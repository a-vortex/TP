#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "Mecanismo.h"

class InsertionSort
{
public:
    static modelo *sort(const modelo *arrayModelos, size_t tamanho, int keyIndex);

private:
    static std::string getKey(const modelo &m, int keyIndex);
};

#endif // INSERTIONSORT_H