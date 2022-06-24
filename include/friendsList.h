#ifndef friends_list_h
#define friends_list_h 
#include "elderly.h"

typedef struct friends_list Friends_List;


// ======================================================================================== //
/*Função para criar uma lista 
RECEBE:
RETORNA:
*/
Friends_List * CreateFriendsElderlyList();


// ======================================================================================== //
/*
RECEBE:
RETORNA:
*/
Friends_List * InsertOneFriendIntoList(Elderly * elderly, Friends_List * friends);


// ======================================================================================== //
/*
RECEBE:
RETORNA:
*/
void PrintFriendsList(Friends_List * friends,char * name);


// ======================================================================================== //
/*
RECEBE:
RETORNA:
*/
void DestructElderlyFriendsList(Friends_List * friends);


// ======================================================================================== //
/*
RECEBE:
RETORNA:
*/
void DestructOneFriendFromList(Friends_List * friends, char *name);


// ======================================================================================== //
/*
RECEBE:
RETORNA:
*/
Elderly * LessFriendDistance(Friends_List * list, long int * coordinates, int index);

#endif 