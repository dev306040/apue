/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  tellwait2.c
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
 * @brief Figure 8.13 Modification of Figure 8.12 to avoid race condition
 * @note TELL_** WAIT_** are implemented in Figure 10.24 tellwait.c
 * @see tellwait.c
 */
#include "apue.h"

static void charatatime(char *);

int tellwait2_main(int argc, char *argv[])
{
  pid_t pid;

  TELL_WAIT();

  if ((pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid == 0) {
    WAIT_PARENT();                              /* parent goes first */
    charatatime("output from child\n");
  } else {
    charatatime("output form parent\n");
    TELL_CHILD(pid);
  }
  exit(0);
}

static void charatatime(char *str)
{
  char *ptr;
  int c;
  setbuf(stdout, NULL);                         /* set unbuffered */
  for (ptr = str; (c = *ptr++) != 0;)
    putc(c, stdout);
}


