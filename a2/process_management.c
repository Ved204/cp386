#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    // fork() splits the process into a main process and child process 
    // if int id = fork() == 0 then we are in the child process
    // if int id = fork() != 0 then we are in the main process
    /* for example if we did "fork()" and then "printf("Hello world\n")" in the next line,
       the output of this will not only just be one hello world statement printed, there will be two.
       so, fork doubled the output, it is a 2^n process, so if i had 3 hello world statements, it would
       print hello world 2^3 times (8 times).
    */

    


    return 0;
}
