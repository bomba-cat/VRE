#include <stdio.h>

#include "headers/memory.h"

int mapFile(int *memstart, int memsize, char *instruction){
    printf("Mapping file to Virtual Memory...");
    //Buffer the Hex to prepare for mapping
    char buf[0x100];
    snprintf(buf, sizeof buf - 1, "%s", instruction);

    printf("just a quick little test: %02x\n", instruction[1]);

    //printf("Mapping %02x\n", buf);

    return 0;
}