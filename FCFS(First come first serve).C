#include<stdio.h>
int main()
{
   int n;
   printf("\nEnter the number of process :-> ");
   scanf("%d",&n);
   int Process[n],Burst[n];
   int Gant[n],i;
   Gant[0]=0;
   float avg_wt=0,avg_tat=0;
   for(i=0;i<n;i++)
   {
       Process[i]=i+1;
       printf("\nEnter the Burst time for Process %d :-> ",Process[i]);
       scanf("%d",&Burst[i]);
   }
   for(i=0;i<n;i++)
   { 
     if(i==0)
    {
        Gant[i]=Gant[i]+Burst[i];
        avg_wt=0;
        avg_tat=Gant[i];
    }
    else 
    {
        Gant[i]=Gant[i-1]+Burst[i];
        avg_wt=avg_wt+Gant[i-1];
        avg_tat=avg_tat+Gant[i];
    }
    }
   avg_wt=(float)avg_wt/n;
   avg_tat=(float)avg_tat/n;
   printf("\nAverage waiting time :-> %.2f",avg_wt);
   printf("\nAverage turn aroung time :-> %.2f",avg_tat);
}