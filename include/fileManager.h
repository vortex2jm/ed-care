#ifndef file_manager_h
#define file_manager_h

//Arquivo com funções auxiliares (Funções utilizadas em mais de um TAD)


/*Função para retornar a primeira linha de um arquivo
RECEBE:
    -> way = string com o caminho para o diretório do arquivo
RETORNA:
    -> char* = uma string com a primeira linha do arquivo
*/
char * FileFirstLine(char * way);


/*Função para calcular a distância entre duas coordenadas
RECEBE:
    -> coordinates1/2 = coordenadas a serem comparadas
RETORNA:
    -> double = valor da distânia em ponto flutuante
*/
double Distance(long int * coordinates1, long int * coordinates2);

#endif