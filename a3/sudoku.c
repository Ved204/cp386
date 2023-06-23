#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 9
#define THREADS_SIZE 27

int sudoku[SIZE][SIZE];
int valid = 1;

typedef struct {
    int row;
    int column;
} parameters;

void *check(void *arg) {
    parameters *data = (parameters *)arg;

    if (data->row != -1 && data->column != -1) {
        int temp[SIZE] = {0};
        int currentrow = data->row;
        int currentcolumn = data->column;

        for (int i = currentrow; i < currentrow + 3; i++) {
            for (int j = currentcolumn; j < currentcolumn + 3; j++) {
                int num = sudoku[i][j];
                if (temp[num - 1] == 0) {
                    temp[num - 1] = 1;
                } else {
                    valid = 0;
                    pthread_exit(NULL);
                }
            }
        }
    } else if (data->row != -1) {
        int row = data->row;
        int temp[SIZE] = {0};

        for (int i = 0; i < SIZE; i++) {
            int num = sudoku[row][i];
            if (temp[num - 1] == 0) {
                temp[num - 1] = 1;
            } else {
                valid = 0;
                pthread_exit(NULL);
            }
        }
    } else if (data->column != -1) {
        int col = data->column;
        int temp[SIZE] = {0};

        for (int i = 0; i < SIZE; i++) {
            int num = sudoku[i][col];
            if (temp[num - 1] == 0) {
                temp[num - 1] = 1;
            } else {
                valid = 0;
                pthread_exit(NULL);
            }
        }
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS_SIZE];
    parameters rc[THREADS_SIZE];
    int index = 0;
    FILE *f = fopen("sample_in_sudoku.txt", "r");
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (fscanf(f, "%d", &sudoku[i][j]) != 1) {
                fprintf("Failed to read Sudoku puzzle from file.\n");
                fclose(f);
                return 1;
            }
        }
    }

    fclose(f);

    for (int i = 0; i < SIZE; i++) {
        rc[index].row = i;
        rc[index].column = -1;
        if (pthread_create(&threads[index], NULL, check, &rc[index]) != 0) {
            return 1;
        }
        index++;
    }

    for (int i = 0; i < SIZE; i++) {
        rc[index].row = -1;
        rc[index].column = i;
        if (pthread_create(&threads[index], NULL, check, &rc[index]) != 0) {
            return 1;
        }
        index++;
    }

    for (int i = 0; i < SIZE; i += 3) {
        for (int j = 0; j < SIZE; j += 3) {
            rc[index].row = i;
            rc[index].column = j;
            if (pthread_create(&threads[index], NULL, check, &rc[index]) != 0) {
                return 1;
            }
            index++;
        }
    }

    for (int i = 0; i < THREADS_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Sudoku Puzzle Solution:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }

    if (valid) {
        printf("Sudoku puzzle is valid.\n");
    } else {
        printf("Sudoku puzzle is invalid.\n");
    }

    return 0;
}