#ifndef TRANSPORTE_H
#define TRANSPORTE_H

#include <string> // Inclui a biblioteca para manipulação de strings.
#include <vector> // Inclui a biblioteca para uso de vetores.

// Classe Transporte: Representa um meio de transporte no sistema.
class Transporte {
public:
    std::string nome; // Nome do transporte.
    int capacidade; // Capacidade máxima de passageiros.
    std::string cidadeAtual; // Nome da cidade onde o transporte está atualmente.
    std::vector<std::string> passageiros; // Lista de passageiros no transporte.

    // Construtor da classe Transporte.
    // Inicializa um transporte com o nome, capacidade e cidade atual fornecidos.
    Transporte(const std::string& nome, int capacidade, const std::string& cidadeAtual);

    // Registra a partida do transporte, alterando a cidade atual para "Em viagem".
    void registrarPartida();

    // Registra a chegada do transporte a uma cidade de destino.
    void registrarChegada(const std::string& cidadeDestino);

    // Adiciona um passageiro ao transporte, verificando se ainda há capacidade disponível.
    void adicionarPassageiro(const std::string& nomePassageiro);
};

#endif
