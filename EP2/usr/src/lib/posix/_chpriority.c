#include <lib.h>
#define chpriority	_chpriority
#include <unistd.h>

#include <stdio.h>

PUBLIC pid_t chpriority(pid, pri)
pid_t pid;
int pri; 
{
  message m;

  m.m1_i1 = (int) pid;
  m.m1_i2 = pri;

  printf("ESTOU NA POSIX CHPRIORITY\n");
  return(_syscall(MM, CHPRIORITY, &m));
}
