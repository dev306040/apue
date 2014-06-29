/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  f3_1.c
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
 * @brief Figure 3.1 Test wheter standard input is capable of seeking
 */

#include "apue.h"
int seek_main(int argc, char *argv[])
{
  if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
    printf("cannot seek\n");
  else
    printf("seek OK\n");
  exit(0);
}
