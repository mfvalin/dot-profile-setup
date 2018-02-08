#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

main(int argc, char **argv)
{
  pid_t pid=atoi(argv[1]);
  if(kill(pid,0)) exit(1);
  exit(0);
}
