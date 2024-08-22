#include <stdio.h>

#include "headers/intepreter.h"

//Returns status and error code of execution, anything over 0 is an error
int executeFile(char *path[]){
    //Buffering the path
    char buf[0x100];
    snprintf(buf, sizeof(buf), "%s.vbf", path);
    //Ready up the executable
    FILE *executable;
    executable = fopen(buf, "rb");
    //Prepare space for instruction
    char instruction[100];
    //Loop instruction
    while(fgets(instruction, sizeof(instruction), executable)){
        printf("%u", instruction);
    }

    return 0;
}