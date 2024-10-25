#include "Atuador.cpp"
#include <iostream>
using namespace std;

class Ventilador : public Atuador {
    public:
        // Construtor
        Ventilador(string nome) : Atuador(nome) {}

        // Método para definir a velocidade e estado do ventilador 
        bool setVelocidade(int velocidade) {
            setValor(velocidade);
            if (velocidade == 0) {
                cout << "Está frio. O ventilador não será ligado no momento." << endl;
                this -> desligar();
                return true;
            }
            else {
                cout << "A temperatura está alta o suficiente para ligar o ventilador." << endl;
                this -> ligar();
                if (velocidade == 1) {
                    cout << "Velocidade do ventilador: mínima." << endl;
                }
                if (velocidade == 2) {
                    cout << "Velocidade do ventilador: média." << endl;
                }
                if (velocidade == 3) {
                    cout << "Velocidade do ventilador: máxima." << endl;
                }
                return true;
            }
        }
};
