#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *threadFunction1(void *arg) 
{
    for (int i = 1; i <= 5; i++) 
    {
        printf("Thread 1: Iteration %d\n", i);
    }
    pthread_exit(NULL);
}
void *threadFunction2(void *arg) 
{
    for (int i = 1; i <= 5; i++) 
    {
        printf("Thread 2: Iteration %d\n", i);
    }
    pthread_exit(NULL);
}
int main() 
{
    pthread_t thread1, thread2;
    if (pthread_create(&thread1, NULL, threadFunction1, NULL) != 0) 
    {
        perror("pthread_create");
        exit(1);
    }
    if (pthread_create(&thread2, NULL, threadFunction2, NULL) != 0) 
    {
        perror("pthread_create");
        exit(1);
    }
    if (pthread_join(thread1, NULL) != 0) 
    {
        perror("pthread_join");
        exit(1);
    }
    if (pthread_join(thread2, NULL) != 0) 
    {
        perror("pthread_join");
        exit(1);
    }
    printf("Both threads have finished.\n");
}
