/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  pipe1.c
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
 * @brief Figure 15.5 Send data from parent to child over a pipe
 */
#include "apue.h"

int
main(void)
{
  int n;
  int fd[2];
  pid_t pid;
  char line[MAXLINE];

  if (pipe(fd) < 0)
    err_sys("pipe error");
  if((pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid > 0) { /*  parent */
    close(fd[0]);
    write(fd[1], "hello world\n", 12);
  } else { /*  child */
    close(fd[1]);
    n = read(fd[0], line, MAXLINE);
    write(STDOUT_FILENO, line, n);
  }
  exit(0);
}



