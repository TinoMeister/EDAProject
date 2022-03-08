#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "utils/utils.h"

//! A function that takes two arguments and print the content of the first argument.
/*!
    \param operations an Operations point.
    \param total a constant character pointer.
*/
void showAll(Operation* operations, int total)
{
    printf("\nindex |  id  | idCom | time\n");
    for (int i = 0; i < total; i++)
    {
        Operation op = operations[i];

        printf("%d | %d | %d | %d\n", (i+1), op.id, op.idMachine, op.time);
    }
    
    printf("\n\n");
}


int main(int argc, char const *argv[])
{
    // Variables
    Operation* operations = malloc(sizeof(Operation)*TAM);
    Operation* newOperations;
    int total = 0, totalOp = 0;
    char op;

    
    // Load Operations from DB
    loadOpData(operations, &total);

    while (op != 'x')
    {
        // Variables
        int index, id, idMachine, time;
        float average;
        bool result;

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
        scanf(" %c", &op);
        op = tolower(op); // Put the result of the user to lower

        switch (op)
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
                result = addOperation(operations, &total, TAM, id, idMachine, time);

                
                // Print if is Successfull or if there is a problem
                if (result)
                    printf("\nSuccessfully Inserted!!\n\n");
                else
                    printf("\nSomething went wrong!!\n\n");

                break;

            case 'b':

                system("clear");

                printf("----------------------------------------------------------------\n");
                printf("|                        Edit Operation                        |\n");
                printf("----------------------------------------------------------------\n\n");

                // Show all operations
                showAll(operations, total);

                // Ask for index, id, id of Machine and time
                printf("\nInsert index to update: ");
                scanf("%d", &index);

                printf("Insert id of operation to change: ");
                scanf("%d", &id);

                printf("Insert Machine number to change: ");
                scanf("%d", &idMachine);

                printf("Insert time of Machine to change: ");
                scanf("%d", &time);

                // Edit the operation and return True or False
                result = editOperation(operations, (index-1), TAM, id, idMachine, time);

                // Print if is Successfull or if there is a problem
                if (result)
                    printf("Successfully Updated!!\n\n");
                else
                    printf("Something went wrong!!\n\n");
                    
                break;

            case 'c':

                system("clear");

                printf("-----------------------------------------------------------------\n");
                printf("|                       Delete Operation                        |\n");
                printf("-----------------------------------------------------------------\n\n");

                // Show all operations
                showAll(operations, total);

                // Ask for index
                printf("\nInsert index to delete: ");
                scanf("%d", &index);

                // Delete the operation and return True or False
                result = deleteOperation(operations, &total, (index-1), TAM);

                // Print if is Successfull or if there is a problem
                if (result)
                    printf("Successfully Deleted!!\n\n");
                else
                    printf("Something went wrong!!\n\n");
                    
                break;

            case 'd':

                system("clear");

                printf("----------------------------------------------------------------\n");
                printf("|                      See All Operation                        |\n");
                printf("----------------------------------------------------------------\n\n");

                // Show all operations
                showAll(operations, total);
                break;

            case 'e':

                system("clear");

                printf("----------------------------------------------------------------\n");
                printf("|                   See All Operation by Lower Time            |\n");
                printf("----------------------------------------------------------------\n\n");

                // Get Total Operations and get the lower time
                totalOp = getTotalOp(operations, total);
                newOperations = getShorter(operations, total, totalOp);

                // Show Operations by Lower Time
                if (newOperations != NULL)
                    showAll(newOperations, totalOp);
                else
                    printf("Something went wrong!!\n\n");

                // Free memory
                free(newOperations);
                
                break;

            case 'f':

                system("clear");

                printf("----------------------------------------------------------------\n");
                printf("|                   See All Operation by Higher Time            |\n");
                printf("----------------------------------------------------------------\n\n");

                // Get Total Operations and get the higher time
                totalOp = getTotalOp(operations, total);
                newOperations = getLonger(operations, total, totalOp);

                // Show Operations by Higher Time
                if (newOperations != NULL)
                    showAll(newOperations, totalOp);
                else
                    printf("Something went wrong!!\n\n");

                // Free memory
                free(newOperations);
                    
                break;

            case 'g':

                system("clear");

                printf("----------------------------------------------------------------\n");
                printf("|                   See All Operation by Average Time            |\n");
                printf("----------------------------------------------------------------\n\n");

                // Get Total Operations
                totalOp = getTotalOp(operations, total);                

                // Show Operations
                for (int i = 0; i < totalOp; i++)
                {
                    // Get Average by Operation
                    average = getAverage(operations, total, (i+1));

                    printf("Average: %d - %.2f\n", (i+1), average);
                }

                printf("\n\n");
                    
                break;

            case 'x':
                // Save Operations to DB
                saveOpData(operations, total);

                printf("See you next time!\n\n");  
                break;
            
            default:
                break;
        }

        if (op != 'x') {
            printf("Press [Enter] key to continue.\n");
            while(getchar()!='\n'); // option TWO to clean stdin
            getchar(); // wait for ENTER 
        }
    }
    
    return 0;
}

/*
int main2(int argc, char const *argv[]) 
{
    int size = 20;
    Operation* operations = malloc(sizeof(Operation)*size);
    int total = 0;

    // Load Operations from DB
    loadOpData(operations, &total);

    // Show operations
    printf("After Loading:\n");
    for (int i = 0; i < total; i++)
    {
        Operation op = operations[i];
        printf("%d - %d - %d\n", op.id, op.idMachine, op.time);
    }
    printf("\n\n");

    // Get Lower 
    int n = operations[total-1].id;
    Operation* newOperations;
    newOperations = getShorter(operations, total, n);

    // Show operations
    printf("\nAfter getShorter:\n");
    for (int i = 0; i < n; i++)
    {
        Operation op = newOperations[i];
        printf("%d - %d - %d\n", op.id, op.idMachine, op.time);
    }

    free(newOperations);


    // Get Higher
    newOperations = getLonger(operations, total, n);

    // Show operations
    printf("\nAfter getLonger:\n");
    for (int i = 0; i < n; i++)
    {
        Operation op = newOperations[i];
        printf("%d - %d - %d\n", op.id, op.idMachine, op.time);
    }

    free(newOperations);


    // Get Average
    printf("\nAfter Average:\n");
    for (int i = 0; i < n; i++)
    {
        float average = getAverage(operations, total, (i+1));

        printf("Average: %d - %.2f\n", (i+1), average);
    }
    


    
    /*
    // Add Operations
    addOperation(operations, &total, size, 1, 1, 4);
    addOperation(operations, &total, size, 1, 3, 5);
    addOperation(operations, &total, size, 2, 2, 4);
    addOperation(operations, &total, size, 2, 4, 5);
    addOperation(operations, &total, size, 3, 3, 5);
    addOperation(operations, &total, size, 3, 5, 6);
    addOperation(operations, &total, size, 4, 4, 5);
    addOperation(operations, &total, size, 4, 5, 5);
    addOperation(operations, &total, size, 4, 6, 4);
    addOperation(operations, &total, size, 4, 7, 5);
    addOperation(operations, &total, size, 4, 8, 9);

    // Show operations
    printf("After Adding:\n");
    for (int i = 0; i < total; i++)
    {
        Operation op = operations[i];
        printf("%d - %d - %d\n", op.id, op.idMachine, op.time);
    }
    
    // Edit Operations
    editOperation(operations, 1, size, 1, 1, 2);
    editOperation(operations, 88, size, 2, 1, 2);
    editOperation(operations, 3, size, 3, 1, 2);

    // Show operations
    printf("\nAfter Editing:\n");
    for (int i = 0; i < total; i++)
    {
        Operation op = operations[i];
        printf("%d - %d - %d\n", op.id, op.idMachine, op.time);
    }

    
    // Delete Operations
    deleteOperation(operations, &total, 1, size);
    deleteOperation(operations, &total, 20, size);
    deleteOperation(operations, &total, 3, size);


    // Show operations
    printf("\nAfter Removing:\n");
    for (int i = 0; i < total; i++)
    {
        Operation op = operations[i];
        printf("%d - %d - %d\n", op.id, op.idMachine, op.time);
    }

    
    // Save Operations to DB
    saveOpData(operations, total);
    

    return 0;
}
*/