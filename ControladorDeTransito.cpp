#include "ControladorDeTransito.h"
#include <iostream>

// Função responsável por iniciar a interação com o usuário e gerenciar a entrada de dados para o sistema.
void ControladorDeTransito::iniciar() {
    setlocale(LC_ALL, "portuguese"); // Configura o local para português, já que a configuração do meu vscode considera pontuações e acentuações como caracteres aleatórios
    
    int numCidades;
    std::cout << "Quantas cidades você quer adicionar? ";
    std::cin >> numCidades; // Solicita ao usuário o número de cidades que ele deseja adicionar.
    std::cin.ignore(); // Ignora o caractere de nova linha após a entrada do número.

    // Loop para adicionar as cidades
    for (int i = 0; i < numCidades; ++i) {
        std::string nomeCidade;
        std::cout << "Digite o nome da cidade " << i + 1 << ": ";
        std::getline(std::cin, nomeCidade); // Lê o nome da cidade.
        viagem.adicionarCidade(nomeCidade); // Adiciona a cidade ao sistema.
    }

    int numTransportes;
    std::cout << "Quantos transportes você quer adicionar? ";
    std::cin >> numTransportes; // Solicita o número de transportes a serem adicionados.
    std::cin.ignore();

    // Loop para adicionar os transportes
    for (int i = 0; i < numTransportes; ++i) {
        std::string nomeTransporte, cidadeAtual;
        int capacidade;
        std::cout << "Digite o nome do transporte " << i + 1 << ": ";
        std::getline(std::cin, nomeTransporte); // Lê o nome do transporte.
        std::cout << "Digite a capacidade do transporte " << i + 1 << ": ";
        std::cin >> capacidade; // Lê a capacidade do transporte.
        std::cin.ignore();
        std::cout << "Digite a cidade atual do transporte " << i + 1 << ": ";
        std::getline(std::cin, cidadeAtual); // Lê a cidade onde o transporte se encontra.
        viagem.adicionarTransporte(nomeTransporte, capacidade, cidadeAtual); // Adiciona o transporte ao sistema.
    }

    // Loop para adicionar passageiros aos transportes
    for (auto& transporte : viagem.transportes) {
        std::string nomePassageiro;
        int numPassageiros;
        std::cout << "Quantos passageiros deseja adicionar ao transporte " << transporte.nome << "? ";
        std::cin >> numPassageiros; // Solicita o número de passageiros para o transporte.
        std::cin.ignore();
        for (int i = 0; i < numPassageiros; ++i) {
            std::cout << "Digite o nome do passageiro: ";
            std::getline(std::cin, nomePassageiro); // Lê o nome do passageiro.
            transporte.adicionarPassageiro(nomePassageiro); // Adiciona o passageiro ao transporte.
        }
    }

    // Adicionar trajetos entre as cidades
    int numTrajetos;
    std::cout << "Quantos trajetos você quer adicionar? ";
    std::cin >> numTrajetos; // Solicita o número de trajetos a serem adicionados.
    std::cin.ignore();

    for (int i = 0; i < numTrajetos; ++i) {
        std::string origem, destino;
        int tempo;
        std::cout << "Digite a cidade de origem do trajeto " << i + 1 << ": ";
        std::getline(std::cin, origem); // Lê a cidade de origem do trajeto.
        std::cout << "Digite a cidade de destino do trajeto " << i + 1 << ": ";
        std::getline(std::cin, destino); // Lê a cidade de destino do trajeto.
        std::cout << "Digite o tempo de viagem (em horas): ";
        std::cin >> tempo; // Lê o tempo de viagem.
        std::cin.ignore();
        viagem.adicionarTrajeto(origem, destino, tempo); // Adiciona o trajeto ao sistema.
    }

    // Calcular a melhor rota entre duas cidades
    std::string origem, destino, nomeTransporte;
    std::cout << "Digite a cidade de origem: ";
    std::getline(std::cin, origem); // Lê a cidade de origem.
    std::cout << "Digite a cidade de destino: ";
    std::getline(std::cin, destino); // Lê a cidade de destino.
    std::cout << "Digite o nome do transporte: ";
    std::getline(std::cin, nomeTransporte); // Lê o nome do transporte.

    // Calcula a melhor rota entre origem e destino.
    auto rota = viagem.calcularMelhorRota(origem, destino);

    // Exibe a rota, caso tenha sido encontrada
    if (!rota.empty()) {
        std::cout << "Rota calculada:\n";
        for (size_t i = 0; i < rota.size() - 1; ++i) {
            std::cout << "Partindo de " << rota[i] << " para " << rota[i + 1] << ".\n";
            viagem.visitas[rota[i]]++; // Registra a visita à cidade.
            // Registra a chegada do transporte e dos passageiros
            for (auto& transporte : viagem.transportes) {
                if (transporte.nome == nomeTransporte) {
                    transporte.registrarChegada(rota[i + 1]); // Registra a chegada do transporte.
                    for (const auto& passageiro : transporte.passageiros) {
                        std::cout << "Passageiro " << passageiro << " está em " << rota[i + 1] << ".\n";
                    }
                    break;
                }
            }
        }
        viagem.visitas[rota.back()]++; // Registra a visita à última cidade da rota.
        std::cout << "Viagem concluída!\n";
    } else {
        std::cout << "Não foi possível encontrar uma rota entre as cidades.\n";
    }

    // Relatar as cidades mais visitadas
    std::cout << "Cidades mais visitadas:\n";
    viagem.relatarCidadesMaisVisitadas(); // Exibe as cidades mais visitadas com base nas visitas registradas.
}
