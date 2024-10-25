#pragma once
#include "Rota.cpp"
#include <iostream>
using namespace std;

class Sensores : public Rota {
public:
    // Construtor
    Sensores(string nome) : Rota(nome) {}
    // Destrutor
    virtual ~Sensores() {}  // Torna a classe polimórfica
};