#include <stdbool.h>

typedef struct 
{
    int id;
    int idOperation;
    int idComputer;
    int time;
} Operation;

// Add new operation
bool addOperation(Operation* operations, int* total, int size, int idOperation, int idComputer, int time);

// Edit the operation
bool editOperation(Operation* operations, int id, int size, int idOperation, int idComputer, int time);

// Delete the operation
bool deleteOperation(Operation* operations, int* total, int id, int size);