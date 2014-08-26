/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  myuclc.c
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
 * @brief Figure 15.14 Filter to convert uppercase characters to lowercase
 */
#include "apue.h"
#include <ctype.h>

int
main(void)
{
  int c;

  while ((c = getchar()) != EOF) {
    if (isupper(c))
      c = tolower(c);
    if (putchar(c) == EOF)
      err_sys("output error");
    if (c == '\n')
      fflush(stdout);
  }
  exit(0);
}


