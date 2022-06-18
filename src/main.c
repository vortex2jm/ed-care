#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/validation.h"
#include "../include/elderlyList.h"
#include "../include/caregiverList.h"

//======================================Main=========================================//

int main(int argc, char ** argv){

    // Verifying if have args
    ValidateArg(argc);

    ElderlyList * elderlyList = CreateElderlyList();
    CareList * caregiverList = CreateCareList();

    InsertElderliesFromFileIntoList(elderlyList, argv); //inserindo idosos do arquivo na lista
    InsertCaregiversFromFileIntoList(caregiverList, argv);  //Inserindo cuidadores do arquivo na lista

    AssigningCaregiversToElderlyList(caregiverList, elderlyList);   //Atribuindo cuidadores aos idosos da lista    
    AssigningElderliesFriends(elderlyList); //Atribuindo os amigos dos idosos da lista


    printf("=============== Idosos e suas listas de cuidadores ==============\n\n");
    PrintElderlyList(elderlyList);


    printf("=============== Lista com todos os cuidadores =================\n\n");
    PrintCaregiversList(caregiverList);


    ProcessListData(elderlyList);   //processando os dados de todos os idosos da lista
    PrintAllFriendsLists(elderlyList);

    return 0;
}
