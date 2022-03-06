#include "operation.h"


// Add new operation
bool addOperation(Operation* operations, int* total, int size, int idComputer, int time)
{
    // Verify if the total is higher then the size of the array
    if (*total < size)
    {
        // Add the new values
        operations[*total].id = (*total + 1);
        operations[*total].idComputer = idComputer;
        operations[*total].time = time;

        // increase plus one
        (*total)++;

        return true;
    }

    return false;
}

// Edit the operation
bool editOperation(Operation* operations, int id, int size, int idComputer, int time) 
{
    if (id < size)
    {
        int index = id - 1;

        operations[index].idComputer = idComputer;
        operations[index].time = time;

        return true;
    }
    
    return false;
}

// Delete the operation
bool deleteOperation(Operation* operations, int* total, int id, int size) 
{
    if (id < size)
    {
        int index = id - 1;

        for (int i = index-1; i < *total; i++) 
        {
            if ((i+1) < *total)
                operations[i] = operations[i+1];
        }    

        (*total)--;
    }
}