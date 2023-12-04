#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define LOCK(m) pthread_mutex_lock(m)
#define UNLOCK(m) pthread_mutex_unlock(m)
#define WAIT(c, m) pthread_cond_wait(c, m)
#define SIGNAL(c) pthread_cond_signal(c)
#define MAX_COUNT 200

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
int count = 0;

void *printEven(void *data)
{
    int tid = *((int *)data);
    while (1)
    {
        LOCK(&lock);

        // wait for this thread's turn
        while (count % 2 == 0)
            WAIT(&condition, &lock);

        // increment count
        if (count < MAX_COUNT)
        {
            count++;
            printf("Thread %d, count %d\n", tid, count);
        }

        // signal the other thread
        SIGNAL(&condition);

        // check if time to exit
        if (count >= MAX_COUNT)
        {
            UNLOCK(&lock);
            return NULL;
        }

        UNLOCK(&lock);
    }
}

void *printOdd(void *data)
{
    int tid = *((int *)data);
    while (1)
    {
        LOCK(&lock);

        // wait for this thread's turn
        if (count % 2 != 0)
            WAIT(&condition, &lock);

        // increment count
        if (count < MAX_COUNT)
        {
            count++;
            printf("Thread %d, count %d\n", tid, count);
        }

        // signal the other thread
        SIGNAL(&condition);

        // check if time to exit
        if (count >= MAX_COUNT)
        {
            UNLOCK(&lock);
            return NULL;
        }

        UNLOCK(&lock);
    }
}

int main(int argc, char **argv)
{
    pthread_t thread1, thread2;
    int tid[] = {1, 2};

    // create threads
    pthread_create(&thread1, NULL, printOdd, &tid[0]);
    pthread_create(&thread2, NULL, printEven, &tid[1]);
    // wait for threads to finish their work
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
