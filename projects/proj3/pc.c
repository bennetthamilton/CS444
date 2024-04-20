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
int quitting_time = 0; // Flag to indicate that no more events will be produced

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
    int producer_id = *(int *)arg;
    int events_to_produce = *(int *)(arg + 1);

    // Produce events
    for (int i = 0; i < events_to_produce; i++) {
        // Produce an event
        int event_num = producer_id * 100 + i;

        sem_wait(empty);   // Wait for empty slot
        sem_wait(mutex);   // Lock mutex

        // Add event to buffer
        printf("P%d: adding event %d\n", producer_id, event_num);
        eventbuf_add(eb, event_num);    

        sem_post(mutex);   // Unlock mutex
        sem_post(full);    // Signal waiting consumers
    }

    // Print that producer is exiting
    printf("P%d: exiting\n", producer_id);

    return NULL;
}

void *consumer(void *arg)
{
    int consumer_id = *(int *)arg;

    while (!quitting_time) {
        // Consume events

        sem_wait(empty);    // Wait for an event
        sem_wait(mutex);    // Lock mutex

        // Exit if no more events or quitting time
        if (eventbuf_empty(eb) || quitting_time) {   
            sem_post(mutex);
            break;

        } else {  // Get event from buffer
            int event_num = eventbuf_get(eb);
            printf("C%d: got event %d\n", consumer_id, event_num);

            sem_post(mutex);    // Unlock mutex
            sem_post(empty);    // If not done, signal waiting producers
        }
    }

    // Print that consumer is exiting
    printf("C%d: exiting\n", consumer_id);

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
    int producer_args[producer_count * 2]; // ID and number of events for each producer

    for (int i = 0; i < producer_count; i++) {
        // Set arguments
        producer_args[i * 2] = i; 
        producer_args[i * 2 + 1] = event_count; 
        // Create a new thread
        pthread_create(&producer_threads[i], NULL, producer, &producer_args[i * 2]);
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

    // Set quitting time flag
    quitting_time = 1;

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