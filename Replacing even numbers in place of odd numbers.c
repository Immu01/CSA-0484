#include<stdio.h>
void processmethod(int a[],int n ,  int i);
int main ()
{
    int n , a[100] , i ;
    printf("enter the no.of integers in an array :");
    scanf("%d" , &n);
    printf("enter the integers in an array :");
    for ( i = 0 ; i < n ; i++)
    {
        scanf("%d" , &a[i]);
    }
    processmethod(a,n,i);
    printf("the result array :");
    for ( i = 0 ; i < n ; i++)
    {
        printf("%d" , a[i]);
    }
    
}
void processmethod( int a[] , int n ,  int i)
{
    for ( i =0 ; i < n ; i++)
    {
        if (a[i] %2 != 0)
        {
            a[i] = a[i] + 1;
        }
    }
}