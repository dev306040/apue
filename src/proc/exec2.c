/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  exec2.c
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
 * @brief Figure 8.20 A program that execs an interpreter file
 * @note I modified some lines of the code list
 */


#include "apue.h"
#include <sys/wait.h>

int exec2_main(int argc, char *argv[])
{
  pid_t pid;
  if ((pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid == 0) {                        /* child */
    if (execl("./testinterp", "testinterp",
          "myarg1", "MY ARG2", (char *)0) < 0)
      err_sys("execl error");
  }
  if (waitpid(pid, NULL, 0) < 0)                /* parent */
    err_sys("waitpid error");
  exit(0);
}
