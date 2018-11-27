#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#include "pargs.h"

int lobster(){
  char m[100];// = "ls";
//  printf("%ld\n\n",sizeof(m) );
  fgets(m, sizeof(m), stdin);
//  printf("%ld\n",strlen(m) );
  if(strlen(m)){
    m[strlen(m)-1] = NULL;
  }else{
    return;
  }
  char **args = pargs(m);
//  printf("[%s]",m);
  int f = fork();
  if (!f){
/*  int i = 0;
  while(args[i]){
    printf("[%s]\n", args[i]);
    ++i;
  }
*/
    if (!strcmp(args[0],"cd")){
      if (args[1]){
        if (chdir(args[1])){
          printf("ERROR OCCURED\n" );
        }
        char cwd[PATH_MAX];
      //  printf("passed\n" );
        getcwd(cwd,sizeof(cwd));
        printf("\n<[Lobster:%s]>",cwd);

        return 0;
      }
      printf("NO ARGS GIVEN\n" );
      return 0;
    }
    execvp(args[0],args);
  }
  int *n;
  wait(n);
  char cwd[PATH_MAX];
  getcwd(cwd,sizeof(cwd));
  printf("\n<[Lobster:%s]>",cwd);
  return 0;
}

int main(int argc, char * argv[]) {
char cwd[PATH_MAX];
getcwd(cwd,sizeof(cwd));
printf("\n<[Lobster:%s]>",cwd);
  while (1) {
    lobster();
  }
  return 0;
}
