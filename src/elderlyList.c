// Elderly list functions implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/validation.h"
#include "../include/elderlyList.h"
#include "../include/elderly.h"
#include "../include/fileManager.h"
#include "../include/sensorsData.h"

// defining cell type
typedef struct cell Cell;

// sentinel 
struct elderly_list {

    Cell * first;
    Cell * last;
};

// cell structure
struct cell {

    Elderly * elderly;
    Cell * next;
};


//====================================Private funcion=========================================//
/*
#Function to insert only one elderly in to the list#

-> It can not be accessed by main function, because elderlies can be added in to the
list by files only

*Main function doesn't has "elderly.h" 
*/
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

// #Function to create a void elderly list#
ElderlyList * CreateElderlyList(){

    ElderlyList * list = calloc(1,sizeof(ElderlyList));
    list->first = NULL;
    list->last = NULL;

    return list;
}

/* 
#Function to insert all elderlies read from 'apoio.txt' in to the list#

-> This function gets names from "apoio.txt" first line, uses these names to open
files that have elderlies names on name, get the data to create a new elderly and 
put in to the list.
*/
ElderlyList * InsertElderliesIntoList(ElderlyList * list, char ** argv){

    // variables declaration
    char * name, firstLine[100], elderlyFileWay[50];
    FILE * elderlyFile;


    // separating names from first line
    name = strtok(SupportFileFirstLine("./tests/Teste1/Entradas", firstLine),";"); 

    while(name != NULL){
        
        sprintf(elderlyFileWay, "./tests/Teste1/Entradas/%s.txt", name);
        elderlyFile = fopen(elderlyFileWay, "r");

        // Inserting elderlies into list one at time
        InsertOneElderly(list, RegisterElderly(name,
                               CreateSensorsDataArray(NumberOfReadings(argv), elderlyFile),
                               NumberOfReadings(argv)));
        
        fclose(elderlyFile);

        // ending strtok
        name = strtok(NULL, ";");   
    }

    return list;
}

/* 
#Function to print elderly list#

-> Only the names will be printed.
*/
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