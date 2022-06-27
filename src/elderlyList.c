#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/validation.h"
#include "../include/fileManager.h"
#include "../include/elderlyList.h"
#include "../include/elderly.h"
#include "../include/friendsList.h"
#include "../include/caregiverList.h"


typedef struct cell Cell;
 
 //Sentinela
struct elderly_list {

    Cell * first;
    Cell * last;
    
};

//Estrutura da célula
struct cell {

    Elderly * elderly;
    Cell * next;
    Friends_List * friends;
    CareList * caregivers;
};

// Função privada (Não pode ser acessada pelo cliente)===============================================================================//
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


// Funções públicas =========================================================//
ElderlyList * CreateElderlyList(){

    ElderlyList * list = calloc(1,sizeof(ElderlyList));
    list->first = NULL;
    list->last = NULL;

    return list;
}


// ========================================================================================== //
ElderlyList * InsertElderliesFromFileIntoList(ElderlyList * list, char ** argv){

    // variables declaration
    char * name, elderlyFileWay[100];
    FILE * elderlyFile;


    // separating names from first line
    name = strtok(FileFirstLine("./apoio.txt"),";"); 

    while(name != NULL){
        
        sprintf(elderlyFileWay, "./%s.txt", name);
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
    char line[1000], * name;
    FILE * caregiversFile;
    Cell * aux;
    

    caregiversFile = fopen("./cuidadores.txt", "r");
    fscanf(caregiversFile, "%*[^\n]\n");    //  deleting first line


    while(!feof(caregiversFile)){   // loop to read lines

        fscanf(caregiversFile, "%[^\n]\n", line);   //  reagind one line at time

        flag =0;
        aux = elderliesList->first;

        name = strtok(line, ";");
        while(name != NULL){

            
            if(!flag){  // if !flag, it's in first name. First name is elderly name

                while(aux && strcmp(name, ElderlyName(aux->elderly))){      // finding elderly on elderliy list
                    aux = aux->next;    // finding right elderly at cells
                }
                flag = 1;
            }  

            else{   // next names are caregivers names, then, program will insert them into elderly caregivers list
                
                // inserting caregiver from main caregivers list on elderly caregivers list
                // This insertion is done by name 
                InsertOneCareGiver(aux->caregivers, ReturnCaregiverByName(caregiversList, name));

            }
            name = strtok(NULL, ";");
        }
    }

    fclose(caregiversFile);

    return elderliesList;
}


// ========================================================================================== //
void ProcessListData(ElderlyList * list){

    Cell * current = list->first;
    FILE * file;
    char fileWay[100];
    int lowFeverCounter=0;

    while(current){

        lowFeverCounter =0;        

        sprintf(fileWay, "./%s-saida.txt", ElderlyName(current->elderly));
        file = fopen(fileWay, "w");

        for(int x =0; x< ReturnDataAmount(current->elderly); x++){

            if(!ReturnSensorDataByIndex(current->elderly,x)) {  //faleceu
                
                fprintf(file, "falecimento\n");    
                break;
            }

            else if(!AnalysisSensorsData(ReturnSensorDataByIndex(current->elderly, x))){

                fprintf(file, "tudo ok\n"); //everything's ok
            } 

            else if(AnalysisSensorsData(ReturnSensorDataByIndex(current->elderly, x)) == 1){    //fall

                fprintf(file, "queda, acionou %s\n", CaregiverName(LessCaregiverDistance(
                                                  ReturnCoordinates(ReturnSensorDataByIndex(
                                                    current->elderly, x)), current->caregivers, x)));
            }

            else if(AnalysisSensorsData(ReturnSensorDataByIndex(current->elderly, x)) == 2){    //High fever

                fprintf(file, "febre alta, acionou %s\n", CaregiverName(LessCaregiverDistance(
                                                  ReturnCoordinates(ReturnSensorDataByIndex(
                                                      current->elderly,x)), current->caregivers, x)));
                lowFeverCounter = 0;
            }

            else if(AnalysisSensorsData(ReturnSensorDataByIndex(current->elderly, x)) == 3){    //Low fever
                
                if(lowFeverCounter == 3){
                    fprintf(file, "febre baixa pela quarta vez, acionou %s\n", CaregiverName(LessCaregiverDistance(
                                                          ReturnCoordinates(ReturnSensorDataByIndex(
                                                            current->elderly, x)), current->caregivers, x)));
                    lowFeverCounter = 0;
                }
                
                else{

                    if(!LessFriendDistance(current->friends, ReturnCoordinates(ReturnSensorDataByIndex(
                                                                                current->elderly, x)), x)){

                        fprintf(file, "Febre baixa mas, infelizmente, o idoso está sem amigos na rede\n");
                    }

                    else{

                        fprintf(file, "febre baixa, acionou amigo %s\n", ElderlyName(LessFriendDistance(current->friends,
                                                                                 ReturnCoordinates(ReturnSensorDataByIndex(
                                                                                     current->elderly, x)), x)));

                    }
                    lowFeverCounter++;
                }
            }
        }
        fclose(file);
        current = current->next;
    }
}


// ========================================================================================== //
Cell * ReturnElderlyCell(Cell *friend, char string[50], Elderly * elder){
    
    while(friend != NULL && strcmp(string,ElderlyName(friend->elderly)) != 0){
        friend = friend->next; 
    };
    
    return friend;
}


// ========================================================================================== //
ElderlyList * AssigningElderliesFriends(ElderlyList * list){
    
    FILE * supportFile;
    char lineFile[100],firstLine[100],*assistant,string1[100],string2[100];
    Cell * friends1 = list->first,* friends2 = list->first;
    int i = 0;
    

    supportFile = fopen("./apoio.txt", "r");
    fscanf(supportFile, "%[^\n]\n", firstLine);
    
    while(fscanf(supportFile,"%[^\n]\n",lineFile) != EOF){

        assistant = strtok(lineFile,";");
        while(assistant != NULL){
            
            if (i == 0){strcpy(string1,assistant); i = 1;}
            else {strcpy(string2,assistant); i = 0;}
            assistant = strtok(NULL,";");
        };
        
        friends1 = ReturnElderlyCell(friends1, string1,friends1->elderly);
        friends2 = ReturnElderlyCell(friends2, string2,friends2->elderly);
        
        friends2->friends = InsertOneFriendIntoList(friends1->elderly,friends2->friends);
        friends1->friends = InsertOneFriendIntoList(friends2->elderly,friends1->friends);
        
        friends1 = list->first; 
        friends2 = list->first;
    };

    fclose(supportFile);
    
    return list;
}


// ========================================================================================== //
void PrintAllFriendsLists(ElderlyList * list){

    Cell * current = list->first;;

    printf("\n================Idosos e suas listas de amigos==============\n");
    
    while(current){

        PrintFriendsList(current->friends, ElderlyName(current->elderly));

        current = current->next;
    }
}


// ========================================================================================== //
void DeleteElderlyList(ElderlyList * list){

    Cell * current, * next;
    current = list->first;

    if(list){

        while(current){

            if(current->caregivers) DestructElderliesCaregiversList(current->caregivers);

            if(current->friends) DestructElderlyFriendsList(current->friends);

            if(current->elderly) KillElderly(current->elderly);

            next = current->next;
            free(current);
            current = next;           
        }
        free(list);
    }
}