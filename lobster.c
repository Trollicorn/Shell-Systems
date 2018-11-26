#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
//  printf("[%s]",m);
  int f = fork();
  if (!f){
    char **args = pargs(m);
/*  int i = 0;
  while(args[i]){
    printf("[%s]\n", args[i]);
    ++i;
  }
*/
    execvp(args[0],args);
  }
  int *n;
  wait(n);
  return 0;
}

int main(int argc, char * argv[]) {
  while (1) {
    lobster();
  }
  return 0;
}
