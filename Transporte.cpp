#include "Transporte.h" // Inclui a definição da classe Transporte.
#include <iostream> // Inclui a biblioteca para operações de entrada e saída.

// Implementação do construtor da classe Transporte.
// Inicializa um objeto Transporte com os valores fornecidos para nome, capacidade e cidade atual.
Transporte::Transporte(const std::string& nome, int capacidade, const std::string& cidadeAtual)
    : nome(nome), capacidade(capacidade), cidadeAtual(cidadeAtual) {}

// Método que registra a partida do transporte, alterando a cidade atual para "Em viagem".
void Transporte::registrarPartida() {
    cidadeAtual = "Em viagem";
}

// Método que registra a chegada do transporte a uma cidade de destino, atualizando a cidade atual.
void Transporte::registrarChegada(const std::string& cidadeDestino) {
    cidadeAtual = cidadeDestino;
}

// Método que adiciona um passageiro ao transporte, caso haja capacidade disponível.
void Transporte::adicionarPassageiro(const std::string& nomePassageiro) {
    if (passageiros.size() < static_cast<size_t>(capacidade)) { // Verifica se há espaço disponível.
        passageiros.push_back(nomePassageiro); // Adiciona o passageiro à lista.
    } else {
        // Exibe uma mensagem indicando que a capacidade foi excedida.
        std::cout << "Capacidade do transporte " << nome << " excedida." << std::endl;
    }
}
