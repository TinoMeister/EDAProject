#include <stdio.h>
#include <stdlib.h>

#include "../utils.h"

// Get the id of Operation on the last Operation
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

// Get the lower timer to complete a job and return the list for each operation
void showShorter(Operation* op) 
{
    Operation *aux = malloc(sizeof(Operation));
    Operation *temp = malloc(sizeof(Operation));
    int totalOp = getTotalOp(op), lower = 999;

    if (op != NULL)
    {
        printf("Id | IdMachine | Time\n");
        for (int i = 0; i < totalOp; i++)
        {
            aux = op;

            while (aux != NULL)
            {
                if ((i+1) == aux->id && lower > aux->time)
                {
                    temp = aux;
                    lower = aux->time;
                }
                aux = aux->next; 
            }

            if (lower != 999)        
                printf("%d | %d | %d\n", temp->id, temp->idMachine, temp->time);

            lower = 999;
        }
    }
}

// Get the high timer to complete a job and return the list for each operation
void showLonger(Operation* op) 
{
    Operation *aux = malloc(sizeof(Operation));
    Operation *temp = malloc(sizeof(Operation));
    int totalOp = getTotalOp(op), higher = -1;

    if (op != NULL)
    {
        printf("Id | IdMachine | Time\n");
        for (int i = 0; i < totalOp; i++)
        {
            aux = op;

            while (aux != NULL)
            {
                if ((i+1) == aux->id && higher < aux->time)
                {
                    temp = aux;
                    higher = aux->time;
                }
                aux = aux->next; 
            }

            if (higher != -1)        
                printf("%d | %d | %d\n", temp->id, temp->idMachine, temp->time);

            higher = -1;
        }
    }
}

// Get the average timer to complete a job considering 
//all the alternatives and return the list for each operation
void showAverage(Operation* op) 
{
    Operation *aux = malloc(sizeof(Operation));
    int totalOp = getTotalOp(op), count = 0;
    float result = 0;

    if (op != NULL)
    {
        printf("Id | Time\n");
        for (int i = 0; i < totalOp; i++)
        {
            aux = op;

            while (aux != NULL)
            {
                if ((i+1) == aux->id)
                {
                    result += aux->time;
                    count++;
                }
                aux = aux->next; 
            }

            if (count != 0 && result != 0)
                printf("%d | %.2f\n", (i+1), result/count);

            count = 0;
            result = 0;
        }
    }
}