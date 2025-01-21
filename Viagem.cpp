#include "Viagem.h"
#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>

void Viagem::adicionarCidade(const std::string& nome) {
    cidades.emplace_back(nome);
    visitas[nome] = 0;
}

void Viagem::adicionarTrajeto(const std::string& origem, const std::string& destino, int tempo) {
    trajetos.emplace_back(origem, destino, tempo);
}

void Viagem::adicionarTransporte(const std::string& nome, int capacidade, const std::string& cidadeAtual) {
    transportes.emplace_back(nome, capacidade, cidadeAtual);
}

std::vector<std::string> Viagem::calcularMelhorRota(const std::string& cidadeOrigem, const std::string& cidadeDestino) {
    std::map<std::string, std::vector<std::pair<std::string, int>>> grafo;

    for (const auto& trajeto : trajetos) {
        grafo[trajeto.origem].emplace_back(trajeto.destino, trajeto.tempo);
        grafo[trajeto.destino].emplace_back(trajeto.origem, trajeto.tempo);  // Caso seja bidirecional
    }

    std::map<std::string, int> distancias;
    std::map<std::string, std::string> antecessores;

    for (const auto& cidade : cidades) {
        distancias[cidade.nome] = std::numeric_limits<int>::max();
    }

    distancias[cidadeOrigem] = 0;
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<std::pair<int, std::string>>> filaPrioridade;

    filaPrioridade.emplace(0, cidadeOrigem);

    while (!filaPrioridade.empty()) {
        std::pair<int, std::string> elementoAtual = filaPrioridade.top();
        filaPrioridade.pop();

        int distanciaAtual = elementoAtual.first;
        std::string cidadeAtual = elementoAtual.second;

        if (distanciaAtual > distancias[cidadeAtual]) {
            continue;
        }

        for (const std::pair<std::string, int>& vizinho : grafo[cidadeAtual]) {
            std::string nomeVizinho = vizinho.first;
            int peso = vizinho.second;
            int novaDistancia = distancias[cidadeAtual] + peso;

            if (novaDistancia < distancias[nomeVizinho]) {
                distancias[nomeVizinho] = novaDistancia;
                antecessores[nomeVizinho] = cidadeAtual;
                filaPrioridade.emplace(novaDistancia, nomeVizinho);
            }
        }
    }

    if (distancias[cidadeDestino] == std::numeric_limits<int>::max()) {
        std::cout << "Não há rota possível entre " << cidadeOrigem << " e " << cidadeDestino << "." << std::endl;
        return {};
    }

    std::vector<std::string> caminho;
    for (std::string cidade = cidadeDestino; !cidade.empty(); cidade = antecessores[cidade]) {
        caminho.push_back(cidade);
        if (cidade == cidadeOrigem) break;
    }

    std::reverse(caminho.begin(), caminho.end());
    return caminho;
}

void Viagem::relatarCidadesMaisVisitadas() {
    for (const auto& cidade : visitas) {
        std::cout << cidade.first << " foi visitada " << cidade.second << " vezes." << std::endl;
    }
}
