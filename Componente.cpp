#pragma once
#include <iostream>
using namespace std;

class Componente {
    private:
        bool ligado;       // Define se o componente está ligado (estado dos atuadores)
        bool conectado;    // Define se o componente está conectado (usado para definir se os sensores estarão ou não buscando valores)
        int valor;         // Valor atual do componente (pode ser leitura de um sensor ou estado de um atuador)
        string nome;       // Nome do componente para identificação

    public:
        // Construtor para inicializar o componente
        Componente(string nome) : ligado(false), conectado(false), valor(0), nome{nome} {}

        // Função para ligar o componente
        void ligar() {
            ligado = true;
            cout << "Componente " << nome << " ligado." << endl;
        }

        // Função para desligar o componente
        void desligar() {
            ligado = false;
            cout << "Componente " << nome << " desligado." << endl;
        }

        // Função para conectar o componente
        bool conectar() {
            conectado = true;
            cout << "Componente " << nome << " conectado." << endl;
            return conectado;
        }

        // Função para desconectar o componente
        void desconectar() {
            conectado = false;
            cout << "Componente " << nome << " desconectado." << endl;
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
