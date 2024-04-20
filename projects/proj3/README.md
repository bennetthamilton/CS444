# Project 3: Producers and Consumers

Practice implementing the Producer and Consumer Model using semaphores.

The producers will add "events" to a queue, and the consumers will remove them. (In this case, our "events" are just integers.)

When the producers are done, the main thread should signal the consumers to exit.

Each producer is its own thread. Each consumer is its own thread.

All producers will have the same producer run function.
All consumers will have the same consumer run function.

## Building

Command line:

* `make` to build. An executable called `pc` will be produced.

## Files

* `pc.c`: The main code to run the program
* `eventbuf.c`: Function for event buffer semaphore
* `eventbuf.h`: Instructions for event buffer functions

## Data

There are four commandline arguments: `Number of producers`, `Number of consumers`, `How many events each producer will generate`, and `How many outstanding events there can be at a time`

## Functions

* `main()`: Runs the program, initializes threads and semaphores, calls thread functions 
  * `sem_open_temp`: Creates a semaphore.
  * `producers`: Produces an event.
  * `consumers`: Consumes an event.

## Notes

* `^C` to quit.
* example output: 

  ./pc 2 4 5 2

  P0: adding event 0
  P1: adding event 100
  C0: got event 0
  P0: adding event 1
  C0: got event 100
  C1: got event 1
  P1: adding event 101
  P0: adding event 2
  C2: got event 101
  C3: got event 2
  P0: adding event 3
  P1: adding event 102
  C0: got event 3
  C1: got event 102
  P0: adding event 4
  P1: adding event 103
  P0: exiting
  C2: got event 4
  C3: got event 103
  P1: adding event 104
  P1: exiting
  C1: got event 104
  C2: exiting
  C0: exiting
  C3: exiting
  C1: exiting