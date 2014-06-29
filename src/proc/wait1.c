/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  wait1.c
 *
 *         Editor:  vim :set et ts=2 sts=2 sw=2
 *
 *         Author:  Martin Y. Yang , yang@libpix.org
 *
 *    Description:  
 *
 * =============================================================
 */
/**
 * @file
 * @brief Figure 8.6 Demonstrate various exit statuses
 */

#include "apue.h"
#include <sys/wait.h>

int wait1_main(int argc, char * argv[])
{
  pid_t pid;
  int status;

  if((pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0)
    exit(7);                                    /* child */

  if (wait(&status) != pid)                     /* wait for child */
    err_sys("wait errror");
  pr_exit(status);

  if((pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0)                            /* child */
    abort();                                    /* generates SIGABRT */

  if (wait(&status) != pid)                     /* wait for child */
    err_sys("wait error");
  pr_exit(status);                              /* and print its status */

  if ((pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0)                            /* child */
    status /= 0;                                /* divide by 0 generates SIGFPE */

  if (wait(&status) != pid)                     /* wait for child */
    err_sys("wait error");
  pr_exit(status);
  exit(0);
}

