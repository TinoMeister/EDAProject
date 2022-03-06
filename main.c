#include <stdio.h>
#include <stdlib.h>

//#include "class/operation/operation.h"
#include "utils/file/file.h"


int main(int argc, char const *argv[]) 
{
    int size = 20;
    Operation* operations = malloc(sizeof(Operation)*size);
    int total = 0;

    // Load Operations from DB
    loadOpData(operations, &total);

    // Add Operations
    addOperation(operations, &total, size, 1, 1, 4);
    addOperation(operations, &total, size, 1, 3, 5);
    addOperation(operations, &total, size, 2, 2, 4);
    addOperation(operations, &total, size, 2, 4, 5);
    addOperation(operations, &total, size, 3, 3, 5);
    addOperation(operations, &total, size, 3, 5, 6);
    addOperation(operations, &total, size, 4, 4, 5);
    addOperation(operations, &total, size, 4, 5, 5);
    addOperation(operations, &total, size, 4, 6, 4);
    addOperation(operations, &total, size, 4, 7, 5);
    addOperation(operations, &total, size, 4, 8, 9);

    // Show operations
    printf("After Adding:\n");
    for (int i = 0; i < total; i++)
    {
        Operation op = operations[i];
        printf("%d - %d - %d - %d\n", op.id, op.idOperation, op.idComputer, op.time);
    }
    
    // Edit Operations
    editOperation(operations, 1, size, 1, 1, 2);
    editOperation(operations, 88, size, 2, 1, 2);
    editOperation(operations, 3, size, 3, 1, 2);

    // Show operations
    printf("After Editing:\n");
    for (int i = 0; i < total; i++)
    {
        Operation op = operations[i];
        printf("%d - %d - %d - %d\n", op.id, op.idOperation, op.idComputer, op.time);
    }

    // Delete Operations
    deleteOperation(operations, &total, 1, size);
    deleteOperation(operations, &total, 20, size);
    deleteOperation(operations, &total, 3, size);


    // Show operations
    printf("After Removing:\n");
    for (int i = 0; i < total; i++)
    {
        Operation op = operations[i];
        printf("%d - %d - %d - %d\n", op.id, op.idOperation, op.idComputer, op.time);
    }


    // Save Operations to DB
    saveOpData(operations, total);


    return 0;
}
