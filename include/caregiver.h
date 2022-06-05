#ifndef caregiver_h
#define caregiver_h

typedef struct caregiver Caregiver;

Caregiver * RegisterCaregiver(char * name, long int latitude, long int longitude);

void EliminateCaregiver(Caregiver * caregiver);

#endif