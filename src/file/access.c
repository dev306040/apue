/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  f4_8.c
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
 * @brief Figure 4.8 Example of access function
 *
 */

#include "apue.h"
#include <fcntl.h>

int access_main(int argc , char *argv[])
{
  if (argc != 2)
    err_quit("usage: apue 4.8 <pathname>");
  if (access(argv[1], R_OK) < 0)
    err_ret("access error for %s", argv[1]);
  else
    printf("read access OK\n");
  if (open(argv[1], O_RDONLY) <0 )
    err_ret("open error for %s", argv[1]);
  else
    printf("open for reading OK\n");
  exit(0);
}

