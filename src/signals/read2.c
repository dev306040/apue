/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  read2.c
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
 * @brief Figure 10.11 Calling read with a timeout, using longjmp
 */

#include "apue.h"
#include <setjmp.h>

static void sig_alrm(int);
static jmp_buf env_alrm;

int read2_main(int argc, char *argv[])
{
  int n;
  char line[MAXLINE];

  if (signal_lib(SIGALRM, sig_alrm) == SIG_ERR)
    err_sys( "signal(SIGALRM) error");
  if (setjmp(env_alrm) != 0)
    err_quit("read timeout");

  alarm(10);

  if ((n = read(STDIN_FILENO, line, MAXLINE)) < 0)
    err_sys("read error");
  alarm(0);

  write(STDOUT_FILENO, line, n);
  exit(0);
}


static void sig_alrm(int signo)
{
  longjmp(env_alrm, 1);
}

