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

typedef struct {
    int thread_id;
    int arrival_time;
    int burst_time;
} thread;


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

    FILE *fp = fopen("sample_in_schedule.txt", "r");

    if (fp == NULL){
        printf("Error: (fopen) - Error opening file.\n");
        return -1;
    }

    int num = 0;
    thread thread_array[100];

    while(fscanf(fp, "%d,%d,%d", &thread_array[num].thread_id, &thread_array[num].arrival_time, &thread_array[num].burst_time) == 3){
        num++;
    }

    fclose(fp);

    int total_turn_around_time = 0;
    int total_wait_time = 0;
    int completion_time = 0;
    double average_wait_time;
    double average_turn_around_time;

    printf("Thread ID \t Arrival Time \t Burst Time \t Completion Time \t Turn-Around Time \t Waiting Time\n");

    for (int i = 0; i < num; i++){
        completion_time += thread_array[i].burst_time;
        int turn_around_time = completion_time - thread_array[i].arrival_time;
        int wait_time = turn_around_time - thread_array[i].burst_time;
        total_wait_time += wait_time;
        total_turn_around_time += turn_around_time;
        
        printf("%d \t %d \t %d \t %d \t %d \t %d\n", thread_array[i].thread_id, thread_array[i].arrival_time, thread_array[i].burst_time, completion_time, turn_around_time, wait_time);
    }

    average_wait_time = (double) total_wait_time/num;
    average_turn_around_time = (double) total_turn_around_time/num;

    printf("The average waiting time: %.2f\n", average_wait_time);
    printf("The average turn-around time: %.2f\n", average_turn_around_time);
    return 0;
}