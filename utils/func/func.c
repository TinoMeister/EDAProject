#include <stdio.h>
#include <stdlib.h>

#include "../utils.h"

// Get the lower timer to complete a job and return the list for each operation
Operation* getShorter(Operation* operations, int total, int size)
{
    Operation* newOperations = malloc(sizeof(Operation)*size);
    int id = 1;
    int lower = 999;

    for (int  i = 0; i < total; i++)
    {
        Operation op = operations[i];

        // Verify if the idOperation change, if so the then increase plus one and reset the lower value
        if (id != op.id)
        {
            id++;
            lower = 999;
        }
        
        // Verify if the value lower is higher than of the time if so then update the list and put the value lower with the same as the operation
        if (lower > op.time)
        {
            newOperations[id - 1] = op;
            lower = op.time;
        } 
    }

    return newOperations;
}

// Get the high timer to complete a job and return the list for each operation
Operation* getLonger(Operation* operations, int total, int size)
{
    Operation* newOperations = malloc(sizeof(Operation)*size);
    int id = 1;
    int higher = -1;

    for (int  i = 0; i < total; i++)
    {
        Operation op = operations[i];

        // Verify if the idOperation change, if so the then increase plus one and reset the lower value
        if (id != op.id)
        {
            id++;
            higher = -1;
        }
        
        // Verify if the value lower is higher than of the time if so then update the list and put the value lower with the same as the operation
        if (higher < op.time)
        {
            newOperations[id - 1] = op;
            higher = op.time;
        } 
    }

    return newOperations;
}

// Get the average timer to complete a job considering all the alternatives and return the list for each operation
float getAverage(Operation* operations, int total, int id)
{
    float result = 0;
    int count = 0;

    for (int i = 0; i < total; i++)
    {
        Operation op = operations[i];

        if (id == op.id)
        {
            result += op.time;
            count++;
        }

    }

    return result / count;
}
