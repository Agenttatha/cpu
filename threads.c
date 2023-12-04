#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *fun1();
void *fun2();
int shared = 1;
int main(){
pthread_t thread1, thread2;
printf("Main thread process ID %d\n", getpid());
pthread_create(&thread1, NULL, fun1, NULL);
pthread_create(&thread2, NULL, fun2, NULL);
pthread_join(thread1, NULL);
pthread_join(thread2, NULL);
printf("In main thread\n");
}
void *fun1(){
        printf("Inside thread 1 with process ID: %d\n", getpid());
        for(int i=0; i<5;i++){
                printf("Thread one i = %d, Shared: %d\n", i, shared++);
                sleep(1);
        }
}
void *fun2(){
        printf("Inside thread 2 with process ID: %d\n", getpid());
        for(int j=0; j<5;j++){
                printf("Thread two j = %d, Shared: %d\n", j, shared++);
                sleep(1);
        }
}
