#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of processes :> ");
    scanf("%d",&n);
    int process[n],burst[n],gant[n],priority[n],i,j,temp1,temp2;
    gant[0]=0;
    float avg_wt=0,avg_tat=0;
    for(i=0;i<n;i++)
    {
        process[i]=i+1;
        printf("Enter the burst time for processes %d :> ",process[i]);
        scanf("%d %d",&burst[i],&priority[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(priority[j]<priority[i])
            {
                temp1 = priority[i];
                priority[i] = priority[j];
                priority[j] = temp1;
                temp2 = burst[i];
                burst[i] = burst[j];
                burst[j] = temp2;
            }
        }
    }
    for(i=0;i<n;i++)
   { 
     if(i==0)
    {
        gant[i]=gant[i]+burst[i];
        avg_wt=0;
        avg_tat=gant[i];
    }
    else 
    {
        gant[i]=gant[i-1]+burst[i];
        avg_wt=avg_wt+gant[i-1];
        avg_tat=avg_tat+gant[i];
    }
    }
   avg_wt=(float)avg_wt/n;
   avg_tat=(float)avg_tat/n;
   printf("\nAverage waiting time :-> %.2f",avg_wt);
   printf("\nAverage turn aroung time :-> %.2f",avg_tat);
}