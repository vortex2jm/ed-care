// Elderly list functions implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/validation.h"
#include "../include/elderlyList.h"
#include "../include/elderly.h"
#include "../include/fileManager.h"
#include "../include/sensorsData.h"
#include "../include/friendsElders.h"

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
    

};

Cell * Return_position_Elder(Cell *friend,char string[50],Elderly * elder);
//====================================Private funcion=========================================//
/*
#Function to insert only one elderly in to the list#

-> It can not be accessed by main function, because elderlies can be added in to the
list by files only

*Main function doesn't has "elderly.h" 
*/
void InsertOneElderly(ElderlyList * list, Elderly * elderly,Friends_List * friends_list){
     
    Cell * newCell = malloc(sizeof(Cell));
    
    newCell->elderly = elderly;
    newCell->friends = friends_list;
    
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
    name = strtok(SupportFileFirstLine("./tests/Teste2/Entradas", firstLine),";"); 

    while(name != NULL){
        
        sprintf(elderlyFileWay, "./tests/Teste2/Entradas/%s.txt", name);
        elderlyFile = fopen(elderlyFileWay, "r");
        
        
        // Inserting elderlies into list one at time
        InsertOneElderly(list, RegisterElderly(name,
                               CreateSensorsDataArray(NumberOfReadings(argv), elderlyFile),
                               NumberOfReadings(argv)),
                               CreateFriendsElderlyList());
        
        fclose(elderlyFile);

        // ending strtok
        name = strtok(NULL, ";");   
    }


    return list;
}

ElderlyList * Friends_Elders(ElderlyList * list){
    FILE * supportFile;
    char lineFile[100],firstLine[100],*assistant,string1[50],string2[50];
    Cell * friends1 = list->first,* friends2 = list->first;
    int i = 0;
    
    
    supportFile = fopen("./tests/Teste2/Entradas/apoio.txt", "r");
    fscanf(supportFile, "%[^\n]\n", firstLine);
    
    while(fscanf(supportFile,"%[^\n]\n",lineFile) != EOF){
        assistant = strtok(lineFile,";");
        while(assistant != NULL){
            if (i == 0){strcpy(string1,assistant); i = 1;}
            else {strcpy(string2,assistant); i = 0;}
            assistant = strtok(NULL,";");
        };
        
        friends1 = Return_position_Elder(friends1, string1,friends1->elderly);
        friends2 = Return_position_Elder(friends2, string2,friends2->elderly);
        
        friends2->friends = InsertFriendsElderliesIntoList(friends1->elderly,friends2->friends);
        friends1->friends = InsertFriendsElderliesIntoList(friends2->elderly,friends1->friends);
        
        friends1 = list->first; 
        friends2 = list->first;
    };
    
    
    
    return list;
}

Cell * Return_position_Elder(Cell *friend,char string[50],Elderly * elder){
    while(friend != NULL && strcmp(string,Return_name(friend->elderly)) != 0){
            friend = friend->next; 
    };
    return friend;
}

 
void Imprimi (ElderlyList * list){
    Cell * assistant = list->first;

    while(assistant != NULL){
        PrintTest(assistant->friends,Return_name(assistant->elderly));
        assistant = assistant->next;
    };
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