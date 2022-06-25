#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/validation.h"
#include "../include/elderlyList.h"
#include "../include/caregiverList.h"

//======================================Main=========================================//

int main(int argc, char ** argv){

    // Verificando se o programa foi executado com algum argumento
    ValidateArg(argc);

    // Criando uma lista de cuidadores e uma lista de idosos vazias
    ElderlyList * elderlyList = CreateElderlyList();
    CareList * caregiverList = CreateCareList();


    InsertElderliesFromFileIntoList(elderlyList, argv); //inserindo idosos do arquivo na lista
    InsertCaregiversFromFileIntoList(caregiverList, argv);  //Inserindo cuidadores do arquivo na lista

    
    AssigningCaregiversToElderlyList(caregiverList, elderlyList);   //Atribuindo cuidadores aos idosos da lista    
    AssigningElderliesFriends(elderlyList); //Atribuindo os amigos dos idosos da lista


    //Imprimindo alguns dados no terminal
    printf("=============== Lista com todos os cuidadores =================\n\n");
    PrintCaregiversList(caregiverList);
    printf("=============== Idosos e suas listas de cuidadores ==============\n\n");
    PrintElderlyList(elderlyList);
    PrintAllFriendsLists(elderlyList);


    ProcessListData(elderlyList);   //processando os dados de todos os idosos da lista e gerando as saídas

    DeleteElderlyList(elderlyList); //Liberando a memória alocada para a lista de idosos
    DestructCaregiversList(caregiverList);  //Liberando a memória alocada para a lista de cuidadores

    return 0;
}