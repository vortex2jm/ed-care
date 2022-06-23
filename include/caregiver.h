#ifndef caregiver_h
#define caregiver_h

// Definindo o tipo Caregiver(cuidador)
typedef struct caregiver Caregiver;

/*Função para alocar espaço para um novo cuidador
RECEBE:
    -> name = nome
    -> coordinates = uma matriz de coordenadas(cada linha da matriz é uma coordenada em latitude e longitude)
    -> size = quantidade de linhas da matriz de coordenadas
RETORNA:
    -> Ponteiro para o tipo Caregiver(cuidador)
*/
Caregiver * RegisterCaregiver(char * name, long int ** coordinates, int size);


/*Função para ler e alocar espaço para os dados do cuidador(coordenadas)
RECEBE:
    -> file = arquivo "CuidadorX.txt"(o arquivo deve estar aberto)
    -> size = quantidade de dados sensoriados que estará no argv
RETORNA:
    -> long int** = matriz de coordenadas 
*/
long int ** CareGiverDataReading(FILE * file, int size);


/*Função para imprimir os dados do cuidador no terminal
RECECBE:
    -> caregiver = ponteiro para cuidador
RETORNA:
    -> void
*/
void PrintCareGiver(Caregiver * caregiver);


/*Função para retornar o nome doo cuidador
RECEBE:
    -> caregiver = ponteiro para cuidador
RETORNA:
    -> char * = string com o nome do cuidador
*/
char * CaregiverName(Caregiver * caregiver);


/*Função para liberar o espaço de memória alocado para um cuidador
RECEBE:
    -> caregiver = ponteiro para cuidador
RETORNA:
    -> void
*/
void EliminateCaregiver(Caregiver * caregiver);


/*Função para retornar apenas uma coordenada do cuidador(latitude e longitude)
RECEBE:
    -> caregiver = ponteiro para cuidador
    -> index = índice que corresponde a uma determinada leitura do sensor. Esse índice representa
    uma linha da matriz de coordenadas.
RETORNA:
    -> long int* = um vetor de 2 long int com latitude e longitude do cuidador
*/
long int * ReturnCaregiverLocation(Caregiver * caregiver, int index);

#endif