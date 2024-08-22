#include <stdio.h>
#include <stdlib.h>

#include "headers/intepreter.h"
#include "headers/memory.h"

/*
    Current Argument Setup
    1. Memory
    2. Executable file (VRE binary format)
    3+. File parameters
*/

int main(int argc, char *argv[]){
    //Init
    int* memory = NULL; // Initialize to NULL
    int code; //error code the intepreter returns

    //Print Parameters
    printf("Starting VRE with following parameters:\n");
    for(int i = 1; i < argc; i++){
        if (i == 1){
            printf("    Memory:             %s bytes\n", argv[i]);
        } else if (i == 2){
            printf("    Executable File:    %s\n", argv[i]);
        } else {
            printf("    P.%d:                %s\n", i, argv[i]);
        }
    }
    //Trigger a failsafe incase arg1 or arg2 arent specified
    if (argc < 1 || argc < 2){
        printf("Not enough arguments presented. Exiting...\n");
        return 3;
    }
    //Allocate memory the VRE is going to use
    printf("Allocating memory\n");
    int memsize = atoi(argv[1]);
    if (memsize > 0){
        //Would be kinda silly if anything bad happened xd
        int *memory = malloc(memsize);
        if (memory == NULL){
            printf("Unable to allocate memory, exiting environment\n");
            return 1;
        }
    } else {
        printf("Error allocating memory");
        return 2;
    }

    //Lets Read the file and output its binary content
    code = loadFile(argv[2], memsize, &memory); //This is so gonna memory leak ngl
    if (code > 0){
        printf("An error occured with the intepreter. Exiting...");
        return code;
    }

    //Free memory before exiting
    printf("Freeing memory\n");
    free(memory); //This code saves lifes
    printf("Exiting...\n"); //stop forgetting newlines you silly billy              
    return 0;
}