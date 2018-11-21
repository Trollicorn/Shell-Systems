#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "pargs.h"

int lobster(){
  return 0;
}

int main(int argc, char * argv[]) {
  char m[100];
  fgets(m, sizeof(m), stdin);
  char **args = pargs(m);
  execvp(args[0],args);
  return 0;
}
