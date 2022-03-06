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