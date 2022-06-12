#include <stdio.h>
#include <stdlib.h>

char * SupportFileFirstLine(char * way, char * firstLine){

    FILE * supportFile;
    char directory[30];
    // static char fisrtLine[100];

    sprintf(directory, "%s/apoio.txt", way);
    supportFile = fopen(directory, "r");

    fscanf(supportFile, "%[^\n]\n", firstLine);

    fclose(supportFile);

    return firstLine;
}



void OpenElderlyFile(char * name, char * way, FILE * file){

    char directory[50];
    sprintf(directory, "%s/%s.txt", way, name);

    file = fopen(directory,"r");
}