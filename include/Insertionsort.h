#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "Mecanismo.h"

class InsertionSort
{
public:
    static modelo *sort(const modelo *arrayModelos, size_t tamanho, int keyIndex);

private:
    static std::string getKey(const modelo &m, int keyIndex);
};

#endif // INSERTION_SORT_H