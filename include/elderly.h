#ifndef elderly_h
#define elderly_h
#include "sensorsData.h"

typedef struct elderly Elderly;

Elderly *RegisterElderly(char *name, SensorsData **data, int dataAmount);

void PrintElderly(Elderly * elderly);

void KillElderly(Elderly *elderly);

char * Return_name(Elderly * elder);

#endif