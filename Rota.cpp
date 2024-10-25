#pragma once
#include <iostream>
using namespace std;

class Rota {
    private:
        bool acionado;       // Define se o componente está acionado
        int valor;         // Valor atual do componente (pode ser leitura de um sensor ou estado de um atuador)
        string nome;       // Nome do componente para identificação

    public:
        // Construtor para inicializar o componente
        Rota(string nome) : acionado(false), valor(0), nome{nome} {}

        // Função para ligar o componente
        void acionar() {
            acionado = true;
            cout << "Componente " << nome << " acionado." << endl;
        }

        // Função para desligar o componente
        void desativar() {
            acionado = false;
            cout << "Componente " << nome << " desativado." << endl;
        }

        // Função para obter o valor atual do componente
        int getValor() {
            return valor;
        }

        // Função para configurar um valor ao componente
        void setValor(int valor) {
                this-> valor = valor;
        }

        // Função para obter o nome do componente
        string getNome() {
            return nome;
        }
};
