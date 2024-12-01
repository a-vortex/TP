#include "../include/EstruturaDeDados.h"
#include "../include/QuickSort.h"
#include "../include/InsertionSort.h"
#include "../include/MergeSort.h"
#include <string>
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "nao tem argumento" << "\n";
        return 1;
    }

    DataStructure data;
    if (!data.loadFromFile(argv[1])) {
        std::cout << "nao ta abrindo" << "\n";
        return 1; 
    }
    
        std::cout << "o arquivo abriu em" << "\n";

    const std::string keys[] = {"name", "id", "address"};

    for (const std::string& key : keys) {
        QuickSort::sort(data.getRecords(), 0, data.getRecordCount() - 1, data.getKeyIndex(key));
        data.printData();

        InsertionSort::sort(data.getRecords(), data.getRecordCount(), data.getKeyIndex(key));
        data.printData();

        MergeSort::sort(data.getRecords(), 0, data.getRecordCount() - 1, data.getKeyIndex(key));
        data.printData();
    }

    return 0;
}
