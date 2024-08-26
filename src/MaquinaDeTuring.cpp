/*
* Trabalho Final - Teoria da Computação (GCC108)
* Sistemas de Informação - UFLA
* Implementado por: Patrícia Souza Couto, 202210524, Turma 14A
*/

#include "MaquinaDeTuring.h"

MaquinaDeTuring::MaquinaDeTuring(
        const vector<string>& estados, 
        string estado_inicial, 
        vector<string> estados_finais, 
        string alfabeto,
        string alfabeto_fita, 
        const vector<Transicao>& delta) 
        : estados(estados), estado_inicial(estado_inicial), estados_finais(estados_finais), alfabeto(alfabeto), alfabeto_fita(alfabeto_fita), delta(delta) {}

void MaquinaDeTuring::setFita(const string& fita) {
    this->fita = fita + "________"; // Adicionar o símbolo branco ao final da palavra de entrada na fita
}

string MaquinaDeTuring::getFita() {
    return fita;
}

/*
* Função para simular uma máquina de turing
* Responsável pela execução passo a passo da lógica da máquina
*/
bool MaquinaDeTuring::simular() {
    // Inicializar a cabeça da fita na primeira posição
    int posicao_cabeca = 0;
    // Inicializar o estado atual com o estado inicial na configuração da MT
    string estado_atual = estado_inicial;
    // Inicializar o contador de iterações para verificar se a máquina entrou em um possível loop infinito
    int cont = 0;
    // Inicializar o sentinela parou para parar a maquina caso ela entre em um possível loop infinito
    int parou = 0;

    // Enquanto não alcançar um estado final ou não houver mais transições possíveis ou não entrou em possível loop infinito , deve-se:
    // Encontrar a transição aplicável e, se encontrar, deve:
    // Atualizar o estado atual e o símbolo na fita e mover a cabeça
    while(true || parou == 0) {
        bool encontrou_transicao = false;
        
        for (const Transicao& transicao : delta) { // Percorrer todas as funções de transição da máquina
        
            if (transicao.estadoAtual == estado_atual && transicao.simboloAtual == fita[posicao_cabeca]) {
                estado_atual = transicao.estadoDestino;
                fita[posicao_cabeca] = transicao.simboloDestino;

                if (transicao.direcao == 'D') {
                    posicao_cabeca++; // Mover a cabeça da fita para a direita
                }
                else if (transicao.direcao == 'E') {
                    if (posicao_cabeca > 0) { // Evitar sair da fita
                        posicao_cabeca--; // Mover a cabeça da fita para a esquerda
                    }
                }
                encontrou_transicao = true;
                break;  // Interromper o loop após encontrar uma transição aplicável
            }
        }

        // Se não encontrou transição, verificar se a máquina está em um estado final
        // Se sim, então aceita a palavra, do contrário, rejeita
        if (!encontrou_transicao) {
            for (const string& estado_final : estados_finais) {
                if (estado_atual == estado_final) {
                    return true; // A palavra foi aceita
                }
            }
            return false; // A palavra foi rejeitada
        }

        // Se o número de iterações atingir o limite máximo definido, pode haver um possível loop inifito
        // Então a máquina para de computar
        cont++;
        if(cont >= MAX) {
            parou = 1;
        }
    }
}
