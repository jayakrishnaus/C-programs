#include<stdio.h>
#include<stdlib.h>


void swap(int a[],int j,int i)
{
    int t;
    t=a[j];
    a[j]=a[i];
    a[i]=t;
}
void main()
{
    int i,burstTime[20],remainTime[20],remainProcess,arrivalTime[20],totalExecutionTime=0,timeQuantum,flag=0,n,pid[20];
    float totalWaitingTime=0;
    printf("Enter the Number of Process(max 20) : ");
    scanf("%d",&n); // n is the number of Process
    remainProcess=n;

    printf("Enter Arrival Time\n");
    for(i=0;i<n;i++){
        printf("For P[%d]: ",i+1);
        scanf("%d",&arrivalTime[i]);
        pid[i]=i+1;
    }

    printf("\nEnter Burst Time\n");
    for(i=0;i<n;i++){
        printf("For P[%d]: ",i+1);
        scanf("%d",&burstTime[i]);
        remainTime[i]=burstTime[i]; // initially assume remain time for any process is equal to it's burst time !
    }

    printf("\nEnter Time Quantum :");
    scanf("%d",&timeQuantum);



   /* for(int i=0;i<n-1;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(arrivalTime[j] < arrivalTime[i])
            {
                    swap(arrivalTime,j,i);
                    swap(burstTime,j,i);
                    swap(remainTime,j,i);
                    swap(pid,j,i);
            }
        }
    }*/
    int j,time=0,x=n;

    for(i=0;x!=0;i++)
    {

        if(arrivalTime[i]<=time)
        {
            if(remainTime[i]>=timeQuantum)
            {
                remainTime[i]=remainTime[i]-timeQuantum;
                time=time+timeQuantum;
                if(remainTime[i]==0)
                {
                    x=x-1;
                    int tat=time-arrivalTime[i];
                    int wait=tat-burstTime[i];
                    printf("p[%d]  |tat  : %d   wait  : %d\n",i+1,tat,wait);
                }
            }
            else if(remainTime[i]!=0 && remainTime[i]<timeQuantum)
            {
                time=time+remainTime[i];
                remainTime[i]=0;
                x=x-1;
                int tat=time-arrivalTime[i];
                int wait=tat-burstTime[i];
                printf("p[%d]  |tat  : %d   wait  : %d\n",i+1,tat,wait);

            }

        }
        if(i==n-1)
          i=-1;

    }

}
