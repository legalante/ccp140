#include "Atuador.cpp"
#include <iostream>
using namespace std;

class Umidificador : public Atuador {
    public:
        // Construtor
        Umidificador(string nome) : Atuador(nome) {}

        // Método para configurar o nível do umidificador
        bool setConfiguracao(int config) {
            setValor(config);
            if (config == 0 || config == 2) { // Desliga quando a umidade está alta ou ideal
                if (config == 0) {
                    cout << "A umidade do ar está alta." << endl;
                }
                else {
                    cout << "A umidade do ar está ideal." << endl;
                }
                this -> desligar();
                return true;
            }
            else { // Liga quando a umidade está baixa
                cout << "A umidade do ar está baixa." << endl;
                this -> ligar();
                return true;
            }
        }
};
