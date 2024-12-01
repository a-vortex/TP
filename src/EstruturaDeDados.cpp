#include "../include/EstruturaDeDados.h"
#include <fstream>
#include <sstream>
#include <iostream>

DataStructure::~DataStructure() {
    delete[] attributes; // Libera os atributos
    for (size_t i = 0; i < recordCount; ++i) {
        delete[] records[i].values; // Libera os valores de cada registro
    }
    delete[] records; // Libera o array de registros
}

bool DataStructure::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false; // Falha ao abrir o arquivo
    }

    // Ler o número de atributos
    file >> attributeCount;
    file.ignore(); // Ignorar o newline após o número
    attributes = new Attribute[attributeCount];

    // Ler os atributos
    for (size_t i = 0; i < attributeCount; ++i) {
        std::string line;
        std::getline(file, line);
        std::istringstream iss(line);

        std::string name, type;
        std::getline(iss, name, ',');
        std::getline(iss, type, ',');

        attributes[i] = {name, type};
    }

    // Ler o número de registros
    file >> recordCount;
    file.ignore(); // Ignorar o newline após o número
    records = new Record[recordCount];

    // Ler os registros
    for (size_t i = 0; i < recordCount; ++i) {
        std::string line;
        std::getline(file, line);
        std::istringstream iss(line);

        records[i].size = attributeCount;
        records[i].values = new std::string[attributeCount];

        for (size_t j = 0; j < attributeCount; ++j) {
            std::getline(iss, records[i].values[j], ',');
        }
    }

    file.close();
    return true;
}

void DataStructure::printData() const {
    // Imprimir atributos
    std::cout << attributeCount << "\n";
    for (size_t i = 0; i < attributeCount; ++i) {
        std::cout << attributes[i].name << "," << attributes[i].type << "\n";
    }

    // Imprimir registros
    std::cout << recordCount << "\n";
    for (size_t i = 0; i < recordCount; ++i) {
        for (size_t j = 0; j < records[i].size; ++j) {
            if (j > 0) std::cout << ",";
            std::cout << records[i].values[j];
        }
        std::cout << "\n";
    }
}

int DataStructure::getKeyIndex(const std::string& key) const {
    for (size_t i = 0; i < attributeCount; ++i) {
        if (attributes[i].name == key) {
            return static_cast<int>(i); // Retorna o índice da chave
        }
    }
    return -1; // Retorna -1 se a chave não for encontrada
}
