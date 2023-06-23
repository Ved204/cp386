/*
 -------------------------------
 Assignment 3
 File: fcfs.c
 -------------------------------
 Author:  Mann Patel / Ved Patel
 ID:      210852760 / 210304140
 Email:   pate5276@mylaurier.ca / pate4140@mylaurier.ca
 Version: 2023-06-23
 -------------------------------
*/
#include <stdio.h>
#include <stdlib.h>


int main(){
    /* 
    Program should use first come first serve scheduling algorithm to calculate 
    completion time, turn-around time, waiting time, average waiting time, and average turn-around time.
    */
    // Completion time (first thread) = Burst time of thread 
    // Completion time of rest of threads = Burst time of current thread + Completion time of previous thread
    // Turn-around time = Completion time of thread - Arrival time of thread
    // Waiting time = Turn-around time - Burst time of thread 
    // Average waiting time = sum of all threads' waiting time / sum of number of threads
    // Average turn-around time = sum of all threads' turn-around time / sum of number of threads 


    return 0;
}