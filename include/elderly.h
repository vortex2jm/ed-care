#ifndef elderly_h
#define elderly_h

typedef struct elderly Elderly;

Elderly * RegisterElderly(char * name, SensorsData ** data, int dataAmount);

void SetElderlyName(Elderly * elderly, char * name);

void KillElderly(Elderly * elderly);

#endif