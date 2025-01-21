#ifndef CIDADE_H
#define CIDADE_H

#include <string>

// Classe que representa uma cidade no sistema.
class Cidade {
public:
    std::string nome; // Nome da cidade. Variável membro que armazena o nome da cidade.

    // Construtor que inicializa a cidade com o nome fornecido.
    // O nome é passado por referência constante para evitar cópias desnecessárias.
    Cidade(const std::string& nome);
};

#endif
