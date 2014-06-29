/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  tellwait1.c
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
 * @brief Figure 8.12 Program with a race condition
 * @see tellwait2.c
 */

#include "apue.h"

static void charatatime(char *);

int tellwait1_main(int argc, char *argv[])
{
  pid_t pid;
  if ((pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid == 0) {
    charatatime("output from child\n");
  } else {
    charatatime("output from parent\n");
  }
  exit(0);
}

static void charatatime(char *str)
{
  char *ptr;
  int c;

  setbuf(stdout, NULL);                         /* set unbuffered */
  for (ptr = str; (c = *ptr++) != 0; )
    putc(c, stdout);
}

