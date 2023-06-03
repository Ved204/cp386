#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int main(){

    FILE *fp;
    FILE *input;
    char * line = NULL;
    int number;
    int lines = 0;
    int matrix[MAX_SIZE] = {};
    fp = fopen("sample_in_grades.txt", "r");

    if (fp == NULL) {
        printf("Error: file pointer is null.");
        return -1;
    }

    int i = 0;
    while (fscanf(fp, "%d", &number) != EOF) {
        // Process the number here (e.g., print it)
        // printf("%d\n", number);
        matrix[i] = number;
        i++;
    }

    for (int j = 0; j < i; j++) {
        printf("%d ", matrix[j]);
    }

    fclose(fp);

    return  0;
}