#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/elderly.h"
#include "../include/elderlyList.h"
#include "../include/friendsList.h"
#include "../include/fileManager.h"

typedef struct friends_cell Friends_Cell;

struct friends_cell {

    Elderly * elderly;
    Friends_Cell *next;

};

// sentinel 
struct friends_list {

    Friends_Cell *first;
    Friends_Cell *last;

};


// Public functions ================================================================//
Friends_List * CreateFriendsElderlyList(){
    Friends_List * list = malloc(sizeof(Friends_List));
    list->first = NULL;
    list->last = NULL;
    
    return list;
}

// =================================================================================== //
Friends_List * InsertOneFriendIntoList(Elderly * elderly,Friends_List * friends){
    
    Friends_Cell *friend = malloc(sizeof(Friends_Cell));
    friend->elderly = elderly;
    

    if (friends->first == NULL){
        friends->first = friend;
        friends->last = friend;
        friend->next = NULL;

    }
    else {
        friends->last->next = friend;
        friends->last = friend;
        friend->next = NULL;
    }
    
    return friends;
}

// =================================================================================== //
void DestructElderlyFriendsList(Friends_List * friends){
    
    Friends_Cell *assistant1 = friends->first;
    Friends_Cell *assistant2;
    
    while(assistant1 != NULL){
        assistant2 = assistant1->next;
        free(assistant1);
        assistant1 = assistant2;
    }
    
    free(friends);
}

// =================================================================================== //
void DestructOneFriendFromList(Friends_List * friends, char *name){
    
    int i =0;

    if (friends->first != NULL) {
        Friends_Cell *current  = friends->first;
        Friends_Cell *previous = NULL;

        while (current != NULL){
            if (strcmp(ElderlyName(current->elderly),name) == 0){ 
                i = 1;
                break; 
            }
            previous = current;
            current = current->next;
        }
        if (i){
            if (friends->first == current){
                friends->first = current->next;
            }
            else if (friends->last == current){
                friends->last = previous;
                previous->next = NULL;
            }
            else {
                previous->next = current->next;
            }
            free(current);  
        }     
    }
}

void PrintTest(Friends_List * friends,char * name){
    Friends_Cell *friend = friends->first;
    
    printf("\n%s :",name);
    
    while(friend != NULL){
        printf("%s ",ElderlyName(friend->elderly));
        friend = friend->next;
    };

    printf("\n");           
}


Elderly * LessFriendDistance(Friends_List * list, long int * coordinates, int index){

    if(!list) return NULL;

    Elderly * lessDistanceFriend = NULL;
    Friends_Cell  * current = list->first;

    while(current){

        if(!lessDistanceFriend){

            if(!ReturnSensorDataByIndex(current->elderly, index)){}

            else if(!ReturnFall(ReturnSensorDataByIndex(current->elderly, index)) &&
            ReturnTemperature(ReturnSensorDataByIndex(current->elderly, index)) < 38 &&
            !IsFourthLowFever(ReturnAllData(current->elderly), index)){

                lessDistanceFriend = current->elderly;
            }
        }

        else{

            if(!ReturnSensorDataByIndex(current->elderly, index)){}

            else if((!ReturnFall(ReturnSensorDataByIndex(current->elderly, index)) &&
            ReturnTemperature(ReturnSensorDataByIndex(current->elderly, index)) < 38 &&
            !IsFourthLowFever(ReturnAllData(current->elderly), index))){


                if(Distance(coordinates, ReturnCoordinates(ReturnSensorDataByIndex(current->elderly, index)))
                < Distance(coordinates, ReturnCoordinates(ReturnSensorDataByIndex(lessDistanceFriend, index))))
                {
                    lessDistanceFriend = current->elderly;
                }        
            }
        }
        current = current->next;
    }
    return lessDistanceFriend;
}