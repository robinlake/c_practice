#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

/*
Assignment requirements:
- Create a program that gives reader threads priority over writer threads concerning a shared variable dfgfdgd
- foo



Todo:
- create 
*/

int sharedValue = 0;
int numReaders = 5;
int numWriters = 5;
int activeReaders = 0;
int activeWriters = 0;
pthread_mutex_t readMutex; 
pthread_mutex_t writeMutex; 
pthread_cond_t isWriting;
pthread_cond_t isReading;

void *readRoutine()
{
    int value = (rand() % 3) + 1;
    sleep(value);
    pthread_mutex_lock(&writeMutex);
    activeReaders +=1;
    while (activeWriters > 0) {
        pthread_cond_wait(&isWriting, &writeMutex);
    }
    printf("got shared value: %d\n", sharedValue);
    printf("Number of readers: %d\n", activeReaders);
    activeReaders -=1;
    pthread_mutex_unlock(&writeMutex);
    if (activeReaders == 0) {
        pthread_cond_signal(&isReading);
    }
}

void *writeRoutine()
{
    int value = (rand() % 3) + 1;
    sleep(value);
    pthread_mutex_lock(&writeMutex);
    while(activeReaders > 0) {
        pthread_cond_wait(&isReading, &writeMutex);
    }
    activeWriters += 1;
    sharedValue += 1;
    printf("Shared value writer = %d\n", sharedValue);
    printf("Number of readers: = %d\n", activeReaders);
    pthread_mutex_unlock(&writeMutex);
    activeWriters -= 1;
    pthread_cond_signal(&isWriting);
}

int main(int argc, char *argv[])
{
    pthread_t r[5];
    pthread_t w[5];
    pthread_mutex_init(&writeMutex, NULL);
    pthread_cond_init(&isWriting, NULL);
    pthread_cond_init(&isReading, NULL);

    for(int i = 0; i < numReaders; i++) {
        if (pthread_create(r + i, NULL, &readRoutine, NULL) != 0) {
            perror("Failed to create reader thread");
            return 1;
        }
    }
    for(int i = 0; i < numWriters; i++) {
        if (pthread_create(w + i, NULL, &writeRoutine, NULL) != 0) {
            perror("Failed to create writer thread");
            return 2;
        }
    }
    for(int i = 0; i < numReaders; i++) {
        if (pthread_join(r[i], NULL) != 0){
            return 3;
        }
    }
    for(int i = 0; i < numWriters; i++) {
        if (pthread_join(w[i], NULL) != 0){
            return 3;
        }
    }
    pthread_mutex_destroy(&writeMutex);
    pthread_cond_destroy(&isWriting);
    pthread_cond_destroy(&isReading);
    return 0;
}
