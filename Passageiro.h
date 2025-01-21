#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include <string> // Inclui a biblioteca de manipulação de strings.

// Classe Passageiro: Representa um passageiro no sistema.
class Passageiro {
public:
    std::string nome; // Nome do passageiro.

    // Construtor da classe Passageiro.
    // Inicializa um objeto Passageiro com o nome fornecido.
    Passageiro(const std::string& nome);
};

#endif
