#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args(char * line) {

    char **arr = calloc(6, sizeof(char *));

    char *new_line = calloc(strlen(line),1);
    strcpy(new_line, line);

    for (int i = 0; new_line; i++) {
        arr[i] = strsep(&new_line," ");
    }

    return arr;
}

int main(int argc, char * argv[]) {

//    printf("\n[Testing parse_args with \"ls -a -l\"]\n");
    char mmm[100];
    strcpy(mmm," ");
    int i = 1;
    while(argv[i]){
       strcat(mmm,argv[i]);
       strcat(mmm," ");
       ++i;
    }
    printf("%s\n", mmm);
    char **args = parse_args(mmm);
    execvp(argv[0],args);

    return 0;
}
