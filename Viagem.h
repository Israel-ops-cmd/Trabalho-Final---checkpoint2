#ifndef VIAGEM_H
#define VIAGEM_H

#include <string>    // Necessário para manipular strings.
#include <vector>    // Necessário para armazenar listas dinâmicas.
#include <map>       // Necessário para relacionar chaves e valores.
#include "Cidade.h"  // Inclui a definição da classe Cidade.
#include "Trajeto.h" // Inclui a definição da classe Trajeto.
#include "Transporte.h" // Inclui a definição da classe Transporte.

class Viagem {
public:
    // Vetor que armazena todas as cidades registradas.
    std::vector<Cidade> cidades;

    // Vetor que armazena os trajetos entre as cidades.
    std::vector<Trajeto> trajetos;

    // Vetor que armazena os transportes disponíveis para as viagens.
    std::vector<Transporte> transportes;

    // Mapa que relaciona o nome de cada cidade com o número de visitas realizadas.
    std::map<std::string, int> visitas;

    // Método para adicionar uma nova cidade ao sistema.
    void adicionarCidade(const std::string& nome);

    // Método para adicionar um trajeto entre duas cidades com um tempo associado.
    void adicionarTrajeto(const std::string& origem, const std::string& destino, int tempo);

    // Método para adicionar um transporte com nome, capacidade e cidade atual.
    void adicionarTransporte(const std::string& nome, int capacidade, const std::string& cidadeAtual);

    // Método para calcular o melhor caminho entre duas cidades usando o algoritmo de Dijkstra.
    std::vector<std::string> calcularMelhorRota(const std::string& cidadeOrigem, const std::string& cidadeDestino);

    // Método para relatar quantas vezes cada cidade foi visitada.
    void relatarCidadesMaisVisitadas();
};

#endif
