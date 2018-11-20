#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char * argv[]) {
  int i = 0;
  while(argv[i]){
    printf("%s\n", argv[i]);
    printf("\n");
    i++;
  }
  return 0;
}
