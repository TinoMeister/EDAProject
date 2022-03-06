#include <stdio.h>
#include <stdlib.h>

//#include "class/operation/operation.h"
#include "utils/file/file.h"


int main(int argc, char const *argv[]) 
{
    int size = 30;
    Operation* operations = malloc(sizeof(Operation)*size);
    int total = 0;

    // Load Operations from DB
    loadOpData(operations, &total);

    // Add operations
    addOperation(operations, &total, size, 3, 10);
    addOperation(operations, &total, size, 12, 2);
    addOperation(operations, &total, size, 14, 3);
    addOperation(operations, &total, size, 6, 7);
    addOperation(operations, &total, size, 8, 15);
    addOperation(operations, &total, size, 4, 9);


    // Show operations
    printf("After Adding:\n");
    for (int i = 0; i < total; i++)
    {
        Operation op = operations[i];
        printf("%d - %d - %d\n", op.id, op.idComputer, op.time);
    }

    editOperation(operations, 1, size, 1, 2);
    editOperation(operations, 88, size, 1, 2);
    editOperation(operations, 3, size, 1, 2);

    // Show operations
    printf("After Editing:\n");
    for (int i = 0; i < total; i++)
    {
        Operation op = operations[i];
        printf("%d - %d - %d\n", op.id, op.idComputer, op.time);
    }

    deleteOperation(operations, &total, 1, size);
    deleteOperation(operations, &total, 20, size);
    deleteOperation(operations, &total, 3, size);


    // Show operations
    printf("After Removing:\n");
    for (int i = 0; i < total; i++)
    {
        Operation op = operations[i];
        printf("%d - %d - %d\n", op.id, op.idComputer, op.time);
    }


    // Save Operations to DB
    saveOpData(operations, total);


    return 0;
}
