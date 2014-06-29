/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  opendata.c
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
 * @brief Figure 7.14 Incorrect usage of an automatic variable
 * @note This is an error demonstration program, not be compiled
 */

#include <stdio.h>

#define DATAFILE "datafile"

FILE * open_data(void)
{
  FILE *fp;
  char databuf[BUFSIZ];                         /* setvbuf makes this the stdio buffer */

  if ((fp = fopen(DATAFILE, "r")) == NULL)
    return NULL;
  if (setvbuf(fp, databuf, _IOLBF, BUFSIZ) != 0)
    return NULL;
  return fp;                                    /* error */
}



