#include <stdio.h>
#include <stdlib.h>

#include "operation.h"

// Get the total of Operations in the list
int getTotal(Operation* op)
{
    int total = 1;

    while (op != NULL)
    {
        total += 1;
        op = op->next;
    }
    

    return total;
}

// Verify if the id Machine alredy exists in Operation
bool verifyOperation(Operation* op, int id, int idMachine)
{
    bool exists = false;

    while (op != NULL)
    {
        if (op->id == id && op->idMachine == idMachine)
            exists = true;

        op = op->next;
    }
    
    return exists;
}

// Add new operation
Operation* addOperation(Operation* op, int id, int idMachine, int time)
{
    Operation *aux, *newOp = malloc(sizeof(Operation));
    bool exists = verifyOperation(op, id, idMachine);

    if (newOp != NULL && !exists)
    {
        newOp->id = id;
        newOp->idMachine = idMachine;
        newOp->time = time;

        // If null saves as first
        if (op == NULL)
        {
            newOp->next = NULL;
            op = newOp;
        }
        else if (id < op->id || (id == op->id && idMachine < op->idMachine))
        {
            newOp->next = op;
            op = newOp;
        }
        else
        {
            aux = op;

            while (aux->next && (id > aux->next->id || (id == aux->next->id && idMachine > aux->next->idMachine)))
                aux = aux->next;

            // The new operation gets the pointer from the previous operation pointer
            newOp->next = aux->next;
            // The next operation gets the the pointer from the new operation
            aux->next = newOp;
        }

        return op;
    }
    
    return NULL;
}

// Edit the operation
Operation* editOperation(Operation* op, int index, int id, int idMachine, int time)
{
    Operation *temp = op;
    int total = getTotal(op);
    bool exists = verifyOperation(op, id, idMachine);

    if (op != NULL && index > 0 && index <= total && !exists)
    {
        // Add like a new Operation
        temp = addOperation(temp, id, idMachine, time);

        if (temp != NULL)
        {
            // Delete de previous Operation
            temp = deleteOperation(temp, (index+1));

            return temp;
        }
    } 
    
    return NULL;
}

// Delete the operation
Operation* deleteOperation(Operation* op, int index)
{
    Operation *temp = op, *aux;
    int total = getTotal(op);

    if (op != NULL && index > 0 && index <= total)
    {
        if (index == 1) 
        {
            op = temp->next;
            free(temp);
        }
        else
        {
            for (int i = 0; i < (index-1); i++)
            { 
                aux = temp;
                temp = temp->next;
            }

            if (temp != NULL)
            {
                aux->next = temp->next;

                free(temp);
            }
        }

        return op;
    }
    
    return NULL;    
}

// Clean the list Operation.
void clean(Operation* op)
{
    Operation *aux;

    if (op != NULL)
    {
        while (op != NULL)
        {
            aux = op;
            op = op->next;
            free(aux);
        }
    }
}