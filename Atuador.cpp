#pragma once
#include "Componente.cpp"
#include <iostream>
using namespace std;

class Atuador : public Componente {
    public:
        // Construtor
        Atuador(string nome) : Componente(nome) {}

        // Método para definir o valor (velocidade, brilho, configuração)
        bool setValor(int valor) {
            Componente::setValor(valor);
            return true;
        }
        // Destrutor
        virtual ~Atuador() {}  // Torna a classe polimórfica
};
