#ifndef TRAJETO_H
#define TRAJETO_H

#include <string>

class Trajeto {
public:
    std::string origem;
    std::string destino;
    int tempo;

    Trajeto(const std::string& origem, const std::string& destino, int tempo);
};

#endif // TRAJETO_H
