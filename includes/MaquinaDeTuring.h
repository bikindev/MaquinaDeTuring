/*
* Trabalho Final - Teoria da Computação (GCC108)
* Sistemas de Informação - UFLA
* Implementado por: Patrícia Souza Couto, 202210524, Turma 14A
*/
#ifndef MT_H
#define MT_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

// Definir o número máximo de iterações na simulação da máquina
// Para que ela pare caso entre em loop infinito
#define MAX 5000 

using namespace std;

// Estrutura para cada função de transição
struct Transicao {
    string estadoAtual;
    char simboloAtual;
    string estadoDestino;
    char simboloDestino;
    char direcao; // E: esquerda, N: parado, D: direita
};

class MaquinaDeTuring {
public:
    MaquinaDeTuring(const vector<string>& estados, string estado_inicial, vector<string> estados_finais, string alfabeto, string alfabeto_fita, const vector<Transicao>& delta);
    void setFita(const string& fita);
    string getFita();
    bool simular();

private:
    vector<string> estados; // Conjunto dos estados
    string alfabeto; // Alfabeto de entrada
    string alfabeto_fita; // Alfabeto da fita
    vector<Transicao> delta; // Funcoes de transicao
    string estado_inicial; // Estado inicial
    vector<string> estados_finais; // Conjunto dos estados finais
    string fita;
};

#endif