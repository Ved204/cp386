#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(FILE *file){

    FILE *fp;
    char * line = NULL;
    fp = fopen(file, "r");
    int lines = 0;
    int matrix[] = {};
    size_t len = 0;
    ssize_t read;

    if (fp == NULL) {
        printf("Error: file pointer is null.");
        return -1;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);
    }

    fclose(fp);

}