#include <stdio.h>

#include "headers/intepreter.h"
#include "headers/memory.h"

//Returns status and error code of execution, anything over 0 is an error
int loadFile(char *path, int *memstart, int memsize){
    //Buffering the path
    char buf[0x100];
    snprintf(buf, sizeof buf - 1, "%s", path);
    //Ready up the executable
    FILE *executable;
    executable = fopen(buf, "rb");

    if (!executable) {
        printf("Error opening file: %s\n", buf);
        return 1; // Return an error code
    }
    //Prepare space for instruction
    char instruction[3];
    //Loop instruction
    while (fscanf(executable, "%2x", &instruction) == 1) {
        for (int i = 0; i < sizeof(instruction); i++){
            mapFile(memstart, memsize, instruction);
        }
    }

    //Almost forgot this like a silly billy
    printf("\nClosing %s\n", buf);
    fclose(executable);

    // WOHOOO NO ERRORS!!!
    printf("Closing intepreter...\n"); //silly billy not using newlines
    return 0;
}