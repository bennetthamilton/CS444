Project 1: Multithreading
Name: Bennett Hamilton
Collaborators: 
Date: 4/3/24

For this project, the goal is to get a simple multithreaded program running in C.

We're going to learn how to pass information from the main thread into the subthreads. 
Each of those threads will do some work while the main thread waits from them to complete.

Example Run
The program will spawn two threads. Each one will print out its "thread identifier" 
followed by a colon, followed by the numbers 0 to 4.

$ ./hellothread 
Launching threads
thread 1: 0
thread 1: 1
thread 1: 2
thread 2: 0
thread 1: 3
thread 2: 1
thread 2: 2
thread 2: 3
thread 2: 4
thread 1: 4
Threads complete!

The exact order of the output may vary, but it should always begin with 
the Launching threads line and end with the Threads complete! line.