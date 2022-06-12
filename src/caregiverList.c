#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/caregiverList.h"
#include "../include/fileManager.h"
#include "../include/validation.h"

typedef struct cell Cell;

struct carelist {

    Cell * first;
    Cell * last;
};

struct cell {

    Caregiver * caregiver;
    Cell * next;
};





CareList * CreateCareList(){

    CareList * list = malloc(sizeof(CareList));

    list->first = NULL;
    list->last = NULL;

    return list;
}



// Private Function======================================================//
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





// Function to insert all caregivers at one time
CareList * InsertCaregiversFromFileIntoList(CareList * list, char ** argv){

    char * name, caregiverFileWay[50];
    FILE * caregiverFile;

    name = strtok(FileFirstLine("./tests/Teste1/Entradas/cuidadores.txt"), ";");

    while(name != NULL){

        sprintf(caregiverFileWay,"./tests/Teste1/Entradas/%s.txt", name);
        caregiverFile = fopen(caregiverFileWay, "r");

        InsertOneCareGiver(list, RegisterCaregiver(name,
                                 CareGiverDataReading(caregiverFile, NumberOfReadings(argv)),
                                 NumberOfReadings(argv)));
                           
        fclose(caregiverFile);

        name = strtok(NULL, ";");
    }

    return list;
}


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