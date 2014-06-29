/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  1_8.c
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
 * @brief Figure 1.8 Demonstrate  strerror and perror
 *
 */
#include "apue.h"
#include <errno.h>


int testerror_main(int argc, char *argv[])
{
  fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
  errno = ENOENT;
  perror(argv[0]);
  exit(0);
}
