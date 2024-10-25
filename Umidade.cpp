#include "Sensor.cpp"
#include <iostream>
using namespace std;

class Umidade : public Sensor {
    public:
        // Construtor
        Umidade(string nome) : Sensor(nome) {}

        // Método para obter umidade relativa
        float getUmidade() { 
            return getValor(); 
        }

        void atualizarUmidade() {
            int umidade = rand() % 101; // Simulação de leitura de umidade entre 0 e 100%
            cout << "Umidade lida no " << getNome() << ": " << umidade << "%" << endl;
            setValor(umidade);
        }
};
