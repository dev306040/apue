/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  echoall.c
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
 * @brief Figure 8.17 Echo all command-line arguments and all environment strings
 */
#include "apue.h"

int echoall_main(int argc, char *argv[])
{
  int i;
  char **ptr;
  extern char **environ;

  for (i = 0; i < argc; i++)                    /* echo all command-line args */
    printf("argv[%d]: %s\n", i, argv[i]);

  for (ptr = environ; *ptr != 0; ptr++)         /* and all env strings */
    printf("%s\n", *ptr);

  exit(0);
}
