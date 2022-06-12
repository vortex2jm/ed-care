#ifndef caregiver_list_h
#define caregiver_list_h
#include "caregiver.h"

typedef struct carelist CareList;

CareList * CreateCareList();

CareList * InsertCaregiversFromFileIntoList(CareList * list, char ** argv);

void PrintCaregiversList(CareList * list);

#endif