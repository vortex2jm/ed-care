#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/elderly.h"

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
void ProcessElderlyData(Elderly * elderly){

    FILE * file;
    char fileWay[50];
    int lowFeverCounter=0;

    // Creating out file
    sprintf(fileWay, "./%s-saida.txt", elderly->name);
    file = fopen(fileWay, "w");


    for(int x=0; x<elderly->dataAmount; x++){

        if(!AnalysisSensorsData(elderly->data[x])){

            fprintf(file, "tudo ok\n");
        }

        else if(AnalysisSensorsData(elderly->data[x]) == 1){

            // idoso caiu, criar função para ver qual cuidador está mais perto
        }

        else if(AnalysisSensorsData(elderly->data[x]) == 2){

            // febre alta, criar função para ver qual cuidador está mais perto
            lowFeverCounter = 0;
        }        

        else if(AnalysisSensorsData(elderly->data[x]) == 3){

            if(lowFeverCounter == 3){

                //febre baixa pela quarta vez, acionar cuidador
                lowFeverCounter = 0;
            }

            else{

                // febre baixa, criar função para ver qual amigo está mais perto
                lowFeverCounter++;
            }

        }

    }

    fclose(file);
}

// possivelmente teremos que adicionar o campo "disponibilidade" nas estruturas dos idosos e cuidadores