/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  sleep1.c
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
 * @brief Figure 10.7 Simple, incomplete implementation of sleep
 */

#include <signal.h>
#include <unistd.h>

static void sig_alrm(int signo)
{
  /* nothing to do, just return to wake up the pause */
}

unsigned int sleep1(unsigned int nsecs)
{
  if (signal(SIGALRM, sig_alrm) == SIG_ERR)
    return nsecs;
  alarm(nsecs);                                 /* start the timer */
  pause();                                      /* next cautght signal wakes us up */
  return alarm(0);                              /* turn off timer, return unslept time */
}



