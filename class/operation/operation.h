#include <stdbool.h>

typedef struct 
{
    int id;
    int idComputer;
    int time;
} Operation;

// Add new operation
bool addOperation(Operation* operations, int* total, int size, int idComputer, int time);