#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/validation.h"
#include "../include/elderlyList.h"


///======================================Main=========================================//

int main(int argc, char ** argv){

    // Verifying if have args
    ValidateArg(argc);

    ElderlyList * elderlyList = CreateElderlyList();

    InsertElderliesIntoList(elderlyList, argv);

    
    PrintElderlyList(elderlyList);
    
    Friends_Elders(elderlyList);
    
    Imprimi (elderlyList);

    printf("\n---------- Apagando amigos ---------\n");
    Destroy_list_of_dead_elderly(elderlyList,"Milla");

    Imprimi (elderlyList);

    
    
    return 0;
}