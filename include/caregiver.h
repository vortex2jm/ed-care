#ifndef caregiver_h
#define caregiver_h

typedef struct caregiver Caregiver;

Caregiver * RegisterCaregiver(char * name, long int ** coordinates, int size);

long int ** CareGiverDataReading(FILE * file, int size);

void PrintCareGiver(Caregiver * caregiver);

char * CaregiverName(Caregiver * caregiver);

void EliminateCaregiver(Caregiver * caregiver);

long int * ReturnCaregiverLocation(Caregiver * caregiver, int index);

#endif