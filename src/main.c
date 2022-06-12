#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/validation.h"
#include "../include/elderlyList.h"
#include "../include/caregiverList.h"


///======================================Main=========================================//

int main(int argc, char ** argv){

    // Verifying if have args
    ValidateArg(argc);

    ElderlyList * elderlyList = CreateElderlyList();
    CareList * caregiverList = CreateCareList();

    InsertElderliesFromFileIntoList(elderlyList, argv);
    InsertCaregiversFromFileIntoList(caregiverList, argv);


    PrintElderlyList(elderlyList);
    PrintCaregiversList(caregiverList);

    // Friends_Elders(elderlyList);
    
    return 0;
}