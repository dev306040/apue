/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  systest2.c
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
 * @brief Figure 10.26 Using system to invoke the ed editor
 */

#include "apue.h"

static void sig_int(int signo)
{
  printf("caught SIGINT\n");
}

static void sig_chld(int signo)
{
  printf("caught SIGCHLD\n");
}

int systest2_main(int argc, char *argv[])
{
  if (signal_lib(SIGINT, sig_int) == SIG_ERR)
    err_sys("signal(SIGINT) error");
  if (signal_lib(SIGCHLD, sig_chld) == SIG_ERR)
    err_sys("signal(SIGCHLD) error");
  if (system_lib("/bin/ed") < 0)
    err_sys("system() error");
  exit(0);
}


