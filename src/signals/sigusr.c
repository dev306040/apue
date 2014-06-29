/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  sigusr.c
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
 * @brief Figure 10.2 Simple program to catch SIGUSR1 and SIGUSR2
 */

#include "apue.h"

static void sig_usr(int);                       /* one handler for both signals */

int sigusr_main(int argc, char *argv[])
{
  if (signal_lib(SIGUSR1, sig_usr) == SIG_ERR)
    err_sys("can't catch SIGUSR1");
  if (signal_lib(SIGUSR2, sig_usr) == SIG_ERR)
    err_sys("can't catch SIGUSR2");
  for( ; ; )
    pause();
}

static void sig_usr(int signo)                  /* argument is signal number */
{
  if (signo == SIGUSR1)
    printf("received SIGUSR1\n");
  else if (signo == SIGUSR2)
    printf("received SIGUSR2\n");
  else
    err_dump("received signal %d\n", signo);
}

