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


void prompt();

int lobster();
