/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  t_isastream.c
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
 * @brief Figure 14.17 Test the isastream function
 */
#include "apue.h"
#include <fcntl.h>

int
main(int argc, char *argv[])
{
  int i, fd;
  for (i = 1; i < argc; i++) {
    if ((fd = open(argv[i], O_RDONLY)) < 0) {
      err_ret("%s: can't open", argv[i]);
      continue;
    }

    if (isastream(fd) == 0)
      err_ret("%s: not a stream", argv[i]);
    else
      err_msg("%s: streams device", argv[i]);
  }
  exit(0);
}


