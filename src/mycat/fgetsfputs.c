/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  fgetsfputs.c
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
 * @brief Figure 5.4 Copy standard input to standard output
 * using getc and putc
 */

#include "apue.h"

int fgetsfputs_main(int argc, char *argv[])
{
  int c;
  while ((c = getc(stdin)) != EOF)
    if (putc(c, stdout) == EOF)
      err_sys("output error");
  
  if (ferror(stdin))
    err_sys("input error");

  exit(0);
}


