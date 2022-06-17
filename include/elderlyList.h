#ifndef elderly_list_h
#define elderly_list_h
#include "elderly.h"

typedef struct elderly_list ElderlyList;

ElderlyList * CreateElderlyList();

ElderlyList * InsertElderliesIntoList(ElderlyList * list, char ** argv);

void RemoveElderlyFromList(ElderlyList * list, char * nome);

void PrintElderlyList(ElderlyList * list);

void DestructElderlyList(ElderlyList * list);

ElderlyList * Friends_Elders(ElderlyList * list);

//teste ...........

void Destroy_list_of_dead_elderly(ElderlyList * list,char *name);


void Imprimi (ElderlyList * list);


#endif