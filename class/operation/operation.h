#include <stdbool.h>

#define TAM 30

typedef struct 
{
    int id;
    int idComputer;
    int time;
} Operation;

// Add new operation
bool addOperation(Operation* operations, int* total, int size, int id, int idComputer, int time);

// Edit the operation
bool editOperation(Operation* operations, int index, int size, int id, int idComputer, int time);

// Delete the operation
bool deleteOperation(Operation* operations, int* total, int index, int size);