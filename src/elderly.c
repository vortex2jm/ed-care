#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/elderly.h"
#include "../include/friendsList.h"
#include "../include/caregiverList.h"

struct elderly {

    char * name;
    SensorsData ** data;
    int dataAmount;

};

// Public functions======================================================================== //
Elderly * RegisterElderly(char * name, SensorsData ** data, int dataAmount){

    Elderly * newElderly = (Elderly*) malloc(sizeof(Elderly));

    newElderly->name = strdup(name);
    newElderly->data = data;
    newElderly->dataAmount = dataAmount;

    return newElderly;
}

// ======================================================================================== //
void PrintElderly(Elderly * elderly){

    if(elderly == NULL) printf("Elderly do not exists!\n\n");

    else if(elderly->name == NULL) printf("Elderly without name!\n\n");
    
    else printf("nome do idoso: %s\n", elderly->name);
}

// ======================================================================================== //
char * ElderlyName(Elderly * elderly){

    return elderly->name;
}

// ======================================================================================== //
void ProcessElderlyData(Elderly * elderly, Friends_List * friendsList, CareList * careList){

    FILE * file;
    char fileWay[50];
    int lowFeverCounter=0;

    // Creating out file
    sprintf(fileWay, "./%s-saida.txt", elderly->name);
    file = fopen(fileWay, "w");


    for(int x=0; x<elderly->dataAmount; x++){

        if(!elderly->data[x]){

            fprintf(file, "falecimento\n");
            break;
        } 

        if(!AnalysisSensorsData(elderly->data[x])){ //sem febre e sem queda

            fprintf(file, "tudo ok\n");
        }

        else if(AnalysisSensorsData(elderly->data[x]) == 1){    //queda

            fprintf(file, "queda, acionou %s\n", CaregiverName(LessCaregiverDistance(
                                                      ReturnCoordinates(elderly->data[x]), careList, x)));
        }

        else if(AnalysisSensorsData(elderly->data[x]) == 2){    //febre alta

            fprintf(file, "febre alta, acionou %s\n", CaregiverName(LessCaregiverDistance(
                                                      ReturnCoordinates(elderly->data[x]), careList, x)));

            lowFeverCounter = 0;
        }        

        else if(AnalysisSensorsData(elderly->data[x]) == 3){    //febre baixa

            if(lowFeverCounter == 3){

                fprintf(file, "febre baixa pela quarta vez, acionou %s\n", CaregiverName(LessCaregiverDistance(
                                                      ReturnCoordinates(elderly->data[x]), careList, x)));

                lowFeverCounter = 0;
            }

            else{
                
                fprintf(file, "febre baixa, acionou fulano de tal\n");
                // febre baixa, criar função para ver qual amigo está mais perto
                lowFeverCounter++;
            }

        }

    }

    fclose(file);
}