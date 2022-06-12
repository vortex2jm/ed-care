#ifndef elderly_list_h
#define elderly_list_h
#include "caregiverList.h"

typedef struct elderly_list ElderlyList;


// #Function to create a void elderly list#
ElderlyList * CreateElderlyList();

/* 
#Function to insert all elderlies read from 'apoio.txt' in to the list#

-> This function gets names from "apoio.txt" first line, uses these names to open
files that have elderlies names on name, get the data to create a new elderly and 
put in to the list.
*/
ElderlyList * InsertElderliesFromFileIntoList(ElderlyList * list, char ** argv);


/* 
#Function to print elderly list#

-> Only the names will be printed.
*/
void PrintElderlyList(ElderlyList * list);


ElderlyList * AssigningCaregiversToElderlyList(CareList * caregiversList, ElderlyList * elderliesList);


void RemoveElderlyFromList(ElderlyList * list, char * nome);

void DestructElderlyList(ElderlyList * list);

ElderlyList * Friends_Elders(ElderlyList * list);

#endif