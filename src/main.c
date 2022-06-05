#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/validation.h"
#include "../include/elderly.h"
#include "../include/sensorsData.h"
#include "../include/elderlyList.h"

//==============================Functions Prototypes=================================//

void InsertElderlyInList(ElderlyList * list, char ** argv);

///======================================Main=========================================//

int main(int argc, char ** argv){

    // Verifying if have args
    ValidateArg(argc);

    ElderlyList * elderlyList = CreateElderlyList();

    InsertElderlyInList(elderlyList, argv);

    // Variables declaration
    
    return 0;
}

//=====================================Functions======================================//

void InsertElderlyInList(ElderlyList * list, char ** argv){

    // variables declaration
    int fall, fscanfRtn;
    char firstLine[200], directoryName[50], * name;
    float temperature;
    long int latitude, longitude;

    Elderly * elderly;
    FILE * supportFile, * elderlyFile;
    SensorsData ** data = calloc(NumberOfReadings(argv), sizeof(SensorsData*));


    //opening support file
    supportFile = fopen("./tests/Teste2/Entradas/apoio.txt", "r");
    fscanf(supportFile, "%[^\n]\n", firstLine);

    
    name = strtok(firstLine,";");   // separating names from first line

    while(name != NULL){
        
        // scanning elderly files
        sprintf(directoryName,"./tests/Teste1/Entradas/%s.txt", name);
        elderlyFile = fopen(directoryName,"r");
        

        // Reading sensors data 
        for(int x=0; x<NumberOfReadings(argv);x++){     // NumberOfReadings returns the number inserted on command line

            fscanfRtn = fscanf(elderlyFile, "%f;%ld;%ld;%d", &temperature, &latitude, &longitude, &fall);

            if(fscanfRtn != 4) break;   // If return != 4, elderly died

            data[x] = RegisterSensorsData(temperature, latitude, longitude, fall);  // Filling sensors data array
        } 

        elderly = RegisterElderly(name, data, NumberOfReadings(argv));  // Instantiating new elderly
    
        // ending strtok
        name = strtok(NULL, ";");   
    }

    fclose(supportFile);
}