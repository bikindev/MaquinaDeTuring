# MaquinaDeTuring
Implementação de uma Máquina de Turing Universal para a disciplina de Teoria da Computação - GCC108
Sistemas de Informação - UFLA
Implementado por: Patrícia Souza Couto, 202210524, Turma 14A

Para compilar, mantenha a mesma estrutura de diretórios deste repositório e use o makefile:
```make```

Para executar, use:
```./MT <arquivo_configuracao>.txt <palavra a ser testada> <arquivo_saida>.txt```

O arquivo de configuração da máquina deve seguir o padrão:
```
q0 q1   // Conjunto de estados
q0      // Estado inicial
q1      // Conjunto de estados finais
a b     // Alfabeto de entrada
a b _   // Alfabeto da fita
q0 a q1 _ D  // Funções de transição, na seguinte forma:
q0 b q0 b D  // (estado de origem, simbolo lido) -> (estado de destino, simbolo escrito, direção do movimento da cabeça)
q0 _ q1 _ D
q1 a q1 a D
q1 b q1 b D
q1 _ q1 _ N
```
Será gerado um arquivo de saída com o nome fornecido no momento da execução contendo o conteúdo da fita ao final da computação e se a palavra é aceita ou não pela máquina.
