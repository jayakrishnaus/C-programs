#include<stdio.h>
void main()
{
int n;
printf("Enter the number of proess:");
scanf("%d",&n);
int burst[20],arrival[20],remain[20],aw=0,at=0;
printf("Enter the arrival times:\n");
for(int i=0;i<n;i++)
{
printf("p[%d] : ",i+1);
scanf("%d",&arrival[i]);
}


for(int i=0;i<n;i++)
{
printf("p[%d] : ",i+1);
scanf("%d",&burst[i]);
remain[i]=burst[i];
}


int time=0,i,j,x=n;
for(;x>0;)
{
int smallest=100;
int k=0;
int flag=0;
for(j=0;j<n;j++)
{
if(arrival[j]<=time && remain[j]!=0)
{
if(smallest>burst[j])
{
smallest=burst[j];
k=j;
flag=1;
}
}
}
if(flag==0)
time++;
else
{
time=time+burst[k];
remain[k]=0;
at +=time-arrival[k];
aw +=time-arrival[k]-burst[k];
printf("\np[%d]  |wait: %d  tat: %d  ",k+1,time-arrival[k]-burst[k],time-arrival[k]);
x=x-1;
}
}
printf("\nAverage tat: %f",(float)at/n);
printf("\nAverage wait: %f", (float)aw/n);
printf("\nNumber of context switch: %d",n-1);
}
