/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  popen1.c
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
 * @brief Figure 15.15 Invoke uppercase/lowercase filter to read commands
 */
#include "apue.h"
#include <sys/wait.h>

int
main(void)
{
  char line[MAXLINE];
  FILE *fpin;

  if ((fpin = popen("myuclc", "r")) == NULL)
    err_sys("popen error");
  for ( ; ; ) {
    fputs("prompt> ", stdout);
    fflush(stdout);
    if (fgets(line, MAXLINE, fpin) == NULL) /* read from pipe */
      break;
    if (fputs(line, stdout) == EOF)
      err_sys("fputs error to pipe");

  }
  if (pclose(fpin) == -1)
    err_sys("pclose error");
  putchar('\n');
  exit(0);
}



