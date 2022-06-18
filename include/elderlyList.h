#ifndef elderly_list_h
#define elderly_list_h
#include "caregiverList.h"
#include "friendsList.h"


typedef struct elderly_list ElderlyList;



ElderlyList * CreateElderlyList();

ElderlyList * InsertElderliesFromFileIntoList(ElderlyList * list, char ** argv);

void PrintElderlyList(ElderlyList * list);

ElderlyList * AssigningCaregiversToElderlyList(CareList * caregiversList, ElderlyList * elderliesList);

void ProcessListData(ElderlyList * list);

ElderlyList * AssigningElderliesFriends(ElderlyList * list);

void RemoveDeadElderlyFromFriendsLists(ElderlyList * list,char *name);

void PrintTest(Friends_List * friends,char * name);

void PrintAllFriendsLists(ElderlyList * list);






//funções ainda nao implementadas
void RemoveElderlyFromList(ElderlyList * list, char * nome);

void DestructElderlyList(ElderlyList * list);

#endif