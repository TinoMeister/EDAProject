#include <stdio.h>
#include <stdlib.h>

#include "utils/utils.h"


int main(int argc, char const *argv[]) 
{
    int size = 20;
    Operation* operations = malloc(sizeof(Operation)*size);
    int total = 0;

    // Load Operations from DB
    loadOpData(operations, &total);

    // Show operations
    printf("After Loading:\n");
    for (int i = 0; i < total; i++)
    {
        Operation op = operations[i];
        printf("%d - %d - %d\n", op.id, op.idComputer, op.time);
    }
    printf("\n\n");

    // Get Lower 
    int n = operations[total-1].id;
    Operation* newOperations;
    newOperations = getShorter(operations, total, n);

    // Show operations
    printf("\nAfter getShorter:\n");
    for (int i = 0; i < n; i++)
    {
        Operation op = newOperations[i];
        printf("%d - %d - %d\n", op.id, op.idComputer, op.time);
    }

    free(newOperations);


    // Get Higher
    newOperations = getLonger(operations, total, n);

    // Show operations
    printf("\nAfter getLonger:\n");
    for (int i = 0; i < n; i++)
    {
        Operation op = newOperations[i];
        printf("%d - %d - %d\n", op.id, op.idComputer, op.time);
    }

    free(newOperations);


    // Get Average
    printf("\nAfter Average:\n");
    for (int i = 0; i < n; i++)
    {
        float average = getAverage(operations, total, (i+1));

        printf("Average: %d - %.2f\n", (i+1), average);
    }
    


    
    /*
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
        printf("%d - %d - %d\n", op.id, op.idComputer, op.time);
    }
    
    // Edit Operations
    editOperation(operations, 1, size, 1, 1, 2);
    editOperation(operations, 88, size, 2, 1, 2);
    editOperation(operations, 3, size, 3, 1, 2);

    // Show operations
    printf("\nAfter Editing:\n");
    for (int i = 0; i < total; i++)
    {
        Operation op = operations[i];
        printf("%d - %d - %d\n", op.id, op.idComputer, op.time);
    }

    
    // Delete Operations
    deleteOperation(operations, &total, 1, size);
    deleteOperation(operations, &total, 20, size);
    deleteOperation(operations, &total, 3, size);


    // Show operations
    printf("\nAfter Removing:\n");
    for (int i = 0; i < total; i++)
    {
        Operation op = operations[i];
        printf("%d - %d - %d\n", op.id, op.idComputer, op.time);
    }

    
    // Save Operations to DB
    saveOpData(operations, total);
    */

    return 0;
}
