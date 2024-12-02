#include "Mecanismo.h"
#include <iostream>
#include <fstream>
#include <sstream>

GerenciadorDeDados::GerenciadorDeDados() {}

GerenciadorDeDados::~GerenciadorDeDados() {}

bool GerenciadorDeDados::carregarDadosDoArquivo(const std::string& nomeArquivo, modelo*& arrayModelos, size_t& tamanho) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo.\n";
        return false;
    }

    std::string linha;
    
    std::getline(arquivo, linha);
    size_t numAtributos = std::stoi(linha);

    for (size_t i = 0; i < numAtributos; ++i) {
        std::getline(arquivo, linha);
    }

    std::getline(arquivo, linha);
    tamanho = std::stoi(linha);

    arrayModelos = new modelo[tamanho];

    size_t indice = 0;
    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);
        std::string nome, id, endereco, conteudo;

        std::getline(iss, nome, ',');
        std::getline(iss, id, ',');
        std::getline(iss, endereco, ',');
        std::getline(iss, conteudo, ',');

        arrayModelos[indice].nome = nome;
        arrayModelos[indice].id = id;
        arrayModelos[indice].endereco = endereco;
        arrayModelos[indice].conteudo = conteudo;

        ++indice;
    }

    arquivo.close();
    return true;
}

void GerenciadorDeDados::exibirDados(modelo* arrayModelos, size_t tamanho) const {
    for (size_t i = 0; i < tamanho; ++i) {
        std::cout << arrayModelos[i].nome << ","
                  << arrayModelos[i].id << ","
                  << arrayModelos[i].endereco << ","
                  << arrayModelos[i].conteudo << "\n";
    }
}

void GerenciadorDeDados::liberarArrayModelo(modelo* arrayModelos) {
    delete[] arrayModelos;
}