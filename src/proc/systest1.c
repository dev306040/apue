/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  systest1.c
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
 * @brief Figure 8.23 Calling the system function
 */

#include "apue.h"
#include <sys/wait.h>

int systest1_main(int argc, char *argv[])
{
  int status;

  if ((status = system_lib("date")) < 0)
      err_sys("system() error");
  pr_exit(status);

  if ((status = system_lib("nosuchcommand")) < 0)
    err_sys("system() error");
  pr_exit(status);

  if((status = system_lib("who; exit 44")) < 0)
    err_sys("system() error");
  pr_exit(status);

  exit(0);
}



