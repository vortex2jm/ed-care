#include <stdio.h>
#include <stdlib.h>
#include "../include/elderlyList.h"
#include "../include/elderly.h"

typedef struct cell Cell;

struct elderly_list {

    Cell * first;
    Cell * last;
};

struct cell {

    Elderly * elderly;
    Cell * next;
    Cell * previous;
};


ElderlyList * CreateElderlyList(){

    ElderlyList * list = calloc(1,sizeof(ElderlyList));
    
    return list;
}

void InsertOnElderlyList(ElderlyList * list, Elderly * elderly){

        
}














