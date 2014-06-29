/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  exec1.c
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
 * @brief Figure 8.16 Example of exec functions
 */

#include "apue.h"
#include <sys/wait.h>
/**
 * @note env_init is modified to be a static to avoid confilict with other program
 */
static char *env_init[] = { "USER=unknown", "PATH=/tmp", NULL };

int exec1_main(int argc, char *argv[])
{
  pid_t pid;

  if((pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid == 0) {                        /* specify pathname, specify environment */
    if (execle("./apue", "echoall", "myarg1",
          "MY ARG2", (char *)0, env_init) < 0)
      err_sys("execle error");
  }

  if (waitpid(pid, NULL, 0) < 0)
    err_sys("wait error");

  if ((pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid == 0) {
    if (execlp("echoall", "echoall", "only 1 arg", (char *) 0) < 0)
      err_sys("execlp error");
  }

  exit(0);

}


