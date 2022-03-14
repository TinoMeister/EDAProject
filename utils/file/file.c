#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils.h"

// Load data of Operation
Operation* loadOpData(Operation* op) 
{
    // Open file
    FILE *f = fopen("db/operations.txt", "r");
    char line[256];
    int id, idMachine, time;

    // Verify if isnt null
    if (f == NULL) 
    {
        printf("Error opening file!\n");
        return NULL;
    }

    // Get the text line by line
    while (fgets(line, sizeof(line), f)) 
    {
        // Remove the ";" and get the values and insert into the list
        char *ptr = strtok(line, ";");
        id = (int)strtol(ptr, (char **)NULL, 10);

        ptr = strtok(NULL, ";");
        idMachine = (int)strtol(ptr, (char **)NULL, 10);

        ptr = strtok(NULL, ";");
        time = (int)strtol(ptr, (char **)NULL, 10);

        // Add the Operation
        op = addOperation(op, id, idMachine, time);
    }

    // Close File
    fclose(f);

    // Return the list
    return op;
}

// Save data of Object
void saveOpData(Operation* op)
{
    // Open file
    FILE *f = fopen("db/operations.txt", "w");

    // Verify if isnt null
    if (f == NULL) 
    {
        printf("Error opening file!\n");
    }

    // Goes operation a operation and saves it into a line in the file
    while (op != NULL)
    {
        fprintf(f, "%d;%d;%d\n", op->id, op->idMachine, op->time);
        op = op->next;
    }
    
    // Close File
    fclose(f);

    // Free operation
    free(op);
}