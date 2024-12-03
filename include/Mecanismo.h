#ifndef MECANISMO_H
#define MECANISMO_H

#include <string>

// Estrutura que representa um modelo com vários atributos
struct modelo {
    std::string nome;
    std::string id;
    std::string endereco;
    std::string conteudo;
};

// Classe responsável por gerenciar os dados
class GerenciadorDeDados {
public:
    GerenciadorDeDados();
    ~GerenciadorDeDados();

    // Carrega os dados do arquivo especificado
    bool carregarDadosDoArquivo(const std::string& nomeArquivo, modelo*& arrayModelos, size_t& tamanho, std::string& cabecalho, size_t& numAtributos);

    // Exibe os dados do array de modelos
    void exibirDados(const modelo* arrayModelos, size_t tamanho) const;

    // Libera a memória alocada para o array de modelos
    void liberarArrayModelo(modelo* arrayModelos) const;

    // Ordena e exibe os dados usando o algoritmo especificado
    void ordenarEExibir(const modelo* arrayModelosOriginal, size_t tamanho, int keyIndex, const std::string& algoritmo, const std::string& cabecalho, size_t numAtributos) const;
};

#endif // MECANISMO_H