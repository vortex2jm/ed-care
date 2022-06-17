#ifndef elderly_h
#define elderly_h
#include "sensorsData.h"
#include "friendsList.h"
#include "caregiverList.h"

typedef struct elderly Elderly;

Elderly *RegisterElderly(char *name, SensorsData **data, int dataAmount);

void PrintElderly(Elderly * elderly);

void KillElderly(Elderly *elderly);

char * ElderlyName(Elderly * elderly);

void ProcessElderlyData(Elderly * elderly, Friends_List * friendsList, CareList * careList);

#endif