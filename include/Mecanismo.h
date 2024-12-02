#ifndef MECANISMO_H
#define MECANISMO_H

#include <string>

struct modelo {
    std::string nome;
    std::string id;
    std::string endereco;
    std::string conteudo;
};

class GerenciadorDeDados {
public:
    GerenciadorDeDados();
    ~GerenciadorDeDados();

    bool carregarDadosDoArquivo(const std::string& nomeArquivo, modelo*& arrayModelos, size_t& tamanho);
    void exibirDados(modelo* arrayModelos, size_t tamanho) const;
    void liberarArrayModelo(modelo* arrayModelos);
};

#endif // MECANISMO_H