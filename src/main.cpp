/*
* Trabalho Final - Teoria da Computação (GCC108)
* Sistemas de Informação - UFLA
* Implementado por: Patrícia Souza Couto, 202210524, Turma 14A
*/

#include "MaquinaDeTuring.h"

void lerArquivoConfig(const string& arquivo_config, vector<string>& estados, string& estado_inicial, vector<string>& estados_finais, string& alfabeto, string& alfabeto_fita,vector<Transicao>& delta) {
    ifstream arq(arquivo_config);
    if (!arq.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return;
    }
   
    string linha;

    // Leitura dos estados
    getline(arq, linha); // Usar getline para ler linhas inteiras
    istringstream iss(linha); // Usar istringstream para quebrar a linha em tokens
    string estado; // dois caracteres definem um estado
    while (iss >> estado) {
        estados.push_back(estado);
    }

    // Leitura do estado inicial
    getline(arq, linha);
    estado_inicial = linha;
    
    // Leitura dos estados finais
    getline(arq, linha);
    istringstream iss2(linha);
    while (iss2 >> estado) {
        estados_finais.push_back(estado);
    }

    // Leitura do alfabeto de entrada
    getline(arq, linha);
    alfabeto = linha;

    // Leitura do alfabeto da fita
    getline(arq, linha);
    alfabeto_fita = linha;

    // Leitura das funções de transição
    while (getline(arq, linha)) {
        istringstream iss3(linha);
        string estado_atual, estado_destino;
        char simbolo_atual, simbolo_destino, direcao;

        iss3 >> estado_atual >> simbolo_atual >> estado_destino >> simbolo_destino >> direcao;

        if (!iss3.fail()) {
            delta.push_back({estado_atual, simbolo_atual, estado_destino, simbolo_destino, direcao});
        }
    }

    // Fechar o arquivo
    arq.close();
}

// Função principal
int main(int argc, char* argv[]) {
    // Verificar se todos os argumentos de entrada foram escritos
    if (argc != 4) {
        return 1;
    }

    // Variáveis para armazenar os argumentos de entrada
    string config_mt = argv[1]; // Arquivo de configuração da MT
    string palavra = argv[2];   // Palavra a ser verificada pela MT
    string arquivo_saida = argv[3]; // Arquivo de saída com o resultado da simulação

    // Variáveis para armazenar os dados de configuração lidos
    vector<string> estados;
    string estado_inicial = "";
    vector<string> estados_finais;
    string alfabeto = "";
    string alfabeto_fita = "";
    vector<Transicao> delta;

    // Ler o arquivo de configuração da máquina
    lerArquivoConfig(config_mt, estados, estado_inicial, estados_finais, alfabeto, alfabeto_fita, delta);

    // Criar instância da Maquina de Turing
    MaquinaDeTuring mt(estados, estado_inicial, estados_finais, alfabeto, alfabeto_fita, delta);

    // Setar a fita
    mt.setFita(palavra);

    // Simular a máquina de Turing
    bool aceita_ou_rejeita = mt.simular();

    // Escrever o resultado da simulação no arquivo
    ofstream saida(arquivo_saida);
    if (aceita_ou_rejeita) {
        saida << mt.getFita() << endl;
        saida << "Aceita" << endl; // Palavra aceita
    }
    else {
        saida << mt.getFita() << endl;
        saida << "Rejeita" << endl; // Palavra reijeitada
    }

    saida.close();

    cout << "Fim" << endl;

    return 0;
}
