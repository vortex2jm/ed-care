#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/caregiverList.h"
#include "../include/fileManager.h"
#include "../include/validation.h"
#include "../include/caregiver.h"

typedef struct cell Cell;

//Sentinela
struct carelist {

    Cell * first;
    Cell * last;
};

//Célula
struct cell {

    Caregiver * caregiver;
    Cell * next;
};


// Funções públicas ====================================================================//
CareList * CreateCareList(){

    CareList * list = malloc(sizeof(CareList));

    list->first = NULL;
    list->last = NULL;

    return list;
}


// ==================================================================================================== //
void InsertOneCareGiver(CareList * list, Caregiver * caregiver){

    Cell * newCell = malloc(sizeof(Cell));
    newCell->caregiver = caregiver;

    if(!list->first){

        list->first = newCell;
        list->last = newCell;
        newCell->next = NULL;
    }

    else{

        list->last->next = newCell;
        list->last = newCell;
        newCell->next = NULL;
    }
}


// ==================================================================================================== //
CareList * InsertCaregiversFromFileIntoList(CareList * list, char ** argv){

    char * name, caregiverFileWay[100];
    FILE * caregiverFile;

    name = strtok(FileFirstLine("./cuidadores.txt"), ";");

    while(name != NULL){

        sprintf(caregiverFileWay,"./%s.txt", name);
        caregiverFile = fopen(caregiverFileWay, "r");

        InsertOneCareGiver(list, RegisterCaregiver(name,
                                 CareGiverDataReading(caregiverFile, NumberOfReadings(argv)),
                                 NumberOfReadings(argv)));

        fclose(caregiverFile);

        name = strtok(NULL, ";");
    }

    return list;
}


// ==================================================================================================== //
void PrintCaregiversList(CareList * list){

    Cell * current, * aux;

    current = list->first;

    if(!list->first){
        printf("Void list!\n\n");
        return;
    }

    while(current){

        aux = current->next;
        PrintCareGiver(current->caregiver);
        current = aux;
    }
}


// ==================================================================================================== //
Caregiver * ReturnCaregiverByName(CareList * carelist, char * name){

    Cell * aux = carelist->first;

    while(aux && strcmp(name, CaregiverName(aux->caregiver))){

        aux = aux->next;
    }

    return aux->caregiver;
}


// ==================================================================================================== //
Caregiver * LessCaregiverDistance(long int * coordinates, CareList * carelist, int index){

    if(!carelist) return NULL;

    Caregiver * lessDistanceCaregiver;
    Cell * current;

    current = carelist->first->next;
    lessDistanceCaregiver = carelist->first->caregiver;


    while(current){

        if(Distance(coordinates, ReturnCaregiverLocation(current->caregiver, index)) 
        < Distance(coordinates, ReturnCaregiverLocation(lessDistanceCaregiver, index))
        ){

            lessDistanceCaregiver = current->caregiver;
        }
        current = current->next;
    }
    return lessDistanceCaregiver;
}


// ==================================================================================================== //
void DestructCaregiversList(CareList * list){

    Cell * current = list->first;
    Cell * next = NULL;

    if(list){

        while(current){

            if(current->caregiver) EliminateCaregiver(current->caregiver);

            next = current->next;
            free(current);
            current = next;
        }
        free(list);
    }
}


// ==================================================================================================== //
void DestructElderliesCaregiversList(CareList * list){

    Cell * current, * next;
    current = list->first;

    if(list){

        while(current){

            next = current->next;
            free(current);
            current = next;
        }
        free(list);
    }
}