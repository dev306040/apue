/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  f4_16.c
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
 * @brief Figure 4.16 Open a file and then unlink it
 */

#include "apue.h"
#include <fcntl.h>

int unlink_main(int argc, char *argv[])
{
  if (open("tempfile", O_RDWR) < 0)
    err_sys("open error");
  if (unlink("tempfile") < 0)
    err_sys("unlink error");
  printf("file unlinked\n");
  sleep(15);
  printf("done\n");
  exit(0);
}

