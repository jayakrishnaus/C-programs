#include<stdio.h>


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
for(i=0;i<n;i++)
{
    printf("For P[%d]: ",i+1);
    scanf("%d",&burstTime[i]);
    remainTime[i]=burstTime[i]; // initially assume remain time for any process is equal to it's burst time !
}

int j,x=n,wait[20],tat[20],k,m;
float rr,large;
for(i=0;x!=0;)
{
  large=0.0;
  rr=0.0;
flag=0;
  for(j=0;j<n;j++)
  {
    if(arrivalTime[j]<=i && remainTime[j]!=0)
    {
      wait[j]=i-arrivalTime[j];

      rr=(float)(wait[j]+burstTime[j])/burstTime[j];

      if(large< rr)
      {
        flag=1;
        large=rr;
        k=j;
      }


    }
}

    if(flag==0)
{

	i=i+1;
}
else{
if(remainTime[k]!=0)
{
    remainTime[k]=0;
    x--;
    i=i+burstTime[k];
    /*if(k==4)
printf("%d%d",arrivalTime[k],i);*/
    tat[k]=i-arrivalTime[k];
    wait[k]=tat[k]-burstTime[k];
    printf("p[%d]  |wait : %d  tat: %d\n",k+1,wait[k],tat[k]);
}
}

  }
}
