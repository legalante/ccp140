#pragma once
#include "Componente.cpp"
#include <iostream>
using namespace std;

class Sensor : public Componente {
public:
    // Construtor
    Sensor(string nome) : Componente(nome) {}
    // Destrutor
    virtual ~Sensor() {}  // Torna a classe polimórfica
};
