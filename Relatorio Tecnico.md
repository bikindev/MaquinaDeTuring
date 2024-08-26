## Relatório Técnico - Implementação de Máquina de Turing Universal
### Implementação: Patrícia Souza Couto, 202210524

#### 1. Introdução

Este relatório descreve a implementação de uma **Máquina de Turing** (MT) em C++. A Máquina de Turing é um modelo computacional teórico introduzido por Alan Turing, capaz de simular qualquer algoritmo computacional. Este projeto faz parte do trabalho final da disciplina **Teoria da Computação (GCC108)** e foi implementado por **Patrícia Souza Couto**.

O objetivo deste trabalho é implementar uma máquina de Turing com base em uma configuração fornecida em um arquivo de texto, realizar simulações com entradas fornecidas, e exibir o resultado da simulação, indicando se a palavra foi aceita ou rejeitada. O programa foi projetado para permitir a leitura de diferentes arquivos de configuração e diferentes palavras de entrada.

#### 2. Arquitetura do Programa

O código é dividido em três arquivos principais:
1. **MaquinaDeTuring.h**: Contém a definição da classe `MaquinaDeTuring` e da estrutura `Transicao`.
2. **MaquinaDeTuring.cpp**: Contém a implementação dos métodos da classe `MaquinaDeTuring`.
3. **main.cpp**: Contém a função principal que gerencia a leitura do arquivo de configuração e a execução da máquina de Turing.

#### 3. Descrição dos Componentes

##### 3.1. Classe `MaquinaDeTuring`

A classe `MaquinaDeTuring` modela o comportamento de uma máquina de Turing. Seus principais atributos são:
- **`estados`**: Um vetor que armazena todos os estados da máquina.
- **`alfabeto`**: Uma string que contém o alfabeto de entrada aceito pela máquina.
- **`alfabeto_fita`**: Uma string que representa os símbolos permitidos na fita da máquina.
- **`delta`**: Um vetor de `Transicao` que representa as funções de transição da máquina.
- **`estado_inicial`**: O estado inicial da máquina.
- **`estados_finais`**: Um vetor de estados finais, onde a máquina aceita a palavra.
- **`fita`**: Uma string que representa a fita da máquina.

##### 3.2. Estrutura `Transicao`

A estrutura `Transicao` é usada para modelar uma função de transição em uma máquina de Turing. Ela armazena o estado atual, o símbolo lido na fita, o estado de destino, o símbolo a ser escrito na fita e a direção em que a cabeça da fita deve se mover (esquerda, direita ou parada).

##### 3.3. Funções da Classe `MaquinaDeTuring`

- **Construtor**: Inicializa a máquina com os estados, transições e outros parâmetros.
- **`setFita`**: Define o conteúdo da fita, adicionando símbolos brancos ao final da palavra para simulação.
- **`getFita`**: Retorna o conteúdo da fita para exibição após a simulação.
- **`simular`**: Executa a simulação da máquina de Turing passo a passo. Essa função busca uma transição válida para cada posição da cabeça de leitura da fita, atualiza o estado e o símbolo conforme a transição, e move a cabeça da fita. A simulação para se a máquina alcança um estado final, ou se atinge um número máximo de iterações (`MAX = 5000`) para evitar loops infinitos.

#### 4. Lógica de Simulação

A função `simular` é responsável pela execução da lógica da máquina de Turing. Ela funciona da seguinte maneira:

1. **Cabeça de Leitura**: Inicializa a cabeça de leitura na posição inicial da fita (posição 0).
2. **Execução de Transições**: Para cada símbolo na fita, a máquina verifica se existe uma transição aplicável com base no estado atual e no símbolo lido. Se uma transição for encontrada, a máquina muda de estado, escreve o novo símbolo na fita e move a cabeça de acordo com a direção especificada (direita, esquerda ou parada).
3. **Verificação de Estado Final**: Se, após uma transição, o estado atual for um dos estados finais, a simulação é concluída com a palavra sendo aceita. Caso contrário, se a máquina não encontrar mais transições possíveis, a palavra é rejeitada.
4. **Contador de Iterações**: Um contador de iterações (`cont`) é usado para interromper a simulação se ela ultrapassar um número máximo de passos (5000), para evitar loops infinitos.

#### 5. Leitura da Configuração da Máquina

A função `lerArquivoConfig` lê o arquivo de configuração e extrai os seguintes componentes:
- Conjunto de estados da máquina.
- Estado inicial.
- Conjunto de estados finais.
- Alfabeto de entrada e da fita.
- Funções de transição.

Essas informações são usadas para configurar a máquina de Turing antes de iniciar a simulação.

#### 6. Controle de Loop Infinito

Um dos principais problemas que podem surgir em uma simulação de máquina de Turing é o risco de entrar em um loop infinito, onde a máquina continua processando indefinidamente sem nunca alcançar um estado final. Para evitar isso, foi introduzido um limite de iterações (`MAX = 5000`). Se o número de iterações ultrapassar esse valor, a máquina encerra a simulação.

#### 7. Teste e Execução

O programa é executado no terminal utilizando a seguinte sintaxe:

```
./MT <arquivo_config_mt>.txt <palavra_a_ser_testada> <arquivo_saida>.txt
```

Exemplo:
```
./MT config.txt 110_ saida.txt
```

1. **`arquivo_config_mt.txt`**: Arquivo contendo a configuração da máquina de Turing (estados, alfabeto, transições etc.).
2. **`palavra_a_ser_testada`**: Palavra inicial a ser colocada na fita para verificação pela máquina.
3. **`arquivo_saida.txt`**: Arquivo onde o resultado da simulação (aceita ou rejeita) será gravado, juntamente com o estado final da fita.

#### 8. Exemplo de Arquivo de Configuração

A seguir está um exemplo de arquivo de configuração que duplica o número de `'1'`s em uma fita:

```
q0 q1 q2 q3 q4 q5 q6
q0
q6
1
1_
q0 1 q1 _ D
q0 _ q5 1 D
q1 1 q1 1 D 
q1 _ q2 _ D 
q2 _ q3 1 E 
q2 1 q2 1 D 
q3 _ q4 _ E 
q3 1 q3 1 E 
q4 1 q4 1 E 
q4 _ q0 1 D 
q5 1 q5 1 D 
q5 _ q6 _ E 
q6 1 q6 _ N
```

#### 9. Resultados Esperados

Com base na configuração fornecida, a máquina processa a palavra de entrada, duplicando os `'1'`s. A palavra `"111"` seria transformada em `"111111"` e aceita pela máquina.

#### 10. Conclusão

Este programa oferece uma simulação funcional de uma máquina de Turing, capaz de processar palavras de acordo com uma configuração fornecida. A implementação inclui mecanismos de controle para evitar loops infinitos e oferece flexibilidade na definição das transições e estados da máquina. O sistema foi testado com várias configurações e palavras de entrada, demonstrando sua capacidade de simular diferentes linguagens e comportamentos computacionais.
