# Project 2: Mutexes

A program that allows brokers to reserve (and unreserve) seats at a venue.

The brokers will be simulated and will be reserving and unreserving seats as fast as they can.

Since the reservation status of all the seats is shared between brokers, we have ample opportunities for race conditions.

You want to write functions to reserve and unreserve seats in such a way that the operations are successful no matter how many brokers are running.

## Building

Command line:

* `make` to build. An executable called `clife` will be produced.
* `make clean` to clean up all build products except the executable.
* `make pristine` to clean up all build products entirely.

VS Code:

* The default build task runs `make`.

## Files

* `reservations.c`: The main code to launch the program

## Data

_[Description of the main data used in the program. Just list the major
data structures—not every variable.]_

There is an 80x24 2D array of Booleans that represents the cells, in
row-major order. Additionally, there's a second parallel array used to
double-buffer during the next generation computation.

If an array element is True, the cell is alive, otherwise it's dead.

There is an array of seats taken. The size is determined by the first argument passed in the command line.
A '1' represents a taken seat while a '0' represents a free seat.

There is an array of brokers which acts as the threads which run the randomized transactions.
The second argument in the command line determines the broker count.

There is a number of transactions represented as a integer value, passed as the third argument in the command line.

## Functions

_[This is a tree of functions and their short descriptions]_

* `main()` : Parses args, init arrays, launches broker threads
* `seat_broker` : Thread function that buys and sells random seats
    * `reserve_seat` : Updates seats array, changes 0 to 1
        * `is_free` : Boolean function that returns true if seat is not taken
    * `free_seat` : Updates seats array, changes 1 to 0
        * `is_free` : Boolean function that returns true if seat is not taken
    * `verify_seat_count` : Verifies 
        * `is_free` : Boolean function that returns true if seat is not taken

## Notes

* `^C` to quit.