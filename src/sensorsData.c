#include <stdio.h>
#include <stdlib.h>
#include "../include/sensorsData.h"

struct sensors{

    float temperature;
    long int coordinates[2];
    int fall;

};

// Private function ================================================================================== //
SensorsData * RegisterSensorsData(float temperature, long int latitude, long int longitude, int fall){

    SensorsData * newSensorsData = malloc(sizeof(SensorsData));

    newSensorsData->temperature = temperature;
    newSensorsData->coordinates[0] = latitude;
    newSensorsData->coordinates[1] = longitude;
    newSensorsData->fall = fall;

    return newSensorsData; 
}

// Public functions =====================================================================================//
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

// ============================================================================================================= //
void PrintData(SensorsData * data){

    if(!data) return;
    //TEST ...........................
    printf("%ld %ld %d %.2f\n", data->coordinates[0], data->coordinates[1], data->fall,data->temperature);
}

// ======================================================================================== //
float ReturnTemperature(SensorsData * data){

    return data->temperature;
}

// ======================================================================================== //
long int * ReturnCoordinates(SensorsData * data){

    return data->coordinates;
}

// ======================================================================================== //
int ReturnFall(SensorsData * data){

    return data->fall;
}

// ======================================================================================== //
int AnalysisSensorsData(SensorsData * data){

    if(data->fall) return 1;

    if(data->temperature >= 38) return 2;

    if(data->temperature >= 37) return 3;

    return 0;
}

// ======================================================================================== //
int IsFourthLowFever(SensorsData ** data, int currentIndex){

    int lowFeverCounter=0;

    for(int x=0; x< currentIndex; x++){

        if(data[x]->temperature >= 38){

            lowFeverCounter =0;
        }

        else if(data[x]->temperature >= 37){

            lowFeverCounter++;
        }       
    }

    if(lowFeverCounter == 4) return 1;

    return 0;
}

// ======================================================================================== //
void DeleteSensorsDataArray(SensorsData ** array, int size){

    if(array){

        for(int x=0; x<size;x++){

            if(array[x]) DeleteSensorsData(array[x]);
        }

        free(array);
    }
}