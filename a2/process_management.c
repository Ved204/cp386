/*
 -------------------------------
 Assignment 2
 File: process_management.c
 -------------------------------
 Author:  Mann Patel / Ved Patel
 ID:      210852760 / 210304140
 Email:   pate5276@mylaurier.ca / pate4140@mylaurier.ca
 Version: 2023-06-06
 -------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <fcntl.h>

void writeOutput(char*, char*);


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

    int mem;
    char* str;
    pid_t parent_id;
    pid_t parent_id2;

    if (argc != 2){
        printf("Error, no file provided\n");
        return -1;
    }

    mem = shm_open("/shared_memory", O_CREAT | O_RDWR, 0666);
    str = mmap(NULL, 4096, PROT_WRITE | PROT_READ, MAP_SHARED, mem, 0);

    if (mem == -1){
        perror("shared_memory_open");
        exit(1);
    }
    if (str == MAP_FAILED){
        perror("map");
        exit(1);
    }
    if (ftruncate(mem, 4096) == -1){
        perror("ftruncate");
        exit(1);
    }

    int pip[2];

    if (pipe(pip) == -1){
        perror("pipe");
        exit(1);
    }

    parent_id = fork();

    if (parent_id == 0){
        char buffer[4096];
        int length;
        int file_directory = open("sample_in_process.txt", O_RDONLY);

        if (file_directory == -1){
            perror("open_error");
            exit(1);
        }
        while ((length = read(file_directory, buffer, 4096)) > 0){
            strncpy(str, buffer, length);
            str[length] = '\0';
        }

        close(file_directory);
        exit(0);
    }
    else if (parent_id > 0){
        wait(NULL);
        parent_id2 = fork();

        if (parent_id2 == 0){
            int file_directory = open("sample_in_process.txt", O_RDONLY);

            if (file_directory == -1){
                perror("open_error");
                exit(1);
            }

            dup2(pip[1], STDOUT_FILENO);
            close(pip[0]);
            close(pip[1]);

            char* args[] = {"sh", "-c", str, NULL};
            execvp(args[0], args);
            exit(0);
        }
        else if (parent_id2 > 0){
            wait(NULL);

            close(pip[1]);
            char buffer[4096];
            int length;

            while ((length = read(pip[0], buffer, 4096)) > 0){
                writeOutput(str, buffer);
            }
        }
    }

    return 0;
}

void writeOutput(char* command, char* output){
    FILE* fp;
    fp = fopen("output.txt", "a");
    fprintf(fp, "The output of: %s : is\n", command);
    fprintf(fp, ">>>>>>>>>>>>>>>\n%s<<<<<<<<<<<<<<<\n", output);
    fclose(fp);
    return;
}
