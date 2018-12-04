#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

#include "pargs.h"

void prompt(){
  char cwd[PATH_MAX];
  getcwd(cwd,sizeof(cwd));
  printf("\n<[Carapace:%s]>",cwd);
}

static void scorpion(int sig1, int sig2){
  return; 
}

int lobster(){
  char m[LINE_MAX];
  fgets(m, sizeof(m), stdin);

  int backin = dup(STDIN_FILENO); //multiply std
  int backout = dup(STDOUT_FILENO);

  if(strlen(m)){
    m[strlen(m)-1] = '\0';
  }
  else{
    return 0;
  }
  char **comms = pargs(m,";");
         /* PARSE PRINTER
  int ss = 0;
  while(comms[ss]){
    printf("%d:[%s]\n", ss,comms[ss]);
    ++ss;
  }
      */
  for (int n=0;comms[n];++n){
//    printf("N: %d\n",n );
    char **args = pargs(comms[n]," ");

    int f = fork();
    if (!f){
             /* PARSE PRINTER
      int i = 0;
      while(args[i]){
        printf("%d:[%s]\n", i,args[i]);
        ++i;
      }
          */
      if (!strcmp(args[0],"exit")){
        exit(1);
      }
      if (!strcmp(args[0],"cd")){
        exit(2);
      }
      for (int i = 0; args[i]; ++i){
        if (!strcmp(args[i], "<")){
          int fd = open(args[i+1], O_RDONLY, 0644);
          if (fd == -1){
	    printf("%s\n",strerror(errno));
	  }
          dup2(fd, STDIN_FILENO);
          args[i] = NULL;
        }
        else if (!strcmp(args[i],">")){
	 int fd = open(args[i+1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
          if (fd == -1){
	    printf("%s\n",strerror(errno));
	  }
          dup2(fd, STDOUT_FILENO);
          args[i] = NULL;
        }
        else if (!strcmp(args[i],">>")){
          int fd = open(args[i+1], O_WRONLY | O_CREAT | O_APPEND, 0644);
          if (fd == -1){
            printf("%s\n",strerror(errno));
          }
          dup2(fd, STDOUT_FILENO);
          args[i] = NULL;
        }
        else if (!strcmp(args[i],"|")){    //if this breaks, call a plumber
	  int fd[2];
          pipe(fd);
          int p = fork();   //a grandchild!
          args[i] = NULL;
	  if (!p){
            dup2(fd[1],STDOUT_FILENO);  //write end now takes from stdout
            execvp(args[0],args);     //running away from death
            printf("%s\n", strerror(errno));
          }
          dup2(fd[0],STDIN_FILENO); //read from readend instead of stdin now
          close(fd[1]);            //no more writing
	  execvp(args[i + 1], &args[i +1]);
          printf("%s\n", strerror(errno));
	}

      }

      execvp(args[0],args);
      printf("%s\n", strerror(errno));
      exit(0);
    }
  //  printf("%d got here3\n",n );
    int stat;
    scorpion(SIG_INT, SIG_IGN);
    wait(&stat);
    dup2(backin, STDIN_FILENO);
    dup2(backout, STDOUT_FILENO);

    if (WEXITSTATUS(stat)==1){ //exit
      exit(0);
    }
    else if(WEXITSTATUS(stat)==2){ //cd
      if (args[1]){
        if (chdir(args[1])){
          printf("%s\n", strerror(errno));
        }
        if (comms[n+1]){
          continue;
        }
        prompt();
        return 0;
      }
      chdir(getenv("HOME"));
      if (comms[n+1]){
        continue;
      }
      prompt();
      return 0;
    }
//    printf("%d got here2\n",n);
    if (comms[n+1]){
  //    printf("%d:%s\n", n,comms[n+1]);
      continue;
    }
//    printf("%d got here\n",n);
    prompt();
    return 0;
  }
}

