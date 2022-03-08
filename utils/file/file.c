#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils.h"

// Load data of Operation
bool loadOpData(Operation* operations, int* total) 
{
    // Open file
    FILE *f = fopen("db/operations.txt", "r");
    char line[256];

    // Verify if isnt null
    if (f == NULL) 
    {
        printf("Error opening file!\n");
        return false;
    }

    // Get the text line by line
    while (fgets(line, sizeof(line), f)) 
    {
        // Remove the ";" and get the values and insert into the list
        char *ptr = strtok(line, ";");
        operations[*total].id = (int)strtol(ptr, (char **)NULL, 10);

        ptr = strtok(NULL, ";");
        operations[*total].idMachine = (int)strtol(ptr, (char **)NULL, 10);

        ptr = strtok(NULL, ";");
        operations[*total].time = (int)strtol(ptr, (char **)NULL, 10);

        // Increse plus one
        (*total)++;
    }

    // Close File
    fclose(f);

    return true;
}

// Save data of Object
bool saveOpData(Operation* operations, int total)
{
    // Open file
    FILE *f = fopen("db/operations.txt", "w");

    // Verify if isnt null
    if (f == NULL) 
    {
        printf("Error opening file!\n");
        return false;
    }

    // Goes operation a operation and saves it into a line in the file
    for (int i = 0; i < total; i++) 
    {
        Operation op = operations[i];
        fprintf(f, "%d;%d;%d\n", op.id, op.idMachine, op.time);
    }
    
    // Close File
    fclose(f);
    return true;
}