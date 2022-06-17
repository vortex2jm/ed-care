#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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

double Distance(long int * coordinates1, long int * coordinates2){

    // printf("%ld / %ld   &&   %ld / %ld\n", coordinates1[0], coordinates1[1], coordinates2[0], coordinates2[1]);

    double distance, cat1, cat2, cat1square, cat2square; 
    
    cat1 = (double)coordinates1[0] - (double)coordinates2[0];
    cat2 = (double)coordinates1[1] - (double)coordinates2[1];

    cat1square = cat1 * cat1;
    cat2square = cat2 * cat2;

    distance = sqrt(cat1square + cat2square);

    return distance;
}








