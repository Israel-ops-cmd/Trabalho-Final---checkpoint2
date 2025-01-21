#include "Viagem.h"
#include <iostream> // Inclui funções de entrada e saída padrão.
#include <limits>   // Fornece limites para tipos numéricos, como valores máximos.
#include <queue>    // Inclui a estrutura de fila de prioridade.
#include <algorithm> // Fornece funções como std::reverse.

void Viagem::adicionarCidade(const std::string& nome) {
    cidades.emplace_back(nome); // Adiciona uma nova cidade à lista de cidades.
    visitas[nome] = 0; // Inicializa o contador de visitas da cidade com zero.
}

void Viagem::adicionarTrajeto(const std::string& origem, const std::string& destino, int tempo) {
    trajetos.emplace_back(origem, destino, tempo); // Adiciona um trajeto entre duas cidades.
}

void Viagem::adicionarTransporte(const std::string& nome, int capacidade, const std::string& cidadeAtual) {
    transportes.emplace_back(nome, capacidade, cidadeAtual); // Adiciona um novo transporte com suas propriedades.
}

std::vector<std::string> Viagem::calcularMelhorRota(const std::string& cidadeOrigem, const std::string& cidadeDestino) {
    std::map<std::string, std::vector<std::pair<std::string, int>>> grafo;

    // Construção do grafo bidirecional com os trajetos.
    for (const auto& trajeto : trajetos) {
        grafo[trajeto.origem].emplace_back(trajeto.destino, trajeto.tempo);
        grafo[trajeto.destino].emplace_back(trajeto.origem, trajeto.tempo);
    }

    // Inicialização das estruturas para o algoritmo de Dijkstra.
    std::map<std::string, int> distancias; // Armazena as menores distâncias de cidadeOrigem.
    std::map<std::string, std::string> predecessores; // Armazena o caminho percorrido.
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<>> fila;

    // Configura todas as distâncias como infinitas inicialmente.
    for (const auto& cidade : cidades) {
        distancias[cidade.nome] = std::numeric_limits<int>::max();
    }

    distancias[cidadeOrigem] = 0; // Distância inicial é 0 para a cidade de origem.
    fila.push({0, cidadeOrigem}); // Adiciona a cidade de origem na fila.

    // Algoritmo de Dijkstra para encontrar o menor caminho.
    while (!fila.empty()) {
        auto top = fila.top(); // Obtem o elemento com a menor distância.
        fila.pop();

        int distAtual = top.first;
        std::string cidadeAtual = top.second;

        if (distAtual > distancias[cidadeAtual]) continue; // Ignora caminhos já processados.

        for (const auto& vizinho : grafo[cidadeAtual]) {
            const auto& cidadeVizinha = vizinho.first;
            const auto& peso = vizinho.second;
            // Relaxamento da aresta, se encontrada uma distância menor.
            if (distAtual + peso < distancias[cidadeVizinha]) {
                distancias[cidadeVizinha] = distAtual + peso;
                predecessores[cidadeVizinha] = cidadeAtual;
                fila.push({distAtual + peso, cidadeVizinha});
            }
        }
    }

    // Reconstrução do caminho mais curto a partir de predecessores.
    std::vector<std::string> caminho;
    for (std::string cidade = cidadeDestino; !cidade.empty(); cidade = predecessores[cidade]) {
        caminho.push_back(cidade);
    }

    std::reverse(caminho.begin(), caminho.end()); // Inverte o caminho para começar na origem.
    return caminho;
}

void Viagem::relatarCidadesMaisVisitadas() {
    // Relata quantas vezes cada cidade foi visitada.
    for (const auto& cidade : visitas) {
        std::cout << cidade.first << " foi visitada " << cidade.second << " vezes." << std::endl;
    }
}
