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

    if (!executable) {
        printf("Error opening file: %s\n", buf);
        return 1; // Return an error code
    }
    //Prepare space for instruction
    char instruction[100];
    //Loop instruction
    while (fread(instruction, 1, sizeof(instruction), executable) > 0) {
        // Print the binary data (in hex format)
        for (int i = 0; i < sizeof(instruction); i++) {
            printf("%02x ", (unsigned char)instruction[i]);
        }
    }

    //Almost forgot this like a silly billy
    fclose(executable);

    // WOHOOO NO ERRORS!!!
    return 0;
}