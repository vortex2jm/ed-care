#ifndef friend_elder_h
#define friend_elder_h 


typedef struct friends_list Friends_List;

Friends_List * CreateFriendsElderlyList();

Friends_List * InsertFriendsElderliesIntoList(Elderly * list,Friends_List * friends);

void PrintTest(Friends_List * friends,char * name);

#endif 