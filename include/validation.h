#ifndef validation_h
#define validation_h

/*Função para verificar se há argumentos na linha de comando. Esta função encerra o programa
e exibe uma mensagem caso não haja argumentos
RECEBE:
    -> argc = parâmetro da função main (quantidade de argumentos da linha de comando)
RETORNA:
    -> int = um inteiro indicando se há argumentos
*/
int ValidateArg(int argc);

/*Função para pegar o primeiro argumento (que terá a quantidade de leituras do sensor) e 
retorná-lo como um inteiro
RECEBE:
    -> argv = parâmetro da função main (argumento da linha de comando)
RETORNA:
    -> int = inteiro com o número de leituras dos sensores
*/
int NumberOfReadings(char ** argv);

#endif