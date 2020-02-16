#include<stdio.h>



void swap(int a[],int j,int i)
{
int t;
t=a[j];
a[j]=a[i];
a[i]=t;
}

void main()
{
int n;
printf("Enter the number of proess:");
scanf("%d",&n);
int burst[20],arrival[20],remain[20],aw=0,at=0,prio[20],pid[20];
printf("Enter the arrival times:\n");
for(int i=0;i<n;i++)
{
printf("p[%d] : ",i+1);
scanf("%d",&arrival[i]);
pid[i]=i+1;
}

printf("Enter the burst time:\n");
for(int i=0;i<n;i++)
{
printf("p[%d] : ",i+1);
scanf("%d",&burst[i]);
remain[i]=burst[i];
}

printf("Enter the priority:\n");
for(int i=0;i<n;i++)
{
printf("p[%d] :  ",i+1);
scanf("%d",&prio[i]);
}


for(int i=0;i<n-1;i++)
{
for(int j=i;j<n;j++)
{
if(prio[j]>prio[i])
{
swap(prio,j,i);
swap(burst,j,i);
swap(arrival,j,i);
swap(remain,j,i);
swap(pid,j,i);
}
}
}

for (int i=0;i<n;i++)
printf("\n%d",prio[i]);

int i,j,x=n,time=0,flag=0;
for(i=0;x>0;i++)
{
if(arrival[i]<=time && remain[i]!=0)
{
remain[i]=0;
time+=burst[i];
aw+=time-arrival[i]-burst[i];
at +=time-arrival[i];
x--;

printf("\np[%d]  |wait : %d  tat: %d",pid[i],time-arrival[i]-burst[i],time-arrival[i]);
flag=1;
i=-1;
}

if(i==n-1)
{
if(flag==0)
time++;
flag=0;
i=-1;
}
}
printf("\nAverage wait: %f", (float)aw/n);
printf("\nAverage tat : %f", (float)at/n);
printf("\nContext switch: %d", n-1);
}
