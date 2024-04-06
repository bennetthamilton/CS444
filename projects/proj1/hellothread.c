// Title: Project 1: Multithreading
// Name: Bennett Hamilton
// Collaborators: 
// Date: 4/3/24
// Description: a simple multithreaded program running in C. 
//              The program will spawn two threads. Each one 
//              will print out its "thread identifier" followed 
//              by a colon, followed by the numbers 0 to 4.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2
#define NUM_ITERATIONS 5

void *print_numbers(void *thread_name) {
    char *name = (char *)thread_name;
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        printf("%s: %d\n", name, i);
        fflush(stdout); // output is flushed immediately
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    char *thread_names[NUM_THREADS] = {"thread 1", "thread 2"};

    printf("Launching threads\n");

    for (int i = 0; i < NUM_THREADS; i++) {
        int result = pthread_create(&threads[i], NULL, print_numbers, (void *)thread_names[i]);
        if (result != 0) {  // check for error
            fprintf(stderr, "Error creating thread %d\n", i + 1);
            return 1; 
        }
    }

    // wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Threads complete!\n");

    return 0;
}