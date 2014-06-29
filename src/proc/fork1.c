/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  fork1.c
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
 * @brief Figure 8.1 Example of fork function
 */

#include "apue.h"

static int glob = 6;                            /* external variable in initialized data */
static char buf[] = "a write to stdout\n";


int fork1_main(int argc, char *argv[])
{
  int var;                                      /* automatic variable on the stack */
  pid_t pid;

  var = 88;
  if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
    err_sys("write error");
  printf("before fork\n");                      /* we don't flush stdout */

  if((pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid == 0) {                        /* child */
    glob++;                                     /* modify variables */
    var++;
  } else {
    sleep(2);                                   /* parent */
  }

  printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
  exit(0);
}

