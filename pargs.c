#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** pargs(char * line) {

    char **arr = calloc(100, sizeof(char *));

    char *new_line = calloc(strlen(line),1);
    strcpy(new_line, line);

    for (int i = 0; new_line; i++) {
        arr[i] = strsep(&new_line," ");
    }

    return arr;
}
