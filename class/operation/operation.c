#include <stdio.h>
#include <stdlib.h>

#include "operation.h"

// Add new operation
Operation* addOperation(Operation* op, int id, int idMachine, int time)
{
    Operation *aux, *newOp = malloc(sizeof(Operation));

    if (newOp != NULL)
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
    }
    
    return op;
    
}

// Edit the operation
Operation* editOperation(Operation* op, int index, int id, int idMachine, int time)
{
    Operation *temp = op;

    if (op != NULL)
    {
        for (int i = 0; i < (index-1); i++)
            temp = temp->next;

        temp->id = id;
        temp->idMachine = idMachine;
        temp->time = time;

        return op;
    } 
    else return NULL;
}

// Delete the operation
Operation* deleteOperation(Operation* op, int index)
{
    Operation *temp = op, *aux;

    if (op != NULL)
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
    else return NULL;    
}