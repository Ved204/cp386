/*
 -------------------------------
 Assignment 2
 File: assignment_average.c
 -------------------------------
 Author:  Mann Patel / Ved Patel
 ID:      210852760 / 210304140
 Email:   pate5276@mylaurier.ca / pate4140@mylaurier.ca
 Version: 2023-06-06
 -------------------------------
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void calculate_average(int matrix[], int i, int j, int lines, int n);

int main(){
    size_t len = 0;
    ssize_t read;
    FILE *fp;
    FILE *file;
    char * line = NULL;
    int number;
    int lines = 0;
    int matrix[MAX_SIZE] = {};
    fp = fopen("sample_in_grades.txt", "r");
    file = fopen("sample_in_grades.txt", "r");

    if (fp == NULL) {
        printf("Error: file pointer is null.");
        return -1;
    }

    int i = 0;
    while (fscanf(fp, "%d", &number) != EOF) {
        matrix[i] = number;
        i++;
    }

    while ((read = getline(&line, &len, file)) != -1) {
        lines++;
    }

    int n = i / lines;

    for (int j = 0; j < n; j++) {
        calculate_average(matrix, i, j, lines, n);
    }

    fclose(fp);

    return 0;
}

void calculate_average(int matrix[], int i, int j, int lines, int n){

    float total = 0;

    for (int k = j; k < i; k += n){
        total += matrix[k];
    }

    total /= lines;

    printf("Assignment %d - Average = %f\n", j+1, total);
}
