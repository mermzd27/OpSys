#include<stdio.h>

int main(){

    int numberOfProcesses=0;
    printf("enter the amount of processes up to 7:\n");
	scanf("%d",&numberOfProcesses);
	
    float averageWaitingTime=0;
    float averageTurnAroundTime,totalTurnAroundTime,totalWaitingTime=0;
	int arrivalTime[7]={0}, burstTime[7]={0},turnAroundTime[7]={0},waitingTime[7]={0},completionTime[7]={0};
	int i,sum=0;

	printf("\nnow enter arrival time and burst time accordingly\n");

	for(i=0;i<numberOfProcesses;i++)
	{
		printf("arrivalTime[%d]:\n",i+1);
		scanf("%d",&arrivalTime[i]);
		printf("burstTime[%d]:\n",i+1);
		scanf("%d",&burstTime[i]);
	}

	for(i=0;i<numberOfProcesses;i++)
	{
		sum+=burstTime[i];
		completionTime[i]+=sum;
	}

	for(i=0;i<numberOfProcesses;i++)
	{
		turnAroundTime[i]=completionTime[i]-arrivalTime[i];
		totalTurnAroundTime+=turnAroundTime[i];
	}
	
	for(i=0;i<numberOfProcesses;i++)
	{
		waitingTime[i]=turnAroundTime[i]-burstTime[i];
		totalWaitingTime+=waitingTime[i];
	}
	
	printf("\n");

	for(i=0;i<numberOfProcesses;i++)
	{
		printf("Process %d\n  arrivalTime %d\n  burstTime %d\n  completionTime %d\n  turnAroundTime %d\n  waitingTime %d\n",i+1,arrivalTime[i],burstTime[i],completionTime[i],turnAroundTime[i],waitingTime[i]);
	}
	
	printf("\n");
	
	averageTurnAroundTime=(totalTurnAroundTime/numberOfProcesses);
	averageWaitingTime=(totalWaitingTime/numberOfProcesses);

	printf("averageTurnAroundTime:  %f\n",averageTurnAroundTime);
	printf("averageWaitingTime:  %f",averageWaitingTime);
	
	return 0;
}
