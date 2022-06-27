#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/fileManager.h"

//Arquivo com funções auxiliares (Funções utilizadas em mais de um TAD)

// funções públicas ===============================================//
char * FileFirstLine(char * way){

    FILE * file;
    char directory[100];
    static char firstLine[1000];

    sprintf(directory, "%s", way);
    file = fopen(directory, "r");

    fscanf(file, "%[^\n]\n", firstLine);

    fclose(file);

    return firstLine;
}


//====================================================================//
double Distance(long int * coordinates1, long int * coordinates2){

    double distance, cat1, cat2, cat1square, cat2square; 
    
    cat1 = (double)coordinates1[0] - (double)coordinates2[0];
    cat2 = (double)coordinates1[1] - (double)coordinates2[1];

    cat1square = cat1 * cat1;
    cat2square = cat2 * cat2;

    distance = sqrt(cat1square + cat2square);

    return distance;
}