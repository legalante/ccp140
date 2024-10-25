#include "Atuador.cpp"
#include <iostream>
using namespace std;

class Desumidificador : public Atuador {
    public:
        // Construtor
        Desumidificador(string nome) : Atuador(nome) {}

        // Método para configurar o nível do desumidificador
        bool setConfiguracao(int config) {
            setValor(config);
            if (config == 1 || config == 2) { // Desliga em umidade baixa ou ideal
                this -> desligar();
                return true;
            }
            else { // Liga em umidade alta
                this -> ligar();
                return true;
            }
        }
};
