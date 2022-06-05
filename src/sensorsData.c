#include <stdio.h>
#include <stdlib.h>
#include "../include/sensorsData.h"

struct sensors{

    float temperature;
    long int coordinates[2];
    int fall;

};

SensorsData * RegisterSensorsData(float temperature, long int latitude, long int longitude, int fall){

    SensorsData * newSensorsData = malloc(sizeof(SensorsData));

    newSensorsData->temperature = temperature;
    newSensorsData->coordinates[0] = latitude;
    newSensorsData->coordinates[1] = longitude;
    newSensorsData->fall = fall;

    return newSensorsData; 
}

void DeleteSensorsData(SensorsData * data){

    if(data) free(data);
}