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
    
    return friends;
}

void Destruct_List_friend(Friends_List * friends, char *name){
    
    int i =0;

    if (friends->first != NULL) {
        Friends_Cell *next  = friends->first;
        Friends_Cell *before = NULL;

        while (next != NULL){
            if (strcmp(Return_name(next->elderly),name) == 0){ 
                i = 1;
                break; 
            }
            before = next;
            next = next->next;
        }
        if (i == 1){
            if (friends->first == next){
                friends->first = next->next;
            }
            else if (friends->last == next){
                friends->last = before;
                before->next = NULL;
            }
            else {
                before->next = next->next;
            }

            free(next);  
        }   
       
    }

}

void Destroy_Elder(Friends_List * friends){
    Friends_Cell *assistant1 = friends->first;
    Friends_Cell *assistant2;
    
    while(assistant1 != NULL){
        assistant2 = assistant1->next;
        free(assistant1);
        assistant1 = assistant2;
    }
    
    free(friends);
 

}


void PrintTest(Friends_List * friends,char * name){
    Friends_Cell *friend = friends->first;
    
    printf("\n%s :",name);
    
    while(friend != NULL){
        printf("%s ",Return_name(friend->elderly));
        friend = friend->next;
    };    
        
}
