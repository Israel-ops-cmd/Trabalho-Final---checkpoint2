#ifndef VIAGEM_H
#define VIAGEM_H

#include "Cidade.h"
#include "Trajeto.h"
#include "Transporte.h"
#include <vector>
#include <map>
#include <string>

class Viagem {
public:
    std::vector<Cidade> cidades;
    std::vector<Trajeto> trajetos;
    std::vector<Transporte> transportes;
    std::map<std::string, int> visitas;

    void adicionarCidade(const std::string& nome);
    void adicionarTrajeto(const std::string& origem, const std::string& destino, int tempo);
    void adicionarTransporte(const std::string& nome, int capacidade, const std::string& cidadeAtual);
    std::vector<std::string> calcularMelhorRota(const std::string& cidadeOrigem, const std::string& cidadeDestino);
    void relatarCidadesMaisVisitadas();
};

#endif // VIAGEM_H
