/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  1_10.c
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
 * @brief Figure 1.10 Read commands from standard input and execute them
 */

#include "apue.h"
#include <sys/wait.h>

static void sig_int(int);

int shell2_main(int argc, char *argv[])
{
  char buf[MAXLINE];
  pid_t pid;
  int status;

  if (signal_lib(SIGINT, sig_int) == SIG_ERR)
    err_sys("signal error");

  printf("%% ");
  while (fgets(buf, MAXLINE, stdin) != NULL) {
    if (buf[strlen(buf) - 1] == '\n')
      buf[strlen(buf) - 1] = 0;

    if ((pid = fork()) < 0) {
      err_sys("fork error");
    } else if (pid == 0) {
      execlp(buf, buf, (char *)0);
      err_ret("couldn't execute: %s", buf);
      exit(127);
    }

    /* parent */
    if ((pid = waitpid(pid, &status, 0)) < 0)
      err_sys("waitpid error");
    printf("%% ");
  }
  exit(0);
}

void sig_int(int signo)
{
  printf("interrupt\n%% ");
}
