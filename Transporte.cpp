#include "Transporte.h"
#include <iostream>

Transporte::Transporte(const std::string& nome, int capacidade, const std::string& cidadeAtual)
    : nome(nome), capacidade(capacidade), cidadeAtual(cidadeAtual) {}

void Transporte::registrarPartida() {
    cidadeAtual = "Em viagem";
}

void Transporte::registrarChegada(const std::string& cidadeDestino) {
    cidadeAtual = cidadeDestino;
}

void Transporte::adicionarPassageiro(const std::string& nomePassageiro) {
    if (passageiros.size() < capacidade) {
        passageiros.push_back(nomePassageiro);
    } else {
        std::cout << "Capacidade do transporte " << nome << " excedida." << std::endl;
    }
}
