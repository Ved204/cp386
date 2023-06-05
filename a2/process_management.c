#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    // fork() function splits the process into a main process and child process 
    // if int id = fork() == 0 then we are in the child process
    // if int id = fork() != 0 then we are in the main process
    /* for example if we did "fork()" and then "printf("Hello world\n")" in the next line,
       the output of this will not only just be one hello world statement printed, there will be two.
       so, fork doubled the output, it is a 2^n process, so if i had 3 hello world statements, it would
       print hello world 2^3 times (8 times).
    */

    // wait() function stops the execution of main process until a child process has finished executing
    // after child process has finished executing, the main process will continue
    // the function is very helpful when you try to print parts of things from one process and part of things from another process
    // in an ordered manner 



    return 0;
}
