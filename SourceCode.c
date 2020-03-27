#include<stdio.h>
#include<unistd.h>
int main(){

    //Total resources
    int sumPQ{0}, sumOfRec{0};

    //Resources available
    int P;
    printf("Enter the value of 'P' resources available :- ");
    scanf("%d", &P);

     //Number of processes
    int Q;
    printf("Enter the number of 'Q' processes :- ");
    scanf("%d", &Q);

    //Sum of P and Q
    sumPQ = P + Q;
    printf("\n");

    for (int i = 0; i < Q; ++i)
    {
        int rec;
        printf("Enter the number resources you need :- ");
        scanf("%d", &rec);
        sumOfRec += rec;

        if(rec < 1)
        {
            printf("System is Not in Safe state,\n");
            printf("As entered number is less then 1.\n");
            return 0;
        }

        if((rec > P) || (sumOfRec > sumPQ))
        {
            printf("\n\nSystem is Not in Safe state,\n");
            printf("As the required number of resources is more than the total number of resources available.\n");
            printf("Process is terminating\n\n");
            return 0;
        }
        else
        {
            P = P - rec;
            printf("\nResources allocated successfully \n");
            printf("The system is in safe state.\n");

            P = P + rec;
            printf("Resources allocated successfully\n\n");
        }
    }

    return 0;
}
