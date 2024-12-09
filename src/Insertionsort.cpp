#include "../include/Insertionsort.h"

modelo* InsertionSort::sort(const modelo* arrayModelos, size_t tamanho, int keyIndex) {
    modelo* sortedArray = new modelo[tamanho];
    std::copy(arrayModelos, arrayModelos + tamanho, sortedArray);

    for (size_t i = 1; i < tamanho; ++i) {
        modelo key = sortedArray[i];
        int j = i - 1;

        while (j >= 0 && getKey(sortedArray[j], keyIndex) > getKey(key, keyIndex)) {
            sortedArray[j + 1] = sortedArray[j];
            --j;
        }
        sortedArray[j + 1] = key;
    }

    return sortedArray;
}

std::string InsertionSort::getKey(const modelo& m, int keyIndex) {
    switch (keyIndex) {
        case 0: return m.nome;
        case 1: return m.id;
        case 2: return m.endereco;
        case 3: return m.conteudo;
        default: return m.nome;
    }
}