/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  prmask.c
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
 * @brief Figure 10.14 Print the signal mask for the process
 */

#include "apue.h"
#include <errno.h>
/*
 * @brief Print the signal mask for the process.
 */

void pr_mask(const char *str)
{
  sigset_t sigset;
  int errno_save;

  errno_save = errno;                           /* we can be called by signal handlers */
  if (sigprocmask(0, NULL, &sigset) < 0)
    err_sys("sigprocmask error");

  printf("%s", str);

  if (sigismember_apue(&sigset, SIGINT))
    printf("SIGINT ");
  if (sigismember_apue(&sigset, SIGQUIT))
    printf("SIGQUIT ");
  if (sigismember_apue(&sigset, SIGUSR1))
    printf("SIGUSR1 ");
  if (sigismember_apue(&sigset, SIGALRM))
    printf("SIGALRM ");
  /* remaning signals can go here */

  printf("\n");
  errno = errno_save;
}
