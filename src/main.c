#include <stdio.h>
#include <stdlib.h>

/*
    Current Argument Setup
    1. Memory
    2. Executable file (VRE binary format)
    3+. File parameters
*/

int main(int argc, char *argv[]){
    //Print Parameters
    printf("Starting VRE with following parameters:\n");
    for(int i = 1; i < argc; i++){
        if (i == 1){
            printf("    Memory:             %s\n", argv[i]);
        } else if (i == 2){
            printf("    Executable File:    %s\n", argv[i]);
        } else {
            printf("    P.%d:                %s\n", i, argv[i]);
        }
    }
    //Allocate memory the VRE is going to use
    printf("Allocating memory\n");
    int *memory = malloc(5 * sizeof(int));
    if (memory == NULL){
        printf("Unable to allocate memory, exiting environment\n");
        return 1;
    }



    //Free memory before exiting
    printf("Freeing memory\n");
    free(memory);
    return 0;
}