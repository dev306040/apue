/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  setops.c
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
 * @brief Figure 10.12 An implementtaion of sigaddset, sigdelset, and sigismember
 * @bug sigset_t type problem \n
 *   In my os, I got this typedef of sigset_t
 *   @code
 *      typedef struct
 *      {
 *        unsigned long int __val[_SIGSET_NWORDS];
 *      } __sigset_t;
 *   @endcode
 *   so we got problem with bit operator, think it over later.
 */

#include <signal.h>
#include <errno.h>

/* <signal.h> usually defines NSIG to include signal number 0 */
#define SIGBAD(signo)  ((signo) <= 0 || (signo) >= NSIG)

int sigaddset_apue(sigset_t *set, int signo)
{
  if (SIGBAD(signo)) {
    errno = EINVAL;
    return -1;
  }

  /* BUG  *set |= 1 << (signo -1); */                     /* turn bit on */
  return 0;
}

int sigdelset_apue(sigset_t *set, int signo)
{
  if (SIGBAD(signo)) {
    errno = EINVAL;
    return -1;
  }
  /* BUG *set &= ~(1 << (signo - 1)); */                 /* turn bit off */
  return 0;
}

int sigismember_apue(const sigset_t *set, int signo)
{
  if (SIGBAD(signo)) {
    errno = EINVAL;
    return -1;  
  }
  /* BUG return ((*set & (1 << (signo - 1))) ! = 0); */
  return 0;
}
