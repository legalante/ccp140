#include "Sensores.cpp"
#include <iostream>
using namespace std;

class Velocidade : public Sensores {
    private:
        int limiteVelocidade;

    public:
        // Construtor
        Velocidade(string nome) : Sensores(nome) {}

        // Métodos para definir e verificar o limiar de claridade
        void setLimiteVelocidade(int limiteVelocidade) { 
            this->limiteVelocidade = limiteVelocidade; 
        }

        int getLimiteVelocidade() {
            return limiteVelocidade;
        }

        void valorVelocidade() {
            int velocidade = rand() % 251; // 0 a 500
            cout << "Velocidade do veículo " << getNome() << ": " << velocidade << " km/h" << endl;
            setValor(velocidade);
        }
        bool acimaLimite() {
            if(getValor() > getLimiteVelocidade()) {
                cout << "VAI LEVAR MULTA ANIMAL" << endl;
                return true;
            } else {
                cout << "ta levando a vovozinha?" << endl;
                return false;
            }
        }

};
