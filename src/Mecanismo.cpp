#include "../include/Mecanismo.h"
#include "../include/Quicksort.h"
#include "../include/Mergesort.h"
#include "../include/Insertionsort.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

GerenciadorDeDados::GerenciadorDeDados() {}

GerenciadorDeDados::~GerenciadorDeDados() {}

// Carrega os dados do arquivo especificado
bool GerenciadorDeDados::carregarDadosDoArquivo(const std::string& nomeArquivo, modelo*& arrayModelos, size_t& tamanho, std::string& cabecalho, size_t& numAtributos) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return false;
    }

    std::string linha;
    // Ler o número de atributos
    std::getline(arquivo, linha);
    numAtributos = std::stoi(linha);

    // Ler as linhas dos atributos e formar o cabeçalho
    for (size_t i = 0; i < numAtributos; ++i) {
        std::getline(arquivo, linha);
        cabecalho += linha + "\n";
    }

    // Ler o número de registros
    std::getline(arquivo, linha);
    tamanho = std::stoi(linha);

    // Criar o array de modelos
    arrayModelos = new modelo[tamanho];

    // Ler os dados do arquivo e preencher o array de modelos
    size_t indice = 0;
    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);
        std::getline(iss, arrayModelos[indice].nome, ',');
        std::getline(iss, arrayModelos[indice].id, ',');
        std::getline(iss, arrayModelos[indice].endereco, ',');
        std::getline(iss, arrayModelos[indice].conteudo, ',');
        ++indice;
    }

    arquivo.close();
    return true;
}

// Exibe os dados do array de modelos
void GerenciadorDeDados::exibirDados(const modelo* arrayModelos, size_t tamanho) const {
    for (size_t i = 0; i < tamanho; ++i) {
        std::cout << arrayModelos[i].nome << ","
                  << arrayModelos[i].id << ","
                  << arrayModelos[i].endereco << ","
                  << arrayModelos[i].conteudo << "\n";
    }
}

// Libera a memória alocada para o array de modelos
void GerenciadorDeDados::liberarArrayModelo(modelo* arrayModelos) const {
    delete[] arrayModelos;
}

// Ordena e exibe os dados usando o algoritmo especificado
void GerenciadorDeDados::ordenarEExibir(const modelo* arrayModelosOriginal, size_t tamanho, int keyIndex, const std::string& algoritmo, const std::string& cabecalho, size_t numAtributos) const {
    modelo* arrayModelosOrdenado = nullptr;

    // Medir o tempo de execução do algoritmo de ordenação
    auto start = std::chrono::high_resolution_clock::now();

    // Seleciona o algoritmo de ordenação
    if (algoritmo == "QuickSort") {
        arrayModelosOrdenado = QuickSort::sort(arrayModelosOriginal, tamanho, keyIndex);
    } else if (algoritmo == "MergeSort") {
        arrayModelosOrdenado = MergeSort::sort(arrayModelosOriginal, tamanho, keyIndex);
    } else if (algoritmo == "InsertionSort") {
        arrayModelosOrdenado = InsertionSort::sort(arrayModelosOriginal, tamanho, keyIndex);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    // Imprime o cabeçalho e os dados ordenados
    std::cout << numAtributos << "\n" << cabecalho << tamanho << "\n";
    exibirDados(arrayModelosOrdenado, tamanho);

    // // Imprime o tempo de execução
    // std::cout << "Tempo de execução (" << algoritmo << "): " << duration.count() << " segundos\n";

    liberarArrayModelo(arrayModelosOrdenado);
}