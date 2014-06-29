/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  test1.c
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
 * @brief Figure 8.28 Program to generate accounting data
 */

#include "apue.h"

int test1_main(int argc, char *argv[])
{
  pid_t pid;

  if ((pid = fork()) < 0)
    err_sys("fork error");
  else if (pid != 0) {                          /* parent */
    sleep(2);
    exit(2);                                    /* terminate with exit status 2 */
  }
                                                /* first child */
  if ((pid = fork()) < 0)
    err_sys("fork error");
  else if (pid != 0) {
    sleep(4);
    abort();                                    /* terminate with core dump */
  }
                                                /* second child*/
  if ((pid = fork()) < 0)
    err_sys("fork error");
  else if (pid != 0) {
    execl("/bin/dd", "dd", "if=/etc/termcap", "of=/dev/null", NULL);
    exit(7);                                    /* shouldn't get here */
  }
                                                /* third child*/
  if ((pid = fork()) < 0)
    err_sys("fork error");
  else if (pid != 0) {
    sleep(8);
    exit(0);                                    /* normal exit */
  }
                                                /* fourth child */
  sleep(6);
  kill(getpid(), SIGKILL);                      /* terminate w/signal, no core dump */
  exit(6);                                      /* shouldn't get here */
}


