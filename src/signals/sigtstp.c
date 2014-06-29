/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  sigtstp.c
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
 * @brief Figure 10.30 How to handle SIGTSTP
 */

#include "apue.h"

#define BUFFSIZE 1024

static void sig_tstp(int);

int sigtstp_main(int argc, char *argv[])
{
  int n;
  char buf[BUFFSIZE];

  /*
   * Only catch SIGTSTP if we're running with a job-control shell.
   */
  if (signal_lib(SIGTSTP, SIG_IGN) == SIG_DFL)
    signal(SIGTSTP, sig_tstp);

  while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
    if (write(STDOUT_FILENO, buf, n) != n)
      err_sys("write error");

  if (n < 0)
    err_sys("read error");

  exit(0);
}

static void sig_tstp(int signo)                 /* signal handler for SIGTSTP */
{
  sigset_t mask;
  /* ... move cursor to lower left corner, reset tty mode ... */

  /*
   * Unblock SIGTSTP, since it's blocked while we're handling it.
   */
  sigemptyset(&mask);
  sigaddset(&mask, SIGTSTP);
  sigprocmask(SIG_UNBLOCK, &mask, NULL);

  signal_lib(SIGTSTP, SIG_DFL);                 /* reset disposition to default */

  kill(getpid(), SIGTSTP);                      /* and send the signal to ourself */

  /* we won't return from the kill until we're continued */

  signal_lib(SIGTSTP, sig_tstp);                /* reestablish signal handler */

  /* ... reset tty mode, redraw screen ... */

}



