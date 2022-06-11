#include <stdio.h>
#include <stdlib.h>
#include "../include/validation.h"

int ValidateArg(int argc){

    if(argc <= 1){

        printf("Enter the number of readings you want to perform!\n\n");
        exit(1);

        return 0;
    } 
    return 1;
}

int NumberOfReadings(char ** argv){

    int num;
    sscanf(argv[1], "%d", &num);

    return num;
}