#include <iostream>
#include <ctime>  // Para uso do time()
#include <thread> // Para sleep_for
#include <chrono> // Para usar minutos e segundos
#include "Sala.cpp"
using namespace std;

int main() {
    // Inicializa a semente para gerar números aleatórios
    srand(time(NULL));

    // Executa o laço 1440 vezes (sendo a cada minuto, resulta em atualizações o dia inteiro)
    Sala sala("Lâmpada", "Ventilador", "Umidificador", "Desumidificador", 
                "Sensor de Luminosidade", "Sensor de Temperatura", "Sensor de Umidade");
    for (int vezes = 0; vezes < 1440; vezes++) {
        sala.atualizarSensores(); // Atribui o método atualizar sensores a sala da vez
        sala.atualizarAtuadores(); // Atribui o método atualizar atuadores a sala da vez
        cout << "______________________________________________________________________________________________________   " << endl << endl;  // Separador para cada iteração
        this_thread::sleep_for(chrono::seconds(60)); // Faz gerar uma saída a cada 1 minuto.
        }
    return 0;
}