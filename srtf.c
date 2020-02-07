#include<stdio.h>
#include<stdlib.h>


void main()
{
    printf("Enter the Number of process:");
    int n;
    int tat[20],wait[20],pid[10];
    scanf("%d",&n);
    int burst[10],dburst[10],arrival[10];
    for(int i=0;i<n;i++)
    {
    printf("Enter the pid arrival and burst of p%d: ",i+1);
    scanf("%d%d",&arrival[i],&burst[i]);
    dburst[i]=burst[i];
    wait[i]=0;
    tat[i]=0;
    }
    int t;

for(int i=0;i<n;i++)
{
    dburst[i]=burst[i];
}

printf("\n\n\t\t\t  PID\n\n");
    int i,j,k=11,l,s,c=0,cont=0,idl=0;

    for(i=0;c<n;i++)
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

for(i=0;i<n;i++)
{
    printf("\nwaiting and tat of process p%d= %d  %d",i+1,wait[i],tat[i]);

}
printf("\n\ncontext switching: %d", cont-1);
printf("\ncpu idle time : %d",idl);
}
