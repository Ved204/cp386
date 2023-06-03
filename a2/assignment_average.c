#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

    FILE *fp;
    FILE *input;
    char * line = NULL;
    fp = fopen("sample_in_grades.txt", "r");
    int lines = 0;
    int matrix[] = {};
    size_t len = 0;
    ssize_t read;

    if ((input = fopen(argv[1], "r")) == NULL) {
        printf("Error: (fopen) - Error opening input file.\n");
        return 1;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("%s", line);
    }

    fclose(fp);

}