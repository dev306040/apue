/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  fork2.c
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
 * @brief Figure 8.8 Avoid zombie processes by calling fork twice
 */

#include "apue.h"
#include <sys/wait.h>

int fork2_main(int argc, char *argv[])
{
  pid_t pid;

  if ((pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid == 0) {                        /* first child */
    if ((pid = fork()) < 0)
      err_sys("fork error");
    else if (pid > 0)
      exit(0);                                  /* parent from second fork == first child */
    /*
     * We're the second child; our parent becomes init as soon
     * as our real parent calls exit() in the statement above.
     * Here's where we'd continue executing, knowing that when
     * we're done, init will reap our status.
     */
    sleep(2);
    printf("second child, parent pid = %d\n", getppid());
    exit(0);
  }

  if (waitpid(pid, NULL, 0) != pid)             /* wait for first child */
    err_sys("waitpid error");

  /*
   * We're the parent (the original process); we continue executing,
   * knowing that we're not the parent of the second child.
   */
  exit(0);

}


