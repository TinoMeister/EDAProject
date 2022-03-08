#include "operation.h"

// Add new operation
bool addOperation(Operation* operations, int* total, int size, int id, int idMachine, int time)
{
    // Verify if the total is higher then the size of the array
    if (*total < size)
    {
        // Add the new values
        operations[*total].id = id;
        operations[*total].idMachine = idMachine;
        operations[*total].time = time;

        // Increase plus one
        (*total)++;

        return true;
    }

    return false;
}

// Edit the operation
bool editOperation(Operation* operations, int index, int size, int id, int idMachine, int time) 
{
    // Verify if the total is higher then the size of the array
    if (id < size)
    {
        // Update the values
        operations[index].id = id;
        operations[index].idMachine = idMachine;
        operations[index].time = time;

        return true;
    }
    
    return false;
}

// Delete the operation
bool deleteOperation(Operation* operations, int* total, int index, int size) 
{
    // Verify if the index is higher then the size of the array
    if (index < size)
    {
        // Go one by one and update the list by writting the next value to the actual.
        for (int i = index; i < *total; i++) 
        {
            if ((i+1) < *total)
                operations[i] = operations[i+1];
        }    

        // Reduce one
        (*total)--;
    }
}