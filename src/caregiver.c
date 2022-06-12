#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/caregiver.h"

struct caregiver{

    char * name;
    long int ** coordinates;
    int size;
};

Caregiver * RegisterCaregiver(char * name, long int ** coordinates, int size){

    Caregiver * newCaregiver = (Caregiver*)malloc(sizeof(Caregiver));

    newCaregiver->name = strdup(name);
    newCaregiver->coordinates = coordinates;
    newCaregiver->size = size;

    return newCaregiver;
}

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


void EliminateCaregiver(Caregiver * caregiver){

    if(caregiver != NULL){

        if(caregiver->name != NULL) free(caregiver->name);
        free(caregiver);
    }
}

void PrintCareGiver(Caregiver * caregiver){

    if(!caregiver) return;

    printf("nome: %s\n", caregiver->name);
    for(int x=0; x<caregiver->size;x++){

        printf("coordenadas: %ld , %ld\n", caregiver->coordinates[x][0], caregiver->coordinates[x][1]);
    }
    printf("\n");
}