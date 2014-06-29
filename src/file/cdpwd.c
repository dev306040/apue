/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  f4_24.c
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
 * @brief Figure 4.24 Example of getcwd function
 */

#include "apue.h"

int cdpwd_main(int argc, char *argv[])
{
  char *ptr;
  int size;

  if (chdir("/usr/spool/uucppublic") < 0)
    err_sys("chdir failed");

  ptr = path_alloc(&size);
  if (getcwd(ptr, size) == NULL)
    err_sys("getcwd failed");
  printf("cwd = %s\n", ptr);
  exit(0);
}


