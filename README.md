# osproj
Conways game of Life
#HCI 104497: Conway Game of Life - An OS course project#
###PROJECT MEMBERS###
StdID | Name
------------ | -------------
**63855** | **Amin M. Quraishi** <!--this is the group leader in bold-->
63855 | Muhammad Ahmed Quraishi
<!-- Replace name and student ids with acutally group member names and ids-->
## Approach ##
Our goal was to create a program that could successfuly replicate the Conway Game of Life. We looked upon different resources and references on the internet, but in the end we used the basic approach of FOR loops and IF-ELSE conditions. We passed parameters to our thread using struct because there were multiple arguments that needed to be passed otherwise we would have simply directly passed it without any struct. We also used pointer character arrays to store and print data. We used FILE related commands to read and write data from the files. We had two files input.txt and output.txt to read from and write into. We used the following libraries:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
All these libraries assisted us in successfully executing our code. The input file, number of generations and the window size were taken by command line parameters. We used fprintf to print data into out file and fscanf to read data from our file into an array, so that we can use the array for our program.

## Problems Faces ##

###Problem 1: Input file was not getting detected###
The first problem we faced was that our input file was not opening and instead we were getting segmentation fault error. We looked into the problem and we found that our file was not in the same location as our project file. We changed the location of the file and it started working.

###Problem 2: The array data was not transferring from main scope to our thread###
We faced several issued when we tried to move the array from main to our thread. The values of the array in the main scope were not movving to the array in our thread. Finally we trien typecasting with our create struct and it worked. We successfully got our array values from main scope to our thread.

###Problem 3: Unable to read data from input file###
Evem after our program successfully detected the input file we were getting error while reading from the input file into our array. We first tried fgetc() command to read from file but it read the whole array as a single character but then we tried the commad fscanf() and then we were able to read invidual values from the whole array in the file.

##References##
- https://rosettacode.org/wiki/Conway%27s_Game_of_Life
- https://www.cs.utexas.edu/users/djimenez/utsa/cs1713-3/c/life.txt
- https://bitstorm.org/gameoflife/
