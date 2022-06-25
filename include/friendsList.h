#ifndef friends_list_h
#define friends_list_h 
#include "elderly.h"

// Definindo o tipo Friends_List(lista de amigos)
typedef struct friends_list Friends_List;


// ======================================================================================== //
/*Função para criar uma lista de amigos vazia
RECEBE:
    -> void
RETORNA:
    -> Friends_List* = ponteiro para lista de amigos
*/
Friends_List * CreateFriendsElderlyList();


// ======================================================================================== //
/*Função para inserir apenar um idoso na lista de amigos
RECEBE:
    -> elderly = ponteiro pra idoso
    -> friends = ponteiro para lista de amigos
RETORNA:
    -> Friends_List* = ponteiro para lista de amigos
*/
Friends_List * InsertOneFriendIntoList(Elderly * elderly, Friends_List * friends);


// ======================================================================================== //
/*Função para imprimir a lista de amigos de um idoso específico no terminal
RECEBE:
    -> friends = lista de amigos
    -> name = nome do idoso no qual vai ser impressa a lista de amigos
RETORNA:
    -> void
*/
void PrintFriendsList(Friends_List * friends,char * name);


// ======================================================================================== //
/*Função para liberar o espaço de memória alocado para uma lista de amigos
RECEBE:
    -> friends = ponteiro para lista de amigos a ser liberada
RETORNA:
    -> void
*/
void DestructElderlyFriendsList(Friends_List * friends);


// ======================================================================================== //
/*Função para varrer uma lista de amigos, ler os dados de apenas um elemento de seus vetores de 
dados e retornar o idoso com menor distância em relação às coordenadas passadas no parâmetro 
RECEBE:
    -> list = lista de amigos
    -> coordinates = coordenadas que serão comparadas com as coordenadas de cada idoso da lista
    -> index = índice para um elemento específico do vetor de dados dos idosos
RETORNA:
    -> Elderly * = ponteiro para idoso
*/
Elderly * LessFriendDistance(Friends_List * list, long int * coordinates, int index);

#endif 