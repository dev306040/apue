/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  suspend2.c
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
 * @brief Figure 10.23 Using sigsuspend to wait for a global variable to be set
 */

#include "apue.h"

volatile sig_atomic_t quitflag;                 /* set nonzero by signal handler */

static void sig_int(int signo)                  /* one signal handler for SIGINT and SIGQUIT */
{
  if (signo == SIGINT)
    printf("\ninterrupt\n");
  else if (signo == SIGQUIT)
    quitflag = 1;                               /* set flag for main loop */
}

int suspend2_main(int argc, char *argv[])
{
  sigset_t newmask, oldmask, zeromask;

  if (signal_lib(SIGINT, sig_int) == SIG_ERR)
    err_sys("signal(SIGINT) error");
  if (signal_lib(SIGQUIT, sig_int) == SIG_ERR)
    err_sys("signal(SIGQUIT) error");

  sigemptyset(&zeromask);
  sigemptyset(&newmask);
  sigaddset(&newmask, SIGQUIT);

  /*
   * Block SIGQUIT and save current signal mask.
   */
  if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
    err_sys("SIG_BLOCK error");

  while (quitflag == 0)
    sigsuspend(&zeromask);

  /*
   * SIGQUIT has been caught and is now blocked; do whatever.
   */
  quitflag = 0;

  /*
   * Reset signal mask which unblocks SIGQUIT.
   */
  if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
    err_sys("SIG_SETMASK error");

  exit(0);
}


