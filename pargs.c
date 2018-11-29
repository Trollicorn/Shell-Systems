#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** pargs(char * line, char * delim) {

    char **arr = calloc(100, sizeof(char *));



    char *end;
    end = line + strlen(line) - 1;
    while (end > line && end[0] == delim[0]) {
      end--;
    }
    end[1] = '\0';

//    printf("{%s}\n",line );

    int i = 0;

    for (; line; i++) {
        if (line[0]==delim[0]){
          arr[i] = strsep(&line,delim);
          --i;
          continue;
        }

        arr[i] = strsep(&line,delim);
    }



//    printf("---(%d)---\n", i);
    arr[i+1] = "\0";
/*    if (!strlen(arr[i-1])){
      printf("oof\n");
    }
*/
    return arr;

}
