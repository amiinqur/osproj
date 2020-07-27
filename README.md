# MultiThread osproj
Conways game of Life
#HCI 104497: Conway Game of Life - An OS course project#
###PROJECT MEMBERS###
StdID | Name
------------ | -------------
**63855** | **Amin M. Quraishi** <!--this is the group leader in bold-->
63856 | Muhammad Ahmed Quraishi
<!-- Replace name and student ids with acutally group member names and ids-->
## Approach ##
Implementing multi threading in our project was a very tough job, but we did it at last. We made some major changes in our code from single thread. We changed it in this way that the number of threads will decide how many generations will the program run for instead of the generation variable deciding that. We removed the for loop which ran until the number of generations instead now the thread process will run the number of times the threads are called. We also moved the writing process into the output file into the main scope instead of the thread like in previous single thread code. 
We evalauted the time taken with various number of threads. 
Time Taken: 2 mins - 3 Threads
Time Taken: 1.5 mins - 4 Threads.

## Problems Faces ##

Problem 1:Input file was not getting detected
The first problem we faced was that our input file was not opening and instead we were getting segmentation fault error. We looked into the problem and we found that our file was not in the same location as our project file. We changed the location of the file and it started working.

Problem 2: The array data was not transferring from main scope to our thread
We faced several issued when we tried to move the array from main to our thread. The values of the array in the main scope were not movving to the array in our thread. Finally we trien typecasting with our create struct and it worked. We successfully got our array values from main scope to our thread.

Problem 3: Unable to read data from input file
Evem after our program successfully detected the input file we were getting error while reading from the input file into our array. We first tried fgetc() command to read from file but it read the whole array as a single character but then we tried the commad fscanf() and then we were able to read invidual values from the whole array in the file.

Problem 4: Problem in continuation of generations between threads
With multiple threads the generations was not continuing instead the same generation was being printed again and again. To overcome this problem we made two global array variable in the beginning which helped us store the value of generation of every thread and in this way the generations continued without any issue and in the end the final state was printed into the output file. 

##References##
- https://rosettacode.org/wiki/Conway%27s_Game_of_Life
- https://www.cs.utexas.edu/users/djimenez/utsa/cs1713-3/c/life.txt
- https://bitstorm.org/gameoflife/
