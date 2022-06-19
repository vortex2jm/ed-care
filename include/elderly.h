#ifndef elderly_h
#define elderly_h
#include "sensorsData.h"

typedef struct elderly Elderly;

Elderly *RegisterElderly(char *name, SensorsData **data, int dataAmount);

void PrintElderly(Elderly * elderly);

void KillElderly(Elderly *elderly);

char * ElderlyName(Elderly * elderly);

int ReturnDataAmount(Elderly * elderly);

SensorsData * ReturnSensorDataByIndex(Elderly * elderly, int index);

SensorsData ** ReturnAllData(Elderly * elderly);

#endif