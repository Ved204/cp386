/*
Assignment 1
Author: Ved Patel
ID:     210304140
Email:  pate4140@mylaurier.ca
*/

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>

void create_directory(char* directoryName);
void remove_directory(char* directoryName);
void get_working_directory();
void change_directory();
void read_directory();
void close_directory();

int main() {

    char directoryName[250];
    char ans;
    char operations[] = "Select the option(s) appropriately by entering the number:\n Enter 1 for creating a directory\n Enter 2 for removing directory\n Enter 3 for printing working directory\n Enter 4 for changing directory one level up\n Enter 5 for reading the content of directory\n Enter 6 for closing the current directory\nEnter q to exit the program\n";

    while (ans != 'q'){
        printf("%s", operations);
        scanf(" %c", &ans);
        switch(ans)
        {
            case '1':
                printf("Enter the Directory name you want to create: ");
                scanf(" %s", directoryName);
                create_directory(directoryName);
                break;
            case '2':
                printf("Enter the Directory name you want to remove: ");
                scanf(" %s", directoryName);
                remove_directory(directoryName);
                break;
            case '3':
                get_working_directory();
                break;
            case '4':
                change_directory();
                break;
            case '5':
                read_directory();
                break;
            case '6':
                close_directory();
                break;
            case 'q':
                break;
            default:
                printf("Error, incorrect input\n");
        }
    }
    return 0;
}

void create_directory(char* directoryName){
    int success = mkdir(directoryName, 0777);

    if (success == 0) {
        printf("Directory created successfully.\n");
    } else {
        printf("Failed to create the directory.\n");
    }
}

void remove_directory(char* directoryName){
    int success = rmdir(directoryName);

    if (success == 0) {
        printf("Directory removed successfully.\n");
    } else {
        printf("Failed to remove the directory.\n");
    }
}

void get_working_directory(){

    char currentDirectory[1000];
    if (getcwd(currentDirectory, sizeof(currentDirectory)) != NULL) {
        printf("Current working directory is: %s\n", currentDirectory);
    } else {
        perror("getcwd() error\n");
        return;
    }
}

void change_directory(){

    char currentDirectory[1000];
    
    if (chdir("..") == 0) {
        printf("Current directory changed successfully\nWorking Directory After Operation: %s\n", getcwd(currentDirectory, sizeof(currentDirectory)));
    } else {
        printf("Failed to change the current directory.\n");
    }
}

void read_directory(){

    const char* directoryPath = ".";

    DIR* directory;
    struct dirent* entry;

    directory = opendir(directoryPath);
    if (directory == NULL) {
        printf("Failed to open the directory.\n");
        return;
    }

    while ((entry = readdir(directory))) {
        printf("File: %s\n", entry->d_name);
    }
}

void close_directory(){

    DIR* directory;
    directory = opendir(".");
    if (closedir(directory) == 0){
        printf("Directory Closed Successfully\n");
    } else{
    printf("Direcotry Closed Unsuccessfully\n");
    }
}