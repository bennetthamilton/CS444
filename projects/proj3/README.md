# Project 3: Producers and Consumers

_[Title and Description]_

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

_[Description of the main data used in the program. Just list the major
data structures—not every variable.]_

There is an 80x24 2D array of Booleans that represents the cells, in
row-major order. Additionally, there's a second parallel array used to
double-buffer during the next generation computation.

If an array element is True, the cell is alive, otherwise it's dead.

## Functions

_[This is a tree of functions and their short descriptions]_

* `main()`
  * `init()`
    * `life_init()`: Initializes the cell array to random 
      * `grid_alloc()`: Allocate space for the cell grid
      * `randomize()`: Randomize the contents of the cell grid
    * `display_init()`: Initializes the display
      * `clear_screen()`
  * `run()`: Main game running routine
    * `life_update()`: Update cell data
      * `update_cell()`: updates a cell based on its neighbors
        * `get_neighbor_count()`: counts neighbors for a cell
    * `life_get_cells()`: Get cell status
    * `display_update()`: Display cells
      * `home_cursor()`
    * `delay()`: Delay between frames
  * `life_shutdown()`: Call before destruction (currently unreachable)
    * `grid_free()`: Free cell grid memory

## Notes

* `^C` to quit.