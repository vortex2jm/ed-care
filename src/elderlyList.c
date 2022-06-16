// Elderly list functions implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/validation.h"
#include "../include/elderlyList.h"
#include "../include/elderly.h"
#include "../include/fileManager.h"
#include "../include/sensorsData.h"
#include "../include/friendsList.h"
#include "../include/caregiverList.h"

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
    Friends_List * friends;
    CareList * caregivers;
};

// Private funcion===============================================================================//
/*
#Function to insert only one elderly in to the list#

-> It can not be accessed by main function, because elderlies can be added in to the
list by files only

*Main function doesn't has "elderly.h" 
*/
void InsertOneElderly(ElderlyList * list, Elderly * elderly, Friends_List * friends_list, CareList * caregivers){
     
    Cell * newCell = malloc(sizeof(Cell));
    
    newCell->elderly = elderly;
    newCell->friends = friends_list;
    newCell->caregivers = caregivers;

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

// Public functions =========================================================//


ElderlyList * CreateElderlyList(){

    ElderlyList * list = calloc(1,sizeof(ElderlyList));
    list->first = NULL;
    list->last = NULL;

    return list;
}

// ========================================================================================== //
ElderlyList * InsertElderliesFromFileIntoList(ElderlyList * list, char ** argv){

    // variables declaration
    char * name, elderlyFileWay[50];
    FILE * elderlyFile;


    // separating names from first line
    name = strtok(FileFirstLine("./tests/Teste1/Entradas/apoio.txt"),";"); 

    while(name != NULL){
        
        sprintf(elderlyFileWay, "./tests/Teste1/Entradas/%s.txt", name);
        elderlyFile = fopen(elderlyFileWay, "r");
        
        
        // Inserting elderlies into list one at time
        InsertOneElderly(list, RegisterElderly(name,
                               CreateSensorsDataArray(NumberOfReadings(argv), elderlyFile),
                               NumberOfReadings(argv)),
                               CreateFriendsElderlyList(),
                               CreateCareList());
        
        fclose(elderlyFile);

        // ending strtok
        name = strtok(NULL, ";");   
    }
    return list;
}

// ========================================================================================== //
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
        PrintCaregiversList(current->caregivers);
        printf("\n");
        current = aux;
    }
}


// ========================================================================================== //
ElderlyList * AssigningCaregiversToElderlyList(CareList * caregiversList, ElderlyList * elderliesList){

    //variable declaration
    int flag=0;
    char line[100], * name;
    FILE * caregiversFile;
    Cell * aux;
    

    caregiversFile = fopen("./tests/Teste1/Entradas/cuidadores.txt", "r");
    fscanf(caregiversFile, "%*[^\n]\n");    //  deleting first line


    while(!feof(caregiversFile)){   // loop to read lines

        fscanf(caregiversFile, "%[^\n]\n", line);   //  reagind one line at time

        flag =0;
        aux = elderliesList->first;

        name = strtok(line, ";");
        while(name != NULL){

            
            if(!flag){  // if !flag, it's in first name. First name's elderly name

                while(aux && strcmp(name, ElderlyName(aux->elderly))){      // finding elderly on elderliy list
                    aux = aux->next;    // finding right elderly at cells
                }
                flag = 1;
            }  

            else{   // next names are caregivers names, then, program will insert them in to elderly caregivers list
                
                // inserting caregiver from main caregivers list on elderly caregivers list
                // This insertion is done by name 
                InsertOneCareGiver(aux->caregivers, ReturnCaregiverByName(caregiversList, name));

            }
            name = strtok(NULL, ";");
        }
    }

    return elderliesList;
}