/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  f5_13.c
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
 * @brief Figure 5.13 Demonstrate tempnam function
 * @note  warning: the use of `tempnam' is dangerous, better use `mkstemp'
 * This is a ld warning, we don't know how to disable it.
 */

#include "apue.h"

int tempnam_main(int argc, char *argv[])
{
  if (argc != 3)
    err_quit("usage: apue 5.13 <directory> <prefix>");

  printf("%s\n", tempnam(argv[1][0] != ' ' ? argv[1] : NULL,
        argv[2][0] != ' ' ? argv[2] : NULL) );
  exit(0);
}


