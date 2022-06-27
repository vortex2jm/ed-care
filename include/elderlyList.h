#ifndef elderly_list_h
#define elderly_list_h
#include "caregiverList.h"
#include "friendsList.h"

// Definindo o tipo ElderlyList(lista de idosos)
typedef struct elderly_list ElderlyList;

// ======================================================================================== //
/*Função para iniciaizar uma lista de idosos vazia na memória
RECEBE:
    -> void
RETORNA:
    -> ponteiro para lista de idosos
*/
ElderlyList * CreateElderlyList();


// ======================================================================================== //
/*Função para inserir todos os idosos do arquivo "apoio.txt" na lista de idosos
RECEBE:
    -> list = ponteiro para lista de idosos
    -> argv = quantidade de dados lidas pelos sensores(será utilizado em funções internas)
RETORNA:
    -> ElderlyList* = ponteiro para lista de idosos
*/
ElderlyList * InsertElderliesFromFileIntoList(ElderlyList * list, char ** argv);


// ======================================================================================== //
/*Função que imprime a lista de idosos e suas respectivas listas de cuidadores no terminal
RECEBE:
    -> list = ponteiro para lista de idosos
RETORNA:
    -> void
*/
void PrintElderlyList(ElderlyList * list);


// ======================================================================================== //
/*Função para atribuir os cuidadores da lista de cuidadres principal às listas de cuidadores dos idosos
RECEBE:
    -> caregiversList = ponteiro para lista de cuidadores principal
    -> elderliesList = ponteiro para a lista de idosos
RETORNA:
    -> ElderlyList* = ponteiro para lista de idosos
*/
ElderlyList * AssigningCaregiversToElderlyList(CareList * caregiversList, ElderlyList * elderliesList);


// ======================================================================================== //
/*Função para tratar os dados dos idosos e gerar as respectivas saídas
RECEBE:
    -> list = ponteiro para lista de idosos a ser analisada
RETORNA:
    -> void
*/
void ProcessListData(ElderlyList * list);


// ======================================================================================== //
/*Função para atribuir os amigos dos idosos em suas listas de amigos
RECEBE:
    -> list = ponteiro para lista de idosos
RETORNA:
    -> ElderlyList* = ponteiro para lista de idosos
*/
ElderlyList * AssigningElderliesFriends(ElderlyList * list);


// ======================================================================================== //
/*Função para imprimir as listas de amigos de todos os idosos da lista de idosos no terminal
RECEBE:
    ->list = ponteiro para lista de idosos
RETORNA:
    -> void
*/
void PrintAllFriendsLists(ElderlyList * list);


// ======================================================================================== //
/*Função para liberar o espaço de memória alocado para a lista de idosos
RECEBE:
    -> list = ponteiro para lista de idosos
RETORNA:
    -> void
*/
void DeleteElderlyList(ElderlyList * list);

#endif