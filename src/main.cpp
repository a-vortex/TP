#include <iostream>
#include <string>
#include "../include/Mecanismo.h"
#include "../include/QuickSort.h"
#include "../include/MergeSort.h"
#include "../include/InsertionSort.h"

//==========Estruturas de Dados==========

// Trabalho Prático 1 - Data Entrega 09/12
// Aluno: Maria Clara Contarini Domingos
// Matrícula: 2023060596
// Email: mccontarinid@gmail.com

//========================================

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <arquivo.xcsv>" << std::endl;
        return 1;
    }

    std::string nomeArquivo = argv[1];

    GerenciadorDeDados gerenciador;
    modelo* arrayModelosOriginal = nullptr;
    size_t tamanho = 0;
    std::string cabecalho;
    size_t numAtributos = 0;

    // Carrega os dados do arquivo
    if (!gerenciador.carregarDadosDoArquivo(nomeArquivo, arrayModelosOriginal, tamanho, cabecalho, numAtributos)) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return 1;
    }

    // Ordenar e exibir usando diferentes algoritmos e chaves
    gerenciador.ordenarEExibir(arrayModelosOriginal, tamanho, 0, "QuickSort", cabecalho, numAtributos);
    gerenciador.ordenarEExibir(arrayModelosOriginal, tamanho, 1, "QuickSort", cabecalho, numAtributos);
    gerenciador.ordenarEExibir(arrayModelosOriginal, tamanho, 2, "QuickSort", cabecalho, numAtributos);

    gerenciador.ordenarEExibir(arrayModelosOriginal, tamanho, 0, "MergeSort", cabecalho, numAtributos);
    gerenciador.ordenarEExibir(arrayModelosOriginal, tamanho, 1, "MergeSort", cabecalho, numAtributos);
    gerenciador.ordenarEExibir(arrayModelosOriginal, tamanho, 2, "MergeSort", cabecalho, numAtributos);

    gerenciador.ordenarEExibir(arrayModelosOriginal, tamanho, 0, "InsertionSort", cabecalho, numAtributos);
    gerenciador.ordenarEExibir(arrayModelosOriginal, tamanho, 1, "InsertionSort", cabecalho, numAtributos);
    gerenciador.ordenarEExibir(arrayModelosOriginal, tamanho, 2, "InsertionSort", cabecalho, numAtributos);

    // Libera a memória do array original
    gerenciador.liberarArrayModelo(arrayModelosOriginal);

    return 0;
}