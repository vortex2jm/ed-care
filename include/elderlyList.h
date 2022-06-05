#ifndef elderly_list_h
#define elderly_list_h
#include "elderly.h"

typedef struct elderly_list ElderlyList;

ElderlyList * CreateElderlyList();

void InsertOnElderlyList(ElderlyList * list, Elderly * elderly);

void RemoveElderlyFromList(ElderlyList * list, char * nome);

void DestructElderlyList(ElderlyList * list);

#endif