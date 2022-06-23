#ifndef caregiver_list_h
#define caregiver_list_h
#include "caregiver.h"

//Definindo o tipo Carelist(lista de cuidadores)
typedef struct carelist CareList;


// ======================================================================================== //
/*Função para criar uma lista de cuidadores vazia
RECEBE:
    -> void
RETORNA:
    -> Carelist * = um ponteiro para o tipo lista de cuidadores
*/
CareList * CreateCareList();


// ======================================================================================== //
/*Função para inserir apenas um cuidador na lista de cuidadores
RECEBE:
    -> list = lista de cuidadores
    -> caregiver = cuidador
RETORNA:
    -> void
*/
void InsertOneCareGiver(CareList * list, Caregiver * caregiver);


// ======================================================================================== //
/*Função para ler os cuidadores d arquivo "cuidadores.txt", abrir o arquivo
/* de cada cuidador individualmente e inserí-los na lista de cuidadores
RECEBE:
    -> list = lista de cuidadores inicializada
    -> argv = quantidade de leituras dos sensores que será utilizada em funções internas
RETORNA:
    -> Carelist * = ponteiro para uma lista de cuidadores
*/
CareList * InsertCaregiversFromFileIntoList(CareList * list, char ** argv);


// ======================================================================================== //
/*Função para procurar um cuidador na lista por nome e retornar seu endereço de memória
RECEBE:
    -> carelist = lista de cuidadores
    -> name = nome do cuidador
RETORNA:
    -> Caregiver * = ponteiro para um cuidador
*/
Caregiver * ReturnCaregiverByName(CareList * carelist, char * name);


// ======================================================================================== //
/*Função para imprimir a lista de cuidadores no terminal
RECEBE:
    -> list = lista de cuidadores
RETORNA:
    -> void
*/
void PrintCaregiversList(CareList * list);


// ======================================================================================== //
/*Função para calcular qual é o cuidador com a menor distância em relação às
/*coordenadas passadas em seus parâmetros
RECEBE:
    -> coordinates = vetor de coordenadas com 2 elementos(latitude e longitude)
    -> carelist = lista de cuidadores 
    -> index = índice da leitura das coordenadas para procurar exatamente este
    mesmo índice nas coordenadas dos cuidadores da lista
RETORNA:
    -> Caregiver * = ponteiro para cuidador
*/
Caregiver * LessCaregiverDistance(long int * coordinates, CareList * carelist, int index);


// ======================================================================================== //
/*Função para liberar o espaço de memória alocado para a lista de cuidadores principal
RECEBE:
    -> list = lista de cuidadores
RETORNA:
    -> void
*/
void DestructCaregiversList(CareList * list);


// ======================================================================================== //
/*Função para liberar o esaço de memória alocado para uma lista de cuidadores
/*de um idoso espeífico
RECEBE:
    ->list = lista de cuidadores
RETORNA:
    -> void
*/
void DestructElderliesCaregiversList(CareList * list);

#endif