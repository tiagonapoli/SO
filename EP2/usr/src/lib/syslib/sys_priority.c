#include "syslib.h"

PUBLIC int sys_priority(int proc, int prio)
{
  message m;

  m.m1_i1 = proc;
  m.m1_i2 = prio;
  return(_taskcall(SYSTASK, SYS_PRIORITY, &m));
}