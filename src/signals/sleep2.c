/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  sleep2.c
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
 * @brief Figure 10.8 Another (imperfect) implementation of sleep
 */
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>

static jmp_buf env_alrm;

static void sig_alrm(int signo)
{
  longjmp(env_alrm, 1);
}


unsigned int sleep2(unsigned int nsecs)
{
  if (signal(SIGALRM, sig_alrm) == SIG_ERR)
    return nsecs;
  if (setjmp(env_alrm) == 0) {
    alarm(nsecs);                               /* start the timer */
    pause();                                    /* next caught signal wakes us up */
  }
  return alarm(0);                              /* turn off timer, return unslept time */
}


