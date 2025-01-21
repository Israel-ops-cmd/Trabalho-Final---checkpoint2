#include "Cidade.h"

// Implementação do construtor da classe Cidade.
// Este construtor inicializa o atributo "nome" da classe Cidade com o valor recebido como parâmetro.
// A inicialização é feita utilizando a lista de inicialização de membros (member initializer list), que é uma maneira eficiente de inicializar atributos.
Cidade::Cidade(const std::string& nome) : nome(nome) {}
