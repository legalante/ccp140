#pragma once
#include "Atuador.cpp"
#include "Lampada.cpp"
#include "Ventilador.cpp"
#include "Umidificador.cpp"
#include "Desumidificador.cpp"
#include "Sensor.cpp"  
#include "Luminosidade.cpp"
#include "Temperatura.cpp"
#include "Umidade.cpp"
#include <iostream>
#include <thread> 
#include <chrono>
using namespace std;

class Sala {
private:
    Atuador* atuadores[12];  // Array de ponteiros para atuadores: lâmpada, ventilador, umidificador, desumidificador
    Sensor* sensores[9];   // Array de ponteiros para sensores: luminosidade, temperatura e umidade

public:
    Sala(string lampada, string ventilador, string umidificador, string desumidificador,
         string luminosidade, string temperatura, string umidade)
    {
        // Inicializando atuadores
        atuadores[0] = new Lampada(lampada);
        atuadores[1] = new Ventilador(ventilador);
        atuadores[2] = new Umidificador(umidificador);
        atuadores[3] = new Desumidificador(desumidificador);
        atuadores[4] = new Lampada(lampada);
        atuadores[5] = new Ventilador(ventilador);
        atuadores[6] = new Umidificador(umidificador);
        atuadores[7] = new Desumidificador(desumidificador);
        atuadores[8] = new Lampada(lampada);
        atuadores[9] = new Ventilador(ventilador);
        atuadores[10] = new Umidificador(umidificador);
        atuadores[11] = new Desumidificador(desumidificador);
        
        // Inicializando sensores
        sensores[0] = new Luminosidade(luminosidade);
        sensores[1] = new Temperatura(temperatura);
        sensores[2] = new Umidade(umidade);
        sensores[3] = new Luminosidade(luminosidade);
        sensores[4] = new Temperatura(temperatura);
        sensores[5] = new Umidade(umidade);
        sensores[6] = new Luminosidade(luminosidade);
        sensores[7] = new Temperatura(temperatura);
        sensores[8] = new Umidade(umidade);
    }

    // Destrutor da classe Sala para desalocar memória alocada dinamicamente
    ~Sala() {
        for (int i = 0; i < 9; ++i) {
            delete sensores[i];
        }
        for (int i = 0; i < 12; ++i) {
            delete atuadores[i];
        }
    }


    // Método para atualizar todos os sensores
    void atualizarSensores() {
        cout << "\n                                ==========================\n";
        cout << "--------------------------------|  Atualizando Sensores  |------------------------------------------\n";
        cout << "                                ==========================\n";
                cout << "\n______________________________________________________________________________________________________";
                cout << "\n                                       SALA 1                                                         ";
                cout << "\n______________________________________________________________________________________________________\n\n";
        
        for (int i = 0; i < 9; ++i) {
            sensores[i]->conectar();  // Conectar todos os sensores
            
            // Chamar métodos de atualização específicos
            if (i == 0) {
                Luminosidade* luminosidade = dynamic_cast<Luminosidade*>(sensores[0]); // Conversão dinâmica (dynamic_cast) de um ponteiro da classe base Sensor para um ponteiro da classe derivada Luminosidade
                luminosidade->atualizarLuminosidade();
                luminosidade->setLimiarClaridade(100); // Configura o valor de limiar claridade para cada sala (valores diferentes em cada uma das 3 salas)
            } else if (i == 1) {
                Temperatura* temperatura = dynamic_cast<Temperatura*>(sensores[1]);
                temperatura->atualizarTemperatura();
            } else if (i == 2) {
                Umidade* umidade = dynamic_cast<Umidade*>(sensores[2]);
                umidade->atualizarUmidade();
                cout << "\n______________________________________________________________________________________________________";
                cout << "\n                                       SALA 2                                                         ";
                cout << "\n______________________________________________________________________________________________________\n\n";
            }
            else if (i == 3) {
                Luminosidade* luminosidade_2 = dynamic_cast<Luminosidade*>(sensores[3]);
                luminosidade_2->atualizarLuminosidade();
                luminosidade_2->setLimiarClaridade(200);
            } else if (i == 4) {
                Temperatura* temperatura_2 = dynamic_cast<Temperatura*>(sensores[4]);
                temperatura_2->atualizarTemperatura();
            } else if (i == 5) {
                Umidade* umidade_2 = dynamic_cast<Umidade*>(sensores[5]);
                umidade_2->atualizarUmidade();
                cout << "\n______________________________________________________________________________________________________";
                cout << "\n                                       SALA 3                                                         ";
                cout << "\n______________________________________________________________________________________________________\n\n";
            }
            else if (i == 6) {
                Luminosidade* luminosidade_3 = dynamic_cast<Luminosidade*>(sensores[6]);
                luminosidade_3->atualizarLuminosidade();
                luminosidade_3->setLimiarClaridade(300);
            } else if (i == 7) {
                Temperatura* temperatura_3 = dynamic_cast<Temperatura*>(sensores[7]);
                temperatura_3->atualizarTemperatura();
            } else if (i == 8) {
                Umidade* umidade_3 = dynamic_cast<Umidade*>(sensores[8]);
                umidade_3->atualizarUmidade();
                cout << "\nSensores atualizados.\n";
            }
        }
        cout << "\n______________________________________________________________________________________________________\n";
    }

    // Método para verificar e atualizar os atuadores com base nos valores dos sensores
    void atualizarAtuadores() {
        cout << "\n                                 =========================\n";
        cout << "---------------------------------| Atualizando Atuadores |-------------------------------------------\n";
        cout << "                                 =========================\n";
                cout << "\n______________________________________________________________________________________________________";
                cout << "\n                                       SALA 1                                                         ";
                cout << "\n______________________________________________________________________________________________________\n\n";

        // Controla a lâmpada baseado na luminosidade
        Luminosidade* luminosidade = dynamic_cast<Luminosidade*>(sensores[0]);
        Lampada* lampada = dynamic_cast<Lampada*>(atuadores[0]);
        int brilho;
        if (luminosidade->estaClaro()) { // Luminosidade alta
            brilho = 0; // Lâmpada pode desligar
        }
        else {
            brilho = 1;
        }
        lampada->setBrilho(brilho);  // Atribuir o valor de brilho (determinado a partir da condição) no método setBrilho da classe lâmpada

        // Controla o ventilador baseado na temperatura
        Temperatura* temperatura = dynamic_cast<Temperatura*>(sensores[1]);
        Ventilador* ventilador = dynamic_cast<Ventilador*>(atuadores[1]);
        int velocidade;
        if (temperatura->getTemperaturaEmC() >= 25.0) {  // Temperatura alta o suficiente para ligra o ventilador
            if (temperatura->getTemperaturaEmC() < 30.0) {
                velocidade = 1; // Velocidade mínima
            }
            if (temperatura->getTemperaturaEmC() >= 30.0 && temperatura->getTemperaturaEmC() < 35.0) {
                velocidade = 2; // Velocidade média
            }
            if (temperatura->getTemperaturaEmC() >= 35.0) {
                velocidade = 3; // Velocidade máxima
            }
        }
        else {
            velocidade = 0; // Ventilador desligado (está frio)
        }
        ventilador->setVelocidade(velocidade); // Atribuir o valor da velocidade (determinada a partir da condição) no método setBrilho da classe ventilador

        // Controla umidificador e desumidificador baseado na umidade
        Umidade* umidade = dynamic_cast<Umidade*>(sensores[2]);
        Umidificador* umidificador = dynamic_cast<Umidificador*>(atuadores[2]);
        Desumidificador* desumidificador = dynamic_cast<Desumidificador*>(atuadores[3]);
        int config;
        if (umidade->getUmidade() > 55.0) {  // Ar úmido
            config = 0; // Umidificador desliga e desumidificador liga
        } 
        else if (umidade->getUmidade() < 45.0) { // Ar seco
            config = 1; // Desumidificador desliga e umidificador liga
        }
        else { // Condições ideais
            config = 2; // Ambos desligados
        }
        umidificador->setConfiguracao(config); // Confere os valores de config (configuração) ao método setConfiguração presente nas classes umidificaor e desumidificador 
        desumidificador->setConfiguracao(config);

        cout << "\nTodos os sensores da sala 1 serão desconectados até a medição do próximo minuto.\n"; // Desconecta os sensores aguardando a próxima medição, em que serão novamente conectados
        for (int i = 0; i < 3; ++i) {
            sensores[i]->desconectar();  // Desconectar todos os sensores da sala 1
        } 

                cout << "\n______________________________________________________________________________________________________";
                cout << "\n                                       SALA 2                                                         ";
                cout << "\n______________________________________________________________________________________________________\n\n";

        // Inicia-se o mesmo processo com a segunda sala, somente com diferentes intervalos de valores que acionam os atuadores

        Luminosidade* luminosidade_2 = dynamic_cast<Luminosidade*>(sensores[3]);
        Lampada* lampada_2 = dynamic_cast<Lampada*>(atuadores[4]);
        int brilho_2;
        if (luminosidade_2->estaClaro()) { 
            brilho_2 = 0; 
        }
        else {
            brilho_2 = 1;
        }
        lampada_2->setBrilho(brilho_2);  

        Temperatura* temperatura_2 = dynamic_cast<Temperatura*>(sensores[4]);
        Ventilador* ventilador_2 = dynamic_cast<Ventilador*>(atuadores[5]);
        int velocidade_2;
        if (temperatura_2->getTemperaturaEmC() >= 20.0) {  
            if (temperatura_2->getTemperaturaEmC() < 25.0) {
                velocidade_2 = 1;
            }
            if (temperatura_2->getTemperaturaEmC() >= 25.0 && temperatura_2->getTemperaturaEmC() < 30.0) {
                velocidade_2 = 2;
            }
            if (temperatura_2->getTemperaturaEmC() >= 30.0) {
                velocidade_2 = 3;
            }
        }
        else {
            velocidade_2 = 0;
        }
        ventilador_2->setVelocidade(velocidade_2);

        Umidade* umidade_2 = dynamic_cast<Umidade*>(sensores[5]);
        Umidificador* umidificador_2 = dynamic_cast<Umidificador*>(atuadores[6]);
        Desumidificador* desumidificador_2 = dynamic_cast<Desumidificador*>(atuadores[7]);
        int config_2;
        if (umidade_2->getUmidade() > 60.0) {  
            config_2 = 0;
        } 
        else if (umidade_2->getUmidade() < 40.0) { 
            config_2 = 1;
        }
        else {
            config_2 = 2;
        }
        umidificador_2->setConfiguracao(config_2);
        desumidificador_2->setConfiguracao(config_2);

        cout << "\nTodos os sensores da sala 2 serão desconectados até a medição do próximo minuto.\n";
        for (int i = 3; i < 6; ++i) {
            sensores[i]->desconectar();  // Desconectar todos os sensores da sala 2
        } 

                cout << "\n______________________________________________________________________________________________________";
                cout << "\n                                       SALA 3                                                         ";
                cout << "\n______________________________________________________________________________________________________\n\n";

        // Inicia-se o mesmo processo com a terceira sala, novamente com diferentes intervalos de valores que acionam os atuadores

        Luminosidade* luminosidade_3 = dynamic_cast<Luminosidade*>(sensores[6]);
        Lampada* lampada_3 = dynamic_cast<Lampada*>(atuadores[8]);
        int brilho_3;
        if (luminosidade_3->estaClaro()) { 
            brilho_3 = 0; 
        }
        else {
            brilho_3 = 1;
        }

        Temperatura* temperatura_3 = dynamic_cast<Temperatura*>(sensores[7]);
        Ventilador* ventilador_3 = dynamic_cast<Ventilador*>(atuadores[9]);
        int velocidade_3;
        if (temperatura_3->getTemperaturaEmC() >= 30.0) {  // Temperatura alta
            if (temperatura_3->getTemperaturaEmC() < 35.0) {
                velocidade_3 = 1;
            }
            if (temperatura_3->getTemperaturaEmC() >= 35.0 && temperatura_3->getTemperaturaEmC() < 40.0) {
                velocidade_3 = 2;
            }
            if (temperatura_3->getTemperaturaEmC() >= 40.0) {
                velocidade_3 = 3;
            }
        }
        else {
            velocidade_3 = 0;
        }
        ventilador_3->setVelocidade(velocidade_3);

        Umidade* umidade_3 = dynamic_cast<Umidade*>(sensores[8]);
        Umidificador* umidificador_3 = dynamic_cast<Umidificador*>(atuadores[10]);
        Desumidificador* desumidificador_3 = dynamic_cast<Desumidificador*>(atuadores[11]);
        int config_3;
        if (umidade_3->getUmidade() > 70.0) {  
            config_3 = 0;
        } 
        else if (umidade_3->getUmidade() < 30.0) { 
            config_3 = 1;
        }
        else {
            config_3 = 2;
        }
        umidificador_3->setConfiguracao(config_3);
        desumidificador_3->setConfiguracao(config_3);

        cout << "\nTodos os sensores da sala 3 serão desconectados até a medição do próximo minuto.\n";
        for (int i = 6; i < 9; ++i) {
            sensores[i]->desconectar();  // Desconectar todos os sensores da sala 3
        } 
        cout << "\n______________________________________________________________________________________________________\n";
    }
};

