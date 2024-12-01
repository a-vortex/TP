#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <string>

struct Attribute {
    std::string name;
    std::string type; // Tipo do atributo (sempre "s" para string)
};

struct Record {
    std::string* values; // Array dinâmico de valores
    size_t size;         // Número de valores no registro

    Record() : values(nullptr), size(0) {}
    ~Record() { delete[] values; }
};

class DataStructure {
private:
    Attribute* attributes; // Array dinâmico de atributos
    size_t attributeCount; // Número de atributos

    Record* records;       // Array dinâmico de registros
    size_t recordCount;    // Número de registros

public:
    DataStructure() : attributes(nullptr), attributeCount(0), records(nullptr), recordCount(0) {}
    ~DataStructure();

    bool loadFromFile(const std::string& filename); // Carrega os dados do arquivo
    void printData() const; // Imprime os dados no formato correto
    int getKeyIndex(const std::string& key) const; // Obtém o índice de uma chave

    // Métodos de acesso
    size_t getAttributeCount() const { return attributeCount; }
    size_t getRecordCount() const { return recordCount; }
    Record* getRecords() const { return records; }
};

#endif // DATA_STRUCTURE_H
