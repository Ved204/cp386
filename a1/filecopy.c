/*
Assignment 1
Author: Ved Patel
ID:     210304140
Email:  pate4140@mylaurier.ca
*/
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

int main (int argc, char *argv[]) {
    FILE *inputFile, *outputFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    if (!argv[1] || !argv[2]){
        printf("Insuffecient paremeters passed.\n");
        return -1;
    }

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: (fopen) - Error opening input file.\n");
        return 1;
    }

    outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error: (fopen) - Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, inputFile)) > 0) {
        fwrite(buffer, 1, bytesRead, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("The contents of file '%s' has been successfully copied into '%s' file\n",argv[1], argv[2]);
    return 0;
}