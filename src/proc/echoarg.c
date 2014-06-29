/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  echoarg.c
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
 * @brief Echo all command-line arguments to standard output
 */

#include "apue.h"

int echoarg_main(int argc, char *argv[])
{
  int i;
  
  for (i = 0; i < argc; i++)                    /* echo all command-line args */
    printf("argv[%d]: %s\n", i, argv[i]);
  exit(0);
}

