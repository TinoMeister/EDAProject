#include <stdio.h>
#include <stdlib.h>

#include "../utils.h"

// Get the highets id of Operation
int getTotalOp(Operation* op)
{
    int total = 0;

    while (op != NULL)
    {
        if (total < op->id)
            total = op->id;

        op = op->next;
    }

    return total;
}

// Get the lower timer to complete a operation
Operation* getShorter(Operation* op, int id) 
{
    Operation *lower = NULL;

    if (op != NULL)
    {
        while (op != NULL)
        {
            if (id == op->id && (lower == NULL || lower->time > op->time))
                lower = op;

            op = op->next; 
        }

        return lower;
    }

    return NULL;
}

// Get the higher timer to complete a operation
Operation* getLonger(Operation* op, int id)
{
    Operation *higher = NULL;

    if (op != NULL)
    {
        while (op != NULL)
        {
            if (id == op->id && (higher == NULL || higher->time < op->time))
                higher = op;

            op = op->next; 
        }

        return higher;
    }

    return NULL;
}

// Get the average timer to complete a operation
float getAverage(Operation* op, int id) 
{
    int count = 0, total = 0;

    while (op != NULL)
    {
        if (id == op->id)
        {
            total += op->time;
            count++;
        }

        op = op->next; 
    }

    if (count == 0)
        return -1;
    else
        return total / count;
}