/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  systest3.c
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
 * @brief Figure 8.24 Execute the command-line argument using system
 */

#include "apue.h"

int systest3_main(int argc, char *argv[])
{
  int status;

  if (argc < 2)
    err_quit("command-line argument required");

  if ((status = system_lib(argv[1])) < 0)
    err_sys("system() error");
  pr_exit(status);

  exit(0);
}
