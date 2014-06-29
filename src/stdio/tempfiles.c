/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  f5_12.c
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
 * @brief Figure 5.12 Demonstrate tmpnam and tmpfile functions
 * @note  warning: the use of `tmpnam' is dangerous, better use `mkstemp'
 * This is a ld warning, we don't know how to disable it
 */

#include "apue.h"

int tempfiles_main(int argc, char *argv[])
{
  char name[L_tmpnam], line[MAXLINE];
  FILE *fp;

  printf("%s\n", tmpnam(NULL));
  tmpnam(name);
  printf("%s\n", name);

  if ((fp = tmpfile()) == NULL)
    err_sys("tmpfile error");
  fputs("one line of output\n", fp);
  rewind(fp);
  if (fgets(line, sizeof(line), fp) == NULL)
    err_sys("fgets error");
  fputs(line, stdout);
  exit(0);

}

