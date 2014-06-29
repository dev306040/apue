/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  f4_23.c
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
 * @brief Figure 4.23 Example of chdir function
 */

#include "apue.h"

int mycd_main(int argc, char *argv[])
{
  if (chdir("/tmp") < 0)
    err_sys("chdir failed");
  printf("chdir to /tmp succeeded\n");
  exit(0);
}


