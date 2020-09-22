#include<stdio.h>

int main(){

    int numberOfProcesses=0;
    printf("enter the amount of processes up to 7:\n");
	scanf("%d",&numberOfProcesses);
	
    float averageWaitingTime=0;
    float averageTurnAroundTime,totalTurnAroundTime,totalWaitingTime=0;
	int arrivalTime[7]={0},exTime[7]={0}, burstTime[7]={0},turnAroundTime[7]={0},waitingTime[7]={0},completionTime[7]={0};
	int i,sum,position,temp,locationOfLeast,shift,least,j=0;

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
        position=i;
        for(j=i+1;j<numberOfProcesses;j++)
        {
            if(burstTime[j]<burstTime[position])
                position=j;
        }
 
        temp=arrivalTime[i];
        arrivalTime[i]=arrivalTime[position];
        arrivalTime[position]=temp;
 
        temp=burstTime[i];
        burstTime[i]=burstTime[position];
        burstTime[position]=temp;
    }
    
    least=arrivalTime[0];
    
    for(i=0;i<numberOfProcesses;i++){
        if(least>arrivalTime[i]){
            least=arrivalTime[i];
            locationOfLeast=i;
        }
    }
    shift=least;
    exTime[locationOfLeast]=shift+burstTime[locationOfLeast];
    shift=exTime[locationOfLeast];
    
    for(i=0;i<numberOfProcesses;i++){
        if (arrivalTime[i]!=least){
            exTime[i]=burstTime[i]+shift;
            shift=exTime[i];
        }
    }

	for(i=0;i<numberOfProcesses;i++)
	{
		turnAroundTime[i]=exTime[i]-arrivalTime[i];
		totalTurnAroundTime=totalTurnAroundTime+turnAroundTime[i];
	}
	
	for(i=0;i<numberOfProcesses;i++)
	{
		waitingTime[i]=turnAroundTime[i]-burstTime[i];
		totalWaitingTime+=waitingTime[i];
	}
	
	printf("\n");
	
	for(i=0;i<numberOfProcesses;i++)
	{
		printf("Process %d\n  arrivalTime %d\n  burstTime %d\n  turnAroundTime %d\n  waitingTime %d\n",i+1,arrivalTime[i],burstTime[i],turnAroundTime[i],waitingTime[i]);
	}
	
	printf("\n");
	
	printf("averageTurnAroundTime:  %f\n",totalTurnAroundTime/numberOfProcesses);
	printf("averageWaitingTime:  %f",totalWaitingTime/numberOfProcesses);
	
	return 0;
}
