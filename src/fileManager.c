#include <stdio.h>
#include <stdlib.h>


// Public functions ===============================================//
char * FileFirstLine(char * way){

    FILE * file;
    char directory[30];
    static char firstLine[100];

    sprintf(directory, "%s", way);
    file = fopen(directory, "r");

    fscanf(file, "%[^\n]\n", firstLine);

    fclose(file);

    return firstLine;
}