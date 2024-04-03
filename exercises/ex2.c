// libraries
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// constants
#define NUM_ELEMENTS 10000
#define NUM_THREADS 4

// make a global array of 10000 integers
int arr[NUM_ELEMENTS] = {0};

// increment each element of the array by 1
void *increment(void *arg) {
    // cast the argument to an integer
    int index = (int)arg;
    // increment the element at the index
    arr[index]++;
    // return NULL
    return NULL;
}

//main function
int main(void) {

    // declare a thread
    pthread_t thread[NUM_THREADS];

    // launch threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(thread + 1, NULL, increment, (void *)i);
    }

    // join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread[i], NULL);
    }

    // get expected
    int expected = NUM_THREADS;

    // get actual and print
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        if (arr[i] != expected) {
            printf("arr[%d] = %d\n", i, arr[i]);
        }
    }

    return 0;
}
