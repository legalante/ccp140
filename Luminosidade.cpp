#include "Sensor.cpp"
#include <iostream>
using namespace std;

class Luminosidade : public Sensor {
    private:
        int limiarClaridade;

    public:
        // Construtor
        Luminosidade(string nome) : Sensor(nome) {}

        // Métodos para definir e verificar o limiar de claridade
        void setLimiarClaridade(int limiarClaridade) { 
            this->limiarClaridade = limiarClaridade; 
        }

        int getLimiarClaridade() {
            return limiarClaridade;
        }

        void atualizarLuminosidade() {
            int luminosidade = rand() % 501; // 0 a 500
            cout << "Luminosidade lida no " << getNome() << ": " << luminosidade << " lux" << endl;
            setValor(luminosidade);
        }
        bool estaClaro() {
            if(getValor() > getLimiarClaridade()) {
                cout << "Está claro! A lâmpada não é necessária no momento." << endl;
                return true;
            } else {
                cout << "Está escuro! A lâmpada foi acesa." << endl;
                return false;
            }
        }

};
