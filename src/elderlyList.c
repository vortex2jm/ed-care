#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/validation.h"
#include "../include/elderlyList.h"
#include "../include/elderly.h"
#include "../include/fileManager.h"
#include "../include/sensorsData.h"

typedef struct cell Cell;

struct elderly_list {

    Cell * first;
    Cell * last;
};

struct cell {

    Elderly * elderly;
    Cell * next;
};

//====================================================================//
// Private funcion=========================================//
void InsertOneElderly(ElderlyList * list, Elderly * elderly){

    Cell * newCell = malloc(sizeof(Cell));
    newCell->elderly = elderly;
    
    if(!list->first){

        list->first = newCell;
        list->last = newCell;
        newCell->next = NULL;
    }

    else{

        newCell->next = list->first;
        list->first = newCell;
    }
}



// .h functions =========================================================//
ElderlyList * CreateElderlyList(){

    ElderlyList * list = calloc(1,sizeof(ElderlyList));
    list->first = NULL;
    list->last = NULL;

    return list;
}

ElderlyList * InsertElderliesIntoList(ElderlyList * list, char ** argv){

    // variables declaration
    char * name, firstLine[100], elderlyFileWay[50];
    FILE * elderlyFile;

    Elderly * fulano;
    SensorsData ** dados;


    // separating names from first line
    name = strtok(SupportFileFirstLine("./tests/Teste1/Entradas", firstLine),";"); 

    while(name != NULL){
        
        sprintf(elderlyFileWay, "./tests/Teste1/Entradas/%s.txt", name);
        elderlyFile = fopen(elderlyFileWay, "r");

        // Inserting elderlies into list one at time
        // InsertOneElderly(list, RegisterElderly(name,
        //                        CreateSensorsDataArray(NumberOfReadings(argv), elderlyFile),
        //                        NumberOfReadings(argv)));

        dados = CreateSensorsDataArray(NumberOfReadings(argv), elderlyFile);
        fulano = RegisterElderly(name, dados, NumberOfReadings(argv));
        InsertOneElderly(list, fulano);
        
        fclose(elderlyFile);

        // ending strtok
        name = strtok(NULL, ";");   
    }

    return list;
}

void PrintElderlyList(ElderlyList * list){

    Cell * current = list->first;
    Cell * aux;

    if(!list->first) {

        printf("Void list!\n\n");
        return;
    }
    
    while(current){

        aux = current->next;
        PrintElderly(current->elderly);
        current = aux;
    }
}