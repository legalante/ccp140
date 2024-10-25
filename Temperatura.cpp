#include "Sensor.cpp"
#include <iostream>
using namespace std;

class Temperatura : public Sensor {
    public:
        // Construtor
        Temperatura(string nome) : Sensor(nome) {}

        // Métodos para retornar a temperatura em diferentes unidades
        float getTemperaturaEmC() { 
            return getValor(); 
            }
        float getTemperaturaEmF() { 
            return (getTemperaturaEmC() * 9.0/5.0) + 32.0; 
            }

        float getTemperaturaEmK() { 
            return getTemperaturaEmC() + 273; 
            }

        void atualizarTemperatura() {
            int temperatura = rand() % 36 + 10; // Simulação de leitura de temperatura entre 10 e 45 °C
            setValor(temperatura);
            
            // Exibir a temperatura nas diferentes unidades
            cout << "Temperatura lida no " << getNome() << ": " << temperatura << " °C" << endl;
            cout << "Temperatura em Fahrenheit: " << getTemperaturaEmF() << " °F" << endl;
            cout << "Temperatura em Kelvin: " << getTemperaturaEmK() << " K" << endl;
        }
};
