#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** pargs(char * line) {

    char **arr = calloc(100, sizeof(char *));

    for (int i = 0; line; i++) {
        arr[i] = strsep(&line," ");
    }

    return arr;
}
