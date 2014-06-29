/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  f4_9.c
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
 * @brief Figure 4.9 Example of umask function
 */

#include "apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int umask_main(int argc, char *argv[])
{
  umask(0);
  if (creat("foo", RWRWRW) < 0)
    err_sys("creat error for foo");
  umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
  if (creat("bar", RWRWRW) < 0)
    err_sys("creat error for bar");
  exit(0);
}

