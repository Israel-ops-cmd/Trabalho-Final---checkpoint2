#ifndef TRAJETO_H
#define TRAJETO_H

#include <string> // Inclui a biblioteca para manipulação de strings.

// Classe Trajeto: Representa um trajeto entre duas cidades no sistema.
class Trajeto {
public:
    std::string origem; // Nome da cidade de origem do trajeto.
    std::string destino; // Nome da cidade de destino do trajeto.
    int tempo; // Tempo necessário para completar o trajeto (em horas, por exemplo).

    // Construtor da classe Trajeto.
    // Inicializa um objeto Trajeto com os valores fornecidos para origem, destino e tempo.
    Trajeto(const std::string& origem, const std::string& destino, int tempo);
};

#endif
