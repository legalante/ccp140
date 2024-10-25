#include "Sensores.cpp"
#include <iostream>
using namespace std;

class Proximidade : public Sensores {
    private:
        int limiteProximidade;
        int proximidadeSegura;

    public:
        // Construtor
        Proximidade(string nome) : Sensores(nome) {}

        // Métodos para definir e verificar o limiar de claridade
        void setLimiteProximidade(int limiteProximidade) { 
            this->limiteProximidade = limiteProximidade; 
        }

        int getLimiteproximidade() {
            return limiteProximidade;
        }

        void valorProximidadee() {
            int velocidade = rand() % 251; // 0 a 500
            //cout << "Velocidade do veículo " << getNome() << ": " << velocidade << " km/h" << endl;
            setValor(velocidade);
        }
        void riscoBatida() {
            }
        }

};
