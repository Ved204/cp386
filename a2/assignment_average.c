#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fp;
    FILE *input;
    char * line = NULL;
    int number;
    int lines = 0;
    int matrix[] = {};
    fp = fopen("sample_in_grades.txt", "r");

    if (fp == NULL) {
        printf("Error: file pointer is null.");
        return -1;
    }

    while (fscanf(fp, "%d", &number) != EOF) {
        // Process the number here (e.g., print it)
        printf("%d\n", number);
    }

    fclose(fp);

}