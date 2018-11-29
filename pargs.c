#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** pargs(char * line, char * delim) {

    char **arr = calloc(100, sizeof(char *));
    int i = 0;
    for (; line; i++) {
        if (line[0]==' '){
          arr[i] = strsep(&line,delim);
          --i;
          continue;
        }

        arr[i] = strsep(&line,delim);





      /*
        while (line[0]==delim) { //FIX
          arr[i] = strsep(&line, delim); //FIX
        }
        */                                //FIX
    }
    arr[i+1] = "\0";
    return arr;
}
