#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<unistd.h> 
void * withdraw();
 void * deposite();
 int amount=1; //shared variable
 sem_t s; //semaphore variable
 int main()
 {
 sem_init(&s,0,1); //initialize semaphore variable - 1st argument is address of variable, 2nd is number of processes sharing semaphore, 3rd argument is the initial value of semaphore variable
 pthread_t thread1, thread2;
 int damount,wamount;
 printf("Enter the amount for Deposite");
 scanf("%d",&damount);
 printf("Enter the wthdraw amount");
 scanf("%d",&wamount);
 
 pthread_create(&thread1, NULL, withdraw, (void *)wamount);
 pthread_create(&thread2, NULL, deposite, (void *) damount);
 pthread_join(thread1, NULL);
 pthread_join(thread2,NULL);
 printf("Final value of shared is %d\n",amount); //prints the last updated value of shared variable
 }
void *withdraw()
{
    int x;
    sem_wait(&s); //executes wait operation on s
    x=amount;//thread1 reads value of shared variable
    printf("Thread1 reads the value as %d\n",x);
    x=x+1000;  //thread1 increments its value
    printf("Local updation by Thread1: %d\n",x);
    sleep(1); //thread1 is preempted by thread 2
    amount=x; //thread one updates the value of shared variable
    printf("Value of shared variable updated by Thread1 is: %d\n",amount);    
    sem_post(&s);
}
void *deposite()
{
    int y;
    sem_wait(&s);
    y=amount;//thread2 reads value of shared variable
    printf("Thread2 reads the value as %d\n",y);
    y=y-500;  //thread2 increments its value
    printf("Local updation by Thread2: %d\n",y);
    sleep(1); //thread2 is preempted by thread 1
    amount=y; //thread2 updates the value of shared variable
    printf("Value of shared variable updated by Thread2 is: %d\n",amount);
    sem_post(&s);
}
