#include <stdio.h>

//Returns status and error code of execution, anything over 0 is an error
int executeFile(char *path[]){
    FILE *executable;
    executable = fopen(path, "rb");

    return 0;
}