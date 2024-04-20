// Title: Project 3: Producers and Consumers
// Name: Bennett Hamilton
// Collaborators: Ashley Doerfler
// Date: 4/20/24
// Description: A C program using semaphores that allows producers to add 
//              events to a buffer and consumers to remove events from the buffer.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include "eventbuf.c"

// Global variables
struct eventbuf *eb;
sem_t *empty, *full, *mutex;

sem_t *sem_open_temp(const char *name, int value)
{
    sem_t *sem;

    // Create the semaphore
    if ((sem = sem_open(name, O_CREAT, 0600, value)) == SEM_FAILED)
        return SEM_FAILED;

    // Unlink it so it will go away after this process exits
    if (sem_unlink(name) == -1) {
        sem_close(sem);
        return SEM_FAILED;
    }

    return sem;
}

void *producer(void *arg)
{
    // Produce events

    return NULL;
}

void *consumer(void *arg)
{
    // Consume events

    return NULL;
}

int main(int argc, char *argv[]) 
{

    // Parse command line arguments
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <buffer size> <producer count> <consumer count>\n", argv[0]);
        return 1;
    }

    // Define arguments
    int producer_count = atoi(argv[1]);
    int consumer_count = atoi(argv[2]);
    int event_count = atoi(argv[3]);
    int max_event = atoi(argv[4]);

    // Initialize the buffer
    eb = eventbuf_create();

    // Initialize semaphores
    empty = sem_open_temp("/empty", event_count);
    full = sem_open_temp("/full", 0);
    mutex = sem_open_temp("/mutex", 1);

    // Start producer threads
    pthread_t producer_threads[producer_count];

    for (int i = 0; i < producer_count; i++) {
        // Create a new thread
        pthread_create(&producer_threads[i], NULL, producer, (void *)&i);
    }

    // Start consumer threads
    pthread_t consumer_threads[consumer_count];

    for (int i = 0; i < consumer_count; i++) {
        // Create a new thread
        pthread_create(&consumer_threads[i], NULL, consumer, (void *)&i);
    }

    // Wait for all producer threads to finish
    for (int i = 0; i < producer_count; i++) {
        pthread_join(producer_threads[i], NULL);
    }

    // Notify all consumer threads that there will be no more events
    for (int i = 0; i < consumer_count; i++) {
        sem_post(full);
    }

    // Wait for all consumer threads to finish
    for (int i = 0; i < consumer_count; i++) {
        pthread_join(consumer_threads[i], NULL);
    }

    // Clean up
    eventbuf_free(eb);
    sem_close(empty);
    sem_close(full);
    sem_close(mutex);

    return 0;
}