#include <lib.h>
#include <stdio.h>

PUBLIC int _syscall(who, syscallnr, msgptr)
int who;
int syscallnr;
register message *msgptr;
{
  int status;

  if(syscallnr > 90) {
    printf("SYSCALL %d\n", syscallnr);
  }

  msgptr->m_type = syscallnr;
  status = _sendrec(who, msgptr);
  if (status != 0) {
	/* 'sendrec' itself failed. */
	/* XXX - strerror doesn't know all the codes */
	msgptr->m_type = status;
  }

  if (msgptr->m_type < 0) {
	errno = -msgptr->m_type;
  printf("errno %d\n", errno);
	return(-1);
  }
  return(msgptr->m_type);
}
