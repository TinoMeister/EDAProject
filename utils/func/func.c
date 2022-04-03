#include <stdio.h>
#include <stdlib.h>

#include "../utils.h"

// Get the highets id of Operation
int getTotalOp(Operation* op)
{
    int total = 0;

    while (op)
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

    // If the list is NULL return NULL
    if (!op)
        return NULL;

    while (op)
    {
        // Verify if the id is equal to the id of element in the list and if the
        // time NULL or if is higher then the time of the element if so the update
        if (id == op->id && (!lower || lower->time > op->time))
            lower = op;

        // Get the next element
        op = op->next; 
    }

    // Return the operation with lowest time
    return lower;
}

// Get the higher timer to complete a operation
Operation* getLonger(Operation* op, int id)
{
    Operation *higher = NULL;

    // If the list is NULL return NULL
    if (!op)
        return NULL;

    while (op)
    {
        // Verify if the id is equal to the id of element in the list and if the
        // time NULL or if is lower then the time of the element if so the update
        if (id == op->id && (!higher || higher->time < op->time))
            higher = op;

        // Get the next element
        op = op->next; 
    }

    // Return the operation with highest time
    return higher;
}

// Get the average timer to complete a operation
float getAverage(Operation* op, int id) 
{
    int count = 0, total = 0;

    while (op)
    {
        // If the id is equal to the id of the element on the list then increase plus
        // one to the count and increase the time value
        if (id == op->id)
        {
            total += op->time;
            count++;
        }

        // Get the next element
        op = op->next; 
    }

    // If count equals to 0 then return -1 else return the total of time divided by
    // total of operations
    if (count == 0)
        return -1;
    else
        return total / count;
}