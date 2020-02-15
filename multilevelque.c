#include<stdio.h>
#include<stdlib.h>
void main()
{



    int i,burstTime[20],remainTime[20],remainProcess,arrivalTime[20],totalExecutionTime=0,timeQuantum,flag=0,n,pid[20];
    float totalWaitingTime=0;

printf("Enter the details for rr shed priority-1\n");
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
    printf("enter the details for srtf priority-2\n");
    int m;
    printf("Enter the number of proess:\n" );
    scanf("%d",&m);
    int burst[10],dburst[10],arrival[10],wait[20],tat[20];
    for(int i=0;i<m;i++)
    {
    printf("Enter the pid arrival and burst of p%d: ",i+1);
    scanf("%d%d",&arrival[i],&burst[i]);
    dburst[i]=burst[i];
    wait[i]=0;
    tat[i]=0;
    }



//r-r
printf("\nROUND-ROBIN\n");
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
else
time++;
    if(i==n-1)
      i=-1;

}




//srtf
printf("\n\n\tSRTF\n");
int t;

for(int i=0;i<m;i++)
{
dburst[i]=burst[i];
}

printf("\n\n\t\t\t  PID\n\n");
int k=11,l,s,c=0,cont=0,idl=0;

for(i=time;c<n;i++)
{
   s=11;
    l=100;

    for(j=0;j<n;j++)
    {

      if(arrival[j]<=i && dburst[j]>0)
      {
          if(dburst[j]<l)
          {
              l=dburst[j];
              s=j;
          }
      }

    }


    if(s!=k)
    {
        cont++;
        k=s;
    }
    if(s!=11)
    {

    dburst[s]=dburst[s]-1;
    printf("p%d   ",s+1);
    }
    else
    {
        idl++;
    }


    if(dburst[s]==0)
    {

        tat[s]=i-arrival[s]+1;
        wait[s]=tat[s]-burst[s];
        c=c+1;
    }

}

for(i=0;i<m;i++)
{
printf("\nwaiting and tat of process p%d= %d  %d",i+1,wait[i],tat[i]);

}
printf("\n\ncontext switching: %d", cont-1);
printf("\ncpu idle time : %d",idl);
}
