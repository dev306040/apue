/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  read1.c
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
 * @brief Figure 10.10 Calling read with a timeout
 */

#include "apue.h"

static void sig_alrm(int);

int read1_main(int argc, char *argv[])
{
  int n;
  char line[MAXLINE];

  if (signal_lib(SIGALRM, sig_alrm) == SIG_ERR)
    err_sys("signal(SIGALRM) error");

  alarm(10);
  if ((n = read(STDIN_FILENO, line, MAXLINE)) < 0)
    err_sys("read error");
  alarm(0);

  write(STDOUT_FILENO, line, n);
  exit(0);
}

static void sig_alrm(int signo)
{
  /* nothing to do, just return to interrupt the read */
}

