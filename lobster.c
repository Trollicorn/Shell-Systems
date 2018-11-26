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

  printf("%ld\n",strlen(m) );
  if(strlen(m)){
    m[strlen(m)-1] = NULL;
  }
//  printf("[%s]",m);
  char **args = pargs(m);
  int i = 0;
  while(args[i]){
    printf("[%s]\n", args[i]);
    ++i;
  }
  execvp(args[0],args);
  return 0;
}
