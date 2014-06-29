/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  1_4.c
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
 * @brief Figure 1.4 3.4 Copy standard input to standard output
 *
 * dkfsdkfskdjfkj
 */

#include "apue.h"

#define BUFFSIZE 4096

int mycat_main(int argc, char *argv[])
{
  int n;
  char buf[BUFFSIZE];

  while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
    if (write(STDOUT_FILENO, buf, n) != n)
      err_sys("write error");
  if (n < 0)
    err_sys("read error");
  exit(0);
}
