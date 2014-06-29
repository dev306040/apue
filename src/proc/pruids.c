/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  pruids.c
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
 * @brief Figure 8.25 Print real and effective user IDs
 */

#include "apue.h"

int pruids_main(int argc, char *argv[])
{
  printf("real uid = %d, effective uid = %d\n", getuid(), geteuid());
  exit(0);
}


