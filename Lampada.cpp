#include "Atuador.cpp"
#include <iostream>
using namespace std;

class Lampada : public Atuador {
    public:
        // Construtor
        Lampada(string nome) : Atuador(nome) {}

        // Método para configurar o brilho da lâmpada
        bool setBrilho(int brilho) {
            setValor(brilho);
            if (brilho == 0) { // Lâmpada não emite brilho (desliga) quando já está claro
                this -> desligar();
                return true;
            }
            else { // Lâmpada emite brilho (liga) quando a luminosidade está baixa
                this -> ligar();
                return true;
            }
        }
};
