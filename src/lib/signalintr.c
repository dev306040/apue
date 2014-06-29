/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  signalintr.c
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
 * @brief Figure 10.19 The signal_intr function
 */

#include "apue.h"

Sigfunc * signal_intr(int signo, Sigfunc *func)
{
  struct sigaction act, oact;

  act.sa_handler = func;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
#ifdef SA_INTERRUPT
  act.sa_flags |= SA_INTERRUPT;
#endif
  if (sigaction(signo, &act, &oact) < 0)
    return SIG_ERR;
  return oact.sa_handler;
}


