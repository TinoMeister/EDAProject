#include <stdio.h>
#include <stdlib.h>

#include "class/operation/operation.h"


int main(int argc, char const *argv[]) 
{
    int size = 10;
    Operation* operations = malloc(sizeof(Operation)*size);
    int total = 0;

    // Add operations
    addOperation(operations, &total, size, 3, 10);
    addOperation(operations, &total, size, 12, 2);
    addOperation(operations, &total, size, 14, 3);
    addOperation(operations, &total, size, 6, 7);
    addOperation(operations, &total, size, 8, 15);
    addOperation(operations, &total, size, 4, 9);


    // Show operations
    for (int i = 0; i < total; i++)
    {
        Operation op = operations[i];
        printf("%d - %d - %d\n", op.id, op.idComputer, op.time);
    }


    return 0;
}
