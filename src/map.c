#include <stdio.h>

#include "headers/memory.h"

int mapFile(int *memstart, int memsize, char *instruction){
    //Buffer the Hex to prepare for mapping
    char buf[0x200];
    snprintf(buf, sizeof buf - 1, "%s", instruction);

    printf("just a quick little test: %02x\n", instruction);

    //printf("Mapping %02x\n", buf);

    return 0;
}