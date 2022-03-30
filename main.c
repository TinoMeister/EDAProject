#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "utils/utils.h"

// Show All Operations
void showAll(Operation * obj)
{
    int count = 0;

    if (obj != NULL)
    {
        printf("Index | Id | Machine | Time\n");
        while (obj != NULL)
        {
            printf("%d | %d | %d | %d\n", (count+1), obj->id, obj->idMachine, obj->time);
            obj = obj->next;
            count++;
        }
    }    
    else 
    {
        printf("Lista vazia");
    }
}

// Show Operations with lower time
void showShorter(Operation* op)
{
    Operation *lower = malloc(sizeof(Operation));
    int totalOp = getTotalOp(op), count = 0;

    if (op != NULL)
    {
        printf("Id | IdMachine | Time\n");
        for (int i = 1; i <= totalOp; i++)
        {
            lower = getShorter(op, i);

            if (lower != NULL)
            {
                printf("%d | %d | %d\n", lower->id, lower->idMachine, lower->time);
                count += lower->time;
            }
            
            lower = NULL;
        }

        printf("Total: %d\n", count);
    }
}

// Show Operations with higher time
void showLonger(Operation* op)
{
    Operation *higher = malloc(sizeof(Operation));
    int totalOp = getTotalOp(op), count = 0;

    if (op != NULL)
    {
        printf("Id | IdMachine | Time\n");
        for (int i = 1; i <= totalOp; i++)
        {
            higher = getLonger(op, i);

            if (higher != NULL)
            {
                printf("%d | %d | %d\n", higher->id, higher->idMachine, higher->time);
                count += higher->time;
            }
            
            higher = NULL;
        }

        printf("Total: %d\n", count);
    }
}

// Show Operations average time
void showAverage(Operation* op)
{
    int totalOp = getTotalOp(op);
    float result = 0, count = 0;

    if (op != NULL)
    {
        printf("Id | Time\n");
        for (int i = 1; i <= totalOp; i++)
        {
            result = getAverage(op, i);

            if (result > -1)
            {
                printf("%d | %.2f\n", i, result);
                count += result;
            }
        }

        printf("Total: %.2f\n", count);
    }
}


int main(int argc, char const *argv[])
{
    // Variables
    Operation *op = NULL, *result;
    char option;

    // Load Operations from DB
    op = loadOpData(op);

    while (option != 'x')
    {
        // Variables
        int index, id, idMachine, time;

        system("clear");

        printf("------------------------------------------------------------------\n");
        printf("|                        WELCOME TO FJSSP                        |\n");
        printf("------------------------------------------------------------------\n\n");

        printf("Operations:\n");
        printf("a) Insert new Operation   b) Edit Operation    c) Delete Operation\n");
        printf("d) See All                e) Get lower time    f) Get higher time\n");
        printf("g) Get average time       x) Exit\n\n");

        // Ask for option to execute
        printf("Option: ");
        scanf(" %c", &option);
        option = tolower(option); // Put the result of the user to lower

        switch (option)
        {
            case 'a':

                system("clear");

                printf("---------------------------------------------------------------\n");
                printf("|                        Add Operation                        |\n");
                printf("---------------------------------------------------------------\n\n");

                // Ask for id, id of Machine and time
                printf("Insert id of operation: ");
                scanf("%d", &id);

                printf("Insert Machine number: ");
                scanf("%d", &idMachine);

                printf("Insert time of Machine: ");
                scanf("%d", &time);
                
                // Add a new operation and return True or False
                result = addOperation(op, id, idMachine, time);
                
                // Print if is Successfull or if there is a problem
                if (result != NULL)
                {
                    op = result;
                    printf("\nSuccessfully Inserted!!\n\n");
                }
                else
                    printf("\nSomething went wrong!!\n\n");

                break;
            
            case 'b':

                system("clear");

                printf("----------------------------------------------------------------\n");
                printf("|                        Edit Operation                        |\n");
                printf("----------------------------------------------------------------\n\n");

                // Show all operations
                showAll(op);

                // Ask for index, id, id of Machine and time
                printf("\nInsert index to update: ");
                scanf("%d", &index);

                printf("Insert id of operation to change: ");
                scanf("%d", &id);

                printf("Insert Machine number to change: ");
                scanf("%d", &idMachine);

                printf("Insert time of Machine to change: ");
                scanf("%d", &time);

                result = editOperation(op, index, id, idMachine, time);                

                if (result != NULL)
                {
                    op = result;
                    printf("Successfully Updated!!\n\n");
                }
                else
                    printf("Something went wrong!!\n\n");
                    
                break;

            case 'c':

                system("clear");

                printf("-----------------------------------------------------------------\n");
                printf("|                       Delete Operation                        |\n");
                printf("-----------------------------------------------------------------\n\n");

                // Show all operations
                showAll(op);

                // Ask for index
                printf("\nInsert index to delete: ");
                scanf("%d", &index);

                result = deleteOperation(op, index);

                if (result != NULL)
                {
                    op = result;
                    printf("Successfully Deleted!!\n\n");
                }
                else
                    printf("Something went wrong!!\n\n");
                    
                break;

            case 'd':

                system("clear");

                printf("----------------------------------------------------------------\n");
                printf("|                      See All Operation                        |\n");
                printf("----------------------------------------------------------------\n\n");

                // Show all operations
                showAll(op);
                break;

            case 'e':

                system("clear");

                printf("----------------------------------------------------------------\n");
                printf("|                   See All Operation by Lower Time            |\n");
                printf("----------------------------------------------------------------\n\n");

                // Get the lower time
                showShorter(op);
                
                break;

            case 'f':

                system("clear");

                printf("----------------------------------------------------------------\n");
                printf("|                   See All Operation by Higher Time            |\n");
                printf("----------------------------------------------------------------\n\n");

                showLonger(op);
                    
                break;

            case 'g':

                system("clear");

                printf("----------------------------------------------------------------\n");
                printf("|                 See All Operation by Average Time            |\n");
                printf("----------------------------------------------------------------\n\n");

                // Get Average by Operation
                showAverage(op);

                printf("\n\n");
                    
                break;

            case 'x':
                // Save Operations to DB
                saveOpData(op);
                // Clean List Operation
                clean(op);

                printf("See you next time!\n\n");  
                break;
            
            default:
                break;
        }

        if (option != 'x') {
            printf("Press [Enter] key to continue.\n");
            while(getchar()!='\n'); // option TWO to clean stdin
            getchar(); // wait for ENTER 
        }
    }
    
    return 0;
}