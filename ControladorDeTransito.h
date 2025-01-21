#ifndef CONTROLADORDETRANSITO_H
#define CONTROLADORDETRANSITO_H

#include "Viagem.h" // Inclui a definição da classe Viagem, que é usada para gerenciar cidades, transportes e trajetos no sistema.

// Classe ControladorDeTransito: Gerencia a interação do usuário com o sistema de transporte e viagem.
class ControladorDeTransito {
private:
    Viagem viagem; // Instância da classe Viagem, que contém a lógica para gerenciar as cidades, transportes, trajetos e passageiros.

public:
    // Função que inicia o processo de interação com o usuário, coleta dados e executa o fluxo de operação do sistema.
    void iniciar();
};

#endif
