#include <stdio.h>
#include <stdlib.h>

#include "../utils.h"

// Get the total of operations
int getTotalOp(Operation* operations, int total)
{
    int totalOp = 0;

    for (int i = 0; i < total; i++)
    {
        Operation op = operations[i];

        // Verify if the varaible totalOp is lower then the id of operations
        if (totalOp < op.id)
            totalOp = op.id; // Update the variable
    }

    // Return the id
    return totalOp;
}

// Get the lower timer to complete a job and return the list for each operation
Operation* getShorter(Operation* operations, int total, int size)
{
    Operation* newOperations = malloc(sizeof(Operation)*size);
    int lower = 999;

    for (int i = 0; i < size; i++)
    {
        int id = (i+1);

        for (int j = 0; j < total; j++)
        {
            Operation op = operations[j];

            // Verify if the id are equals
            if (id == op.id)
            {
                // Verify if the value lower is higher than of the time if so then update 
                //the list and put the value lower with the same as the operation
                if (lower > op.time)
                {
                    newOperations[id - 1] = op;
                    lower = op.time;
                } 
            }
        }

        // Reset variable
        lower = 999;
    }

    // Return the new variable
    return newOperations;
}

// Get the high timer to complete a job and return the list for each operation
Operation* getLonger(Operation* operations, int total, int size)
{
    Operation* newOperations = malloc(sizeof(Operation)*size);
    int higher = -1;
    int id = 0;

    for (int i = 0; i < size; i++)
    {
        id = (i+1);

        for (int j = 0; j < total; j++)
        {
            Operation op = operations[j];

            // Verify if the id are equals
            if (id == op.id)
            {
                // Verify if the value higher is lower than of the time if so then update 
                //the list and put the value higher with the same as the operation
                if (higher < op.time)
                {
                    newOperations[id - 1] = op;
                    higher = op.time;
                } 
            }
        }

        // Reset variable
        higher = -1;
    }

    // Return the new operations
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

        // Verify if the id is equal to the id of operation
        if (id == op.id)
        {
            // Increase time e count + 1 
            result += op.time;
            count++;
        }

    }

    // Return the value by dividing the result from count
    return result / count;
}
