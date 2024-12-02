#include <iostream>
#include <string>
#include "../include/Mecanismo.h"

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
    modelo* arrayModelos = nullptr;
    size_t tamanho = 0;

    if (!gerenciador.carregarDadosDoArquivo(nomeArquivo, arrayModelos, tamanho)) {
        return 1;
    }

    gerenciador.exibirDados(arrayModelos, tamanho);

    gerenciador.liberarArrayModelo(arrayModelos);

    return 0;
}