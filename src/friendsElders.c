#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/elderly.h"
#include "../include/elderlyList.h"
#include "../include/friendsElders.h"

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

Friends_List * CreateFriendsElderlyList(){
    Friends_List * list = malloc(sizeof(Friends_List));
    list->first = NULL;
    list->last = NULL;
    
    return list;
}



Friends_List * InsertFriendsElderliesIntoList(Elderly * list,Friends_List * friends){
    
    Friends_Cell *friend = malloc(sizeof(Friends_Cell));
    friend->elderly = list;
    

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
    printf("--%s\n",Return_name(friend->elderly));
    return friends;
}


void PrintTest(Friends_List * friends,char * name){
    Friends_Cell *friend = friends->first;
    
    printf("\n%s :",name);
    while(friend != NULL){
        printf("%s ",Return_name(friend->elderly));
        friend = friend->next;
    };
}
