#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/wait.h>

#include "pargs.h"

int lobster(){
  char m[100];// = "ls";
//  printf("%ld\n\n",sizeof(m) );
  fgets(m, sizeof(m), stdin);
//  printf("%ld\n",strlen(m) );
  if(strlen(m)){
    m[strlen(m)-1] = NULL;
  }else{
    return 0;
  }
  char **args = pargs(m," ");
  int f = fork();
  if (!f){
  int i = 0;
  while(args[i]){
    printf("%d:[%s]\n", i,args[i]);
    ++i;
  }

    if (!strcmp(args[0],"exit")){
      exit(1);
    }
    if (!strcmp(args[0],"cd")){
      exit(2);
    }
    execvp(args[0],args);
  }
  int n;
  wait(&n);
  if (WEXITSTATUS(n)==1){
    exit(0);
  }
  else if(WEXITSTATUS(n)==2){
    if (args[1]){
      if (chdir(args[1])){
        printf("Directory does not exist" );
      }
      char cwd[PATH_MAX];
      getcwd(cwd,sizeof(cwd));
      printf("\n<[Lobster:%s]>",cwd);
      return 0;
    }
    chdir(getenv("HOME"));
    char cwd[PATH_MAX];
    getcwd(cwd,sizeof(cwd));
    printf("\n<[Lobster:%s]>",cwd);
    return 0;
  }
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
