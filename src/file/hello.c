/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  1_6.c
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
 * @brief Figure 1.6 Print the process ID
 */

#include "apue.h"

int hello_main(int argc, char *argv[])
{
  printf("hello world from process ID %d\n", getpid());
  exit(0);
}
