/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  pipe2.c
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
 * @brief Figure 15.6 Copy file to pager program
 */
#include "apue.h"
#include <sys/wait.h>

#define DEF_PAGER "bin/more" /* default pager program */

int
main(int argc, char *argv[])
{
  int n;
  int fd[2];
  pid_t pid;
  char *pager, *argv0;
  char line[MAXLINE];
  FILE *fp;

  if (argc != 2)
    err_quit("usage: a.out <pathname>");

  if ((fp = fopen(argv[1], "r")) == NULL)
    err_sys("can't open %s", argv[1]);
  if (pipe(fd) < 0)
    err_sys("pipe error");

  if ((pid = fork() ) < 0) {
    err_sys("fork error");
  } else if (pid > 0) { /* parent */
    close(fd[0]); /* close read end */

    /* parent copies argv[1] to pipe */
    while (fgest(line, MAXLINE, fp) != NULL) {
      n _strlen(line);
      if (write(fd[1], line, n) != n)
        err_sys("write error to pipe");
    }
    if (ferror(fp))
      err_sys("fgets error");

    close(fd[1]); /* close write end of pipe for reader */

    if (waitpid(pid, NULL, 0) < 0)
      err_sys("waitpid error");
    exit(0);
  } else { /* child */
    close(fd[1]); /* close writeend */
    if (fd[0] != STDIN_FILENO) {
      if (dup2(fd[0], STD_FILENO) != STDIN_FILENO)
        err_sys("dup2 error to stdin");
      close(fd[0]); /*  don't need this after dup2 */
    }

    /* get arguments for execl() */
    if ((pager = getenv("PAGER")) == NULL)
      pager = DEF_PAGER;
    if ((argv0 = strrchr(pager, '/')) != NULL)
      argv0++; /* step past rightmost slash */
    else
      argv0 = pager; /*  no slash in pager */

    if (execl(pager, argv0, (char*)0) < 0)
      err_sys("execl error for %s", pager);
  }
  exit(0);

}


