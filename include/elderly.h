#ifndef elderly_h
#define elderly_h
#include "sensorsData.h"


// Definindo o tipo Elderly(idoso)
typedef struct elderly Elderly;


// ======================================================================================== //
/*Função para alocar memória para um novo idoso
RECEBE:
    -> name = nome do idoso
    -> data = um vetor de dados
    -> dataAmount = quantidade de dados que possui no vetor
RETORNA:
    -> Elderly* = ponteiro para idoso
*/
Elderly *RegisterElderly(char *name, SensorsData **data, int dataAmount);


// ======================================================================================== //
/*Função para imprimir o nome do idoso no terminal
RECEBE:
    -> elderly = ponteiro para idoso
RETORNA:
    -> void
*/
void PrintElderly(Elderly * elderly);


// ======================================================================================== //
/*Função para liberar o espaço de memória alocado para um idoso
RECEBE:
    -> elderly = ponteiro para idoso
RETORNA:
    -> void
*/
void KillElderly(Elderly *elderly);


// ======================================================================================== //
/*Função para retornar o nome do idoso
RECEBE:
    -> ponteiro para idoso
RETORNA:
    -> char* = uma string com o nome do idoso
*/
char * ElderlyName(Elderly * elderly);


// ======================================================================================== //
/*Função para retornar a quantidade de elementos do vetor de dados do idoso
RECEBE:
    -> elderly = ponteiro para idoso
RETORNA:
    -> int = quantidade de dados
*/
int ReturnDataAmount(Elderly * elderly);


// ======================================================================================== //
/*Função para retornar apenas um elemento do vetor de dados do idoso através de um índice específico
RECEBE:
    -> elderly = ponteiro para idoso
    -> index = índice correspondente ao elemento do vetor desejado 
RETORNA:
    -> SensorsData* = ponteiro para o tipo "dados dos sensores"(temperatura, localização e queda)
*/
SensorsData * ReturnSensorDataByIndex(Elderly * elderly, int index);


// ======================================================================================== //
/*Função para retornar o vetor de dados do idoso por completo
RECEBE:
    -> elderly = ponteiro para idoso
RETORNA:
    -> SensorsData** = vetor do tipo "dados do sensores"
*/
SensorsData ** ReturnAllData(Elderly * elderly);

#endif