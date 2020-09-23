#include<stdio.h>

int main() {

    int numberOfProcesses = 0;
    printf("enter the amount of processes up to 7:\n");
    scanf("%d", & numberOfProcesses);
    float averageWaitingTime = 0;
    float averageTurnAroundTime, totTurnAroundTimee, totWaitingTimee = 0;
    int arrivalTime[7] = {0},burstTime[7] = {0}, 
    turnAroundTime[7] = {0}, waitingTime[7] = {0}, 
    turnArr[7] = {0}, temp[7] = {0};
    int d = numberOfProcesses;
    int i, sum, timeQuantum, position,a;

    printf("\nnow enter arrival time and burst time accordingly\n");

    for (i = 0; i < numberOfProcesses; i++) {
        printf("arrivalTime[%d]:\n", i + 1);
        scanf("%d", & arrivalTime[i]);
        printf("burstTime[%d]:\n", i + 1);
        scanf("%d", & burstTime[i]);
        temp[i] = burstTime[i];

    }

    printf("\nenter time quantum:\t");
    scanf("%d", &timeQuantum);
    
    printf("\n");

    for (sum=0,i=0;d!=0;) {
        if (temp[i]<=timeQuantum&&temp[i]>0){
            sum=sum+temp[i];
            temp[i]=0;
            a=1;
        } else if (temp[i]>0){
            temp[i]=temp[i]-timeQuantum;
            sum=sum+timeQuantum;
        }
        if (temp[i]==0&&a==1) {
            d=d-1;
            turnArr[i]=sum-arrivalTime[i];
            waitingTime[i]=sum-arrivalTime[i]-burstTime[i];
            totWaitingTimee=totWaitingTimee+sum-arrivalTime[i]-burstTime[i];
            totTurnAroundTimee=totTurnAroundTimee+sum-arrivalTime[i];
            a = 0;
        }
        if (i==numberOfProcesses-1) {
            i=0;
        } else if (arrivalTime[i+1]<=sum) {
            i++;
        } else {
            i=0;
        }
    }

    averageWaitingTime = totWaitingTimee/numberOfProcesses;
    averageTurnAroundTime = totTurnAroundTimee/numberOfProcesses;

    printf("\n");

    for (i = 0; i < numberOfProcesses; i++) {
        printf("Process %d\n  arrivalTime %d\n  burstTime %d\n  turnAroundTime %d\n  waitingTime %d\n", i + 1, arrivalTime[i], burstTime[i], turnArr[i], waitingTime[i]);
    }

    printf("\n");

    printf("averageTurnAroundTime:  %f\n", averageTurnAroundTime);
    printf("averageWaitingTime:  %f", averageWaitingTime);

    return 0;
}
