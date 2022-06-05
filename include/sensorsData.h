#ifndef sensors_data_h
#define sensors_data_h

typedef struct sensors SensorsData;

SensorsData * RegisterSensorsData(float temperature, long int latitude, long int longitude, int fall);

void DeleteSensorsData(SensorsData * data);

#endif