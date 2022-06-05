#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/caregiver.h"

struct caregiver{

    char * name;
    long int coordinates[2];
};

Caregiver * RegisterCaregiver(char * name, long int latitude, long int longitude){

    Caregiver * newCaregiver = (Caregiver*)malloc(sizeof(Caregiver));

    newCaregiver->name = strdup(name);
    newCaregiver->coordinates[0] = latitude;
    newCaregiver->coordinates[1] = longitude;

    return newCaregiver;
}

void EliminateCaregiver(Caregiver * caregiver){

    if(caregiver != NULL){

        if(caregiver->name != NULL) free(caregiver->name);
        free(caregiver);
    }
}