#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "pargs.h"

int lobster(){
  return 0;
}

int main(int argc, char * argv[]) {
  char m[100];// = "ls";
  fgets(m, sizeof(m), stdin);
  if(!strlen(m)){
    m[strlen(m)-1] = "\0";
  }
  printf("%s",m);
  char **args = pargs(m);
  execvp("lobster",args);
  return 0;
}
