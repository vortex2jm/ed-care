#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/elderly.h"
#include "../include/sensorsData.h"


struct elderly {

    char * name;
    SensorsData ** data;
    int dataAmount;
};


Elderly * RegisterElderly(char * name, SensorsData ** data, int dataAmount){

    Elderly * newElderly = (Elderly*) malloc(sizeof(Elderly));

    newElderly->name = strdup(name);
    newElderly->data = data;
    newElderly->dataAmount = dataAmount;

    return newElderly;
}


Elderly * CreateVoidElderly(){

    Elderly * newElderly = (Elderly*) malloc(sizeof(Elderly));
    newElderly->name = NULL;

    return newElderly;
}


void SetElderlyName(Elderly * elderly, char * name){

    if(!elderly->name) elderly->name = strdup(name);
    else strcpy(elderly->name, name);
}


void KillElderly(Elderly * elderly){

}