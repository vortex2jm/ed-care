#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/caregiver.h"

struct caregiver{

    char * name;
    long int ** coordinates;
    int size;
};


// Public Functions ======================================================================//
Caregiver * RegisterCaregiver(char * name, long int ** coordinates, int size){

    Caregiver * newCaregiver = (Caregiver*)malloc(sizeof(Caregiver));

    newCaregiver->name = strdup(name);
    newCaregiver->coordinates = coordinates;
    newCaregiver->size = size;

    return newCaregiver;
}

// ========================================================================================= //
long int ** CareGiverDataReading(FILE * file, int size){

    long int ** data = malloc(sizeof(long int *) * size);
    for(int x=0; x<size;x++){
        data[x] = malloc(sizeof(long int) * 2);
    }

    for(int x=0; x<size;x++){

        fscanf(file,"%ld;%ld\n", &data[x][0], &data[x][1]);    
    }

    return data;
}

// ==================================================================================================== //
void EliminateCaregiver(Caregiver * caregiver){

    if(caregiver){

        if(caregiver->name) free(caregiver->name);

        if(caregiver->coordinates){

            for(int x=0; x<caregiver->size; x++){

                if(caregiver->coordinates[x]) free(caregiver->coordinates[x]);
            }

            free(caregiver->coordinates);
        }

        free(caregiver);
    }
}

// ==================================================================================================== //
void PrintCareGiver(Caregiver * caregiver){

    if(!caregiver) return;

    printf("nome: %s\n", caregiver->name);

}

// ==================================================================================================== //
char * CaregiverName(Caregiver * caregiver){

    return caregiver->name;
}

// ==================================================================================================== //
long int * ReturnCaregiverLocation(Caregiver * caregiver, int index){

    return caregiver->coordinates[index];
}