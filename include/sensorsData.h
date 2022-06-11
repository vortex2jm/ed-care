#ifndef sensors_data_h
#define sensors_data_h

typedef struct sensors SensorsData;

SensorsData ** CreateSensorsDataArray(int size, FILE * file);

void PrintData(SensorsData * data);

void DeleteSensorsData(SensorsData * data);

#endif