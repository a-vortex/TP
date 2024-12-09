#include "../include/Mergesort.h"
#include <algorithm>

modelo* MergeSort::sort(const modelo* arrayModelos, size_t tamanho, int keyIndex) {
    modelo* sortedArray = new modelo[tamanho];
    std::copy(arrayModelos, arrayModelos + tamanho, sortedArray);
    sortInternal(sortedArray, 0, tamanho - 1, keyIndex);
    return sortedArray;
}

void MergeSort::sortInternal(modelo* arrayModelos, int left, int right, int keyIndex) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        sortInternal(arrayModelos, left, mid, keyIndex);
        sortInternal(arrayModelos, mid + 1, right, keyIndex);
        merge(arrayModelos, left, mid, right, keyIndex);
    }
}

void MergeSort::merge(modelo* arrayModelos, int left, int mid, int right, int keyIndex) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    modelo* L = new modelo[n1];
    modelo* R = new modelo[n2];

    for (int i = 0; i < n1; ++i) {
        L[i] = arrayModelos[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arrayModelos[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (getKey(L[i], keyIndex) <= getKey(R[j], keyIndex)) {
            arrayModelos[k] = L[i];
            ++i;
        } else {
            arrayModelos[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arrayModelos[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arrayModelos[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;
}

std::string MergeSort::getKey(const modelo& m, int keyIndex) {
    switch (keyIndex) {
        case 0: return m.nome;
        case 1: return m.id;
        case 2: return m.endereco;
        case 3: return m.conteudo;
        default: return m.nome;
    }
}