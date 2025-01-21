#include "Trajeto.h" // Inclui a definição da classe Trajeto.

// Implementação do construtor da classe Trajeto.
// Inicializa um objeto Trajeto com a cidade de origem, cidade de destino e o tempo de viagem fornecidos.
Trajeto::Trajeto(const std::string& origem, const std::string& destino, int tempo)
    : origem(origem), destino(destino), tempo(tempo) {}
