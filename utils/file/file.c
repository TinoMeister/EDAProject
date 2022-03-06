#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"

// Load data of Operation
bool loadOpData(Operation* operations, int* total) 
{
    FILE *f = fopen("db/operations.txt", "r");
    char line[256];

    if (f == NULL) 
    {
        printf("Error opening file!\n");
        return false;
    }

    while (fgets(line, sizeof(line), f)) 
    {
        char *ptr = strtok(line, ";");
        operations[*total].id = (int)strtol(ptr, (char **)NULL, 10);

        ptr = strtok(NULL, ";");
        operations[*total].idComputer = (int)strtol(ptr, (char **)NULL, 10);

        ptr = strtok(NULL, ";");
        operations[*total].time = (int)strtol(ptr, (char **)NULL, 10);

        (*total)++;
    }

    fclose(f);

    return true;
}

// Save data of Object
bool saveOpData(Operation* operations, int total)
{
    FILE *f = fopen("db/operations.txt", "w");

    if (f == NULL) 
    {
        printf("Error opening file!\n");
        return false;
    }

    for (int i = 0; i < total; i++) 
    {
        Operation op = operations[i];
        fprintf(f, "%d;%d;%d\n", op.id, op.idComputer, op.time);
    }
    
    fclose(f);
    return true;
}