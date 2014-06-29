/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  vfork1.c
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
 * @brief Figure 8.3 Example of vfork function
 */


#include "apue.h"

static glob = 6;                                /* external variable in initialized data */

int vfork1_main(int argc, char *argv[])
{
  int var;                                      /* automatic variable on the stack */
  pid_t pid;

  var=88;
  printf("before vfork\n");                     /* we don't flush stdio */
  if ((pid = vfork()) < 0) {
    err_sys("vfork error");
  } else if (pid == 0) {                        /* child */
    glob++;                                     /* modify parent's variables */
    var++;
    _exit(0);                                   /* child terminates */
  }
  /*
   * Parent continues here.
   */
  printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
  exit(0);
}
