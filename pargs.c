#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** pargs(char * line) {

    char **arr = calloc(100, sizeof(char *));
    int i = 0;
    for (; line; i++) {
        arr[i] = strsep(&line," ");
    }
    arr[i+1] = "\0";
    return arr;
}
