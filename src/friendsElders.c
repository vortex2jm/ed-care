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