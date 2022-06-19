#ifndef sensors_data_h
#define sensors_data_h

typedef struct sensors SensorsData;

SensorsData ** CreateSensorsDataArray(int size, FILE * file);

void PrintData(SensorsData * data);

float ReturnTemperature(SensorsData * data);

long int * ReturnCoordinates(SensorsData * data);

int ReturnFall(SensorsData * data);

int AnalysisSensorsData(SensorsData * data);

void DeleteSensorsData(SensorsData * data);

int IsFourthLowFever(SensorsData ** data, int currentIndex);

void DeleteSensorsDataArray(SensorsData ** array, int size);

#endif