/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  1_9.c
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
 * @brief Figure 1.9 Print user ID and group ID
 */

#include "apue.h"

int uidgid_main(int argc, char *argv[])
{
  printf("uid = %d, gid = %d\n", getuid(), getgid());
  exit(0);
}
