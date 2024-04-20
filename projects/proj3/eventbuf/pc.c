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

int main(int argc, char *argv[]) 
{

    // Parse command line arguments
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <buffer size> <producer count> <consumer count>\n", argv[0]);
        return 1;
    }

    // Initialize the buffer

    // Start producer threads

    // Start consumer threads

    // Wait for all producer threads to finish

    // Notify all consumer threads that there will be no more events

    // Wait for all consumer threads to finish

    // Free the buffer

    return 0;
}