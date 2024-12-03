#include "QuickSort.h"
#include <algorithm>

modelo *QuickSort::sort(const modelo *arrayModelos, size_t tamanho, int keyIndex)
{
    modelo *sortedArray = new modelo[tamanho];
    std::copy(arrayModelos, arrayModelos + tamanho, sortedArray);
    sortInternal(sortedArray, 0, tamanho - 1, keyIndex);
    return sortedArray;
}

void QuickSort::sortInternal(modelo *arrayModelos, int left, int right, int keyIndex)
{
    if (left < right)
    {
        int pivotIndex = partition(arrayModelos, left, right, keyIndex);
        sortInternal(arrayModelos, left, pivotIndex - 1, keyIndex);
        sortInternal(arrayModelos, pivotIndex + 1, right, keyIndex);
    }
}

int QuickSort::partition(modelo *arrayModelos, int left, int right, int keyIndex)
{
    std::string pivot = getKey(arrayModelos[right], keyIndex);
    int i = left - 1;
    for (int j = left; j < right; ++j)
    {
        if (getKey(arrayModelos[j], keyIndex) <= pivot)
        {
            ++i;
            std::swap(arrayModelos[i], arrayModelos[j]);
        }
    }
    std::swap(arrayModelos[i + 1], arrayModelos[right]);
    return i + 1;
}

std::string QuickSort::getKey(const modelo &m, int keyIndex)
{
    switch (keyIndex)
    {
    case 0:
        return m.nome;
    case 1:
        return m.id;
    case 2:
        return m.endereco;
    default:
        return m.nome;
    }
}