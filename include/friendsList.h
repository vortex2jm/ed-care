#ifndef friends_list_h
#define friends_list_h 
#include "elderly.h"

typedef struct friends_list Friends_List;

Friends_List * CreateFriendsElderlyList();

Friends_List * InsertOneFriendIntoList(Elderly * elderly, Friends_List * friends);


// ======================================================================================== //
/*Função para imprimir uma lista de amigos no terminal
RECEBE:
RETORNA:
*/
void PrintFriendsList(Friends_List * friends,char * name);

void DestructElderlyFriendsList(Friends_List * friends);

void DestructOneFriendFromList(Friends_List * friends, char *name);

Elderly * LessFriendDistance(Friends_List * list, long int * coordinates, int index);

#endif 