#include <stdio.h>
#include <stdlib.h>
#include "../include/sensorsData.h"

struct sensors{

    float temperature;
    long int coordinates[2];
    int fall;

};
// Private function
SensorsData * RegisterSensorsData(float temperature, long int latitude, long int longitude, int fall){

    SensorsData * newSensorsData = malloc(sizeof(SensorsData));

    newSensorsData->temperature = temperature;
    newSensorsData->coordinates[0] = latitude;
    newSensorsData->coordinates[1] = longitude;
    newSensorsData->fall = fall;

    return newSensorsData; 
}

// .h functions
void DeleteSensorsData(SensorsData * data){

    if(data) free(data);
}

SensorsData ** CreateSensorsDataArray(int size, FILE * file){

    SensorsData ** data = calloc(size, sizeof(SensorsData*));
    int fall=0, fscanfRtn;
    float temperature=0;
    long int latitude=0, longitude=0;

    for(int x=0; size;x++){     // NumberOfReadings returns the number inserted on command line

        fscanfRtn = fscanf(file, "%f;%ld;%ld;%d", &temperature, &latitude, &longitude, &fall);
        

        if(fscanfRtn != 4){ // If return != 4, elderly died

            for(int y=x; y<size;y++){
                data[x] = NULL;         // filling another fields with null value
            }
            break;
        } 
        
        data[x] = RegisterSensorsData(temperature, latitude, longitude, fall);  // Filling sensors data array
        
        
    }

    return data;
}

void PrintData(SensorsData * data){

    if(!data) return;
    //TEST ...........................
    printf("%ld %ld %d %.2f\n", data->coordinates[0], data->coordinates[1], data->fall,data->temperature);
    
    /*
    printf("%ld %ld\n", data->coordinates[0], data->coordinates[1]);
    printf("queda: %d\n", data->fall);
    printf("temperatura: %.2f\n\n", data->temperature);
    */
}