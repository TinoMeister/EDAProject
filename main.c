#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "utils/utils.h"


void showAll(Operation* operations, int total)
{
    printf("\nindex |  id  | idCom | time\n");
    for (int i = 0; i < total; i++)
    {
        Operation op = operations[i];

        printf("%d | %d | %d | %d\n", (i+1), op.id, op.idComputer, op.time);
    }
    
    printf("\n\n");
}


int main(int argc, char const *argv[])
{
    Operation* operations = malloc(sizeof(Operation)*TAM);
    Operation* newOperations;
    int total = 0, totalOp = 0;
    char op;

    // Load Operations from DB
    loadOpData(operations, &total);

    while (op != 'x')
    {
        int index, id, idComputer, time;
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

        printf("Option: ");
        scanf(" %c", &op);
        op = tolower(op);

        switch (op)
        {
            case 'a':

                system("clear");

                printf("---------------------------------------------------------------\n");
                printf("|                        Add Operation                        |\n");
                printf("---------------------------------------------------------------\n\n");

                printf("Insert id of operation: ");
                scanf("%d", &id);

                printf("Insert computer number: ");
                scanf("%d", &idComputer);

                printf("Insert time of computer: ");
                scanf("%d", &time);

                result = addOperation(operations, &total, TAM, id, idComputer, time);

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

                showAll(operations, total);

                printf("\nInsert index to update: ");
                scanf("%d", &index);

                printf("Insert id of operation to change: ");
                scanf("%d", &id);

                printf("Insert computer number to change: ");
                scanf("%d", &idComputer);

                printf("Insert time of computer to change: ");
                scanf("%d", &time);

                result = editOperation(operations, (index-1), TAM, id, idComputer, time);

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

                showAll(operations, total);

                printf("\nInsert index to delete: ");
                scanf("%d", &index);

                result = deleteOperation(operations, &total, (index-1), TAM);

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

                showAll(operations, total);
                break;

            case 'e':

                system("clear");

                printf("----------------------------------------------------------------\n");
                printf("|                   See All Operation by Lower Time            |\n");
                printf("----------------------------------------------------------------\n\n");

                totalOp = getTotalOp(operations, total);
                newOperations = getShorter(operations, total, totalOp);

                if (newOperations != NULL)
                    showAll(newOperations, totalOp);
                else
                    printf("Something went wrong!!\n\n");

                free(newOperations);
                
                break;

            case 'f':

                system("clear");

                printf("----------------------------------------------------------------\n");
                printf("|                   See All Operation by Higher Time            |\n");
                printf("----------------------------------------------------------------\n\n");

                totalOp = getTotalOp(operations, total);
                newOperations = getLonger(operations, total, totalOp);

                if (newOperations != NULL)
                    showAll(newOperations, totalOp);
                else
                    printf("Something went wrong!!\n\n");

                free(newOperations);
                    
                break;

            case 'g':

                system("clear");

                printf("----------------------------------------------------------------\n");
                printf("|                   See All Operation by Average Time            |\n");
                printf("----------------------------------------------------------------\n\n");

                totalOp = getTotalOp(operations, total);                

                for (int i = 0; i < totalOp; i++)
                {
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
        printf("%d - %d - %d\n", op.id, op.idComputer, op.time);
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
        printf("%d - %d - %d\n", op.id, op.idComputer, op.time);
    }

    free(newOperations);


    // Get Higher
    newOperations = getLonger(operations, total, n);

    // Show operations
    printf("\nAfter getLonger:\n");
    for (int i = 0; i < n; i++)
    {
        Operation op = newOperations[i];
        printf("%d - %d - %d\n", op.id, op.idComputer, op.time);
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
        printf("%d - %d - %d\n", op.id, op.idComputer, op.time);
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
        printf("%d - %d - %d\n", op.id, op.idComputer, op.time);
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
        printf("%d - %d - %d\n", op.id, op.idComputer, op.time);
    }

    
    // Save Operations to DB
    saveOpData(operations, total);
    

    return 0;
}
*/