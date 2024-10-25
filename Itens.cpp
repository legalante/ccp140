#pragma once
#include "Rota.cpp"
#include <iostream>
using namespace std;

class Itens : public Rota {
    public:
        // Construtor
        Itens(string nome) : Rota(nome) {}

        // Método para definir o valor (velocidade, brilho, configuração)
        bool setValor(int valor) {
            Rota::setValor(valor);
            return true;
        }
        // Destrutor
        virtual ~Itens() {}  // Torna a classe polimórfica
};