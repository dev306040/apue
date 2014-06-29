/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  suspend1.c
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
 * @brief Figure 10.22 Protecting a critical region from a signal
 */

#include "apue.h"

static void sig_int(int);

int suspend1_main(int argc, char *argv[])
{
  sigset_t newmask, oldmask, waitmask;

  pr_mask("program start: ");
  if (signal_lib(SIGINT, sig_int) == SIG_ERR)
    err_sys("signal(SIGINT) error");
  sigemptyset(&waitmask);
  sigaddset(&waitmask, SIGUSR1);
  sigemptyset(&newmask);
  sigaddset(&newmask, SIGINT);

  /*
   * Block SIGINT and save current signal mask.
   */
  if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
    err_sys("SIG_BLOCK error");

  /*
   * Critical region of code.
   */
  pr_mask("in critical region: ");

  /*
   * Pause, allowing all signals except SIGUSR1
   */
  if (sigsuspend(&waitmask) != -1)
    err_sys("sigsuspend error");

  pr_mask("after return from sigsuspend: ");

  /*
   * Reset signal mask which unblocks SIGINT.
   */
  if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
    err_sys("SIG_SETMASK error");
  /*
   * And continue processing ...
   */
  pr_mask("program exit: ");

  exit(0);
}

static void sig_int(int signo)
{
  pr_mask("\n sig_int: ");
}


