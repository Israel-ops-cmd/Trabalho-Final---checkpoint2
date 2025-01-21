#ifndef TRANSPORTE_H
#define TRANSPORTE_H

#include <string>
#include <vector>

class Transporte {
public:
    std::string nome;
    int capacidade;
    std::string cidadeAtual;
    std::vector<std::string> passageiros;

    Transporte(const std::string& nome, int capacidade, const std::string& cidadeAtual);

    void registrarPartida();
    void registrarChegada(const std::string& cidadeDestino);
    void adicionarPassageiro(const std::string& nomePassageiro);
};

#endif // TRANSPORTE_H
