/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  cliargs.c
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
 * @brief Figure 17.33 The cli_args function
 */

#include "openservd1.h"
/*
 * This function is called by buf_args(), which is called by request(),
 * buf_args() has broken up the client's buffer into an argv[]-style
 * array, which we now process.
 */

int
cli_args(int argc, char *argv)
{
  if (argc != 3 || strcmp(argv[0], CL_OPEN) != 0) {
    strcpy(errmsg, "usage: <pathname> <oflag>>\n");
    return(-1);
  }
  pathname = argv[1]; /* save ptr to pathname to open */
  oflag = atoi(argv[2]);
  return(0);
}


