#ifndef sensors_data_h
#define sensors_data_h

// Definindo o tipo SensorsData(dados dos sensores)
typedef struct sensors SensorsData;

// =================================================================================== //
/*Função para alocar espaço de memória para um vetor de dados dos sensores
RECEBE:
    -> size = tamanho do vetor
    -> file = arquivo que terá os dados lidos para jogar para o vetor
RETORNA:
    -> SensorsData** = ponteiro para um vetor de ponteiros para dados dos sensores
*/
SensorsData ** CreateSensorsDataArray(int size, FILE * file);


// =================================================================================== //
/*Função para printar apenas um conjunto de dados dos sensores (temperatura, localização e queda)
RECEBE:
    -> data - ponteiro para dados do sensor
RETORNA:
    -> void
*/
void PrintData(SensorsData * data);


// =================================================================================== //
/*Função para retornar a temperatura que está dentro do tipo dados do sensor
RECEBE:
    -> data = ponteiro para dados do sensor
RETORNA:
    -> float = temperatura em ponto flutuante
*/
float ReturnTemperature(SensorsData * data);


// =================================================================================== //
/*Função para retornar as coordenadas que estão dentro do tipo dados do sensores
RECEBE:
    -> data = ponteiro para dados do sensor
RETORNA:
    -> long int* = um vetor de dois elementos com latitude e longitude
*/
long int * ReturnCoordinates(SensorsData * data);


// =================================================================================== //
/*Função para retornar a queda(1 - caiu, 0 - não caiu)
RECEBE:
    -> data = ponteiro para dados do sensor
RETORNA:
    -> int = um inteiro indicando se caiu ou não
*/
int ReturnFall(SensorsData * data);


// =================================================================================== //
/*Função para analisar os dados dos sensores e retornar um inteiro(1 - queda, 2 - febre alta, 3 febre baixa)
/*Queda tem prioridade sobre febre alta e febre alta tem prioridade sobre febre baixa
RECEBE:
    -> data = ponteiro para dados do sensor
RETORNA:
    -> int = inteiro indicando a situação dos dados
*/
int AnalysisSensorsData(SensorsData * data);


// =================================================================================== //
/*Função para liberar o espaço de memória alocado para apenas um conjunto de dados dos sensores
RECEBE:
    -> data = ponteiro para dados dos sensores
RETORNA:
    -> void 
*/
void DeleteSensorsData(SensorsData * data);


// =================================================================================== //
/*Função para verificar se um vetor de dados, até determinado elemento, teve 4 febres baixas
/*sem uma febre alta no meio
RECEBE:
    -> data = ponteiro para um vetor de ponteiros para dados dos sensores
    -> currentIndex = índice limite a ser analisado
RETORNA:
    -> int = inteiro que retorna se houve ou não houve 4 febres baixas
*/
int IsFourthLowFever(SensorsData ** data, int currentIndex);


// =================================================================================== //
/*Função para liberar o espaço de memória alocado para um vetor de dados de sensores
RECEBE:
    -> array = ponteiro para um vetor de ponteiros que apontam para dados de sensores
    -> size = tamanho do vetor
RETORNA:
    -> void
*/
void DeleteSensorsDataArray(SensorsData ** array, int size);

#endif