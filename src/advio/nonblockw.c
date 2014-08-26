/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  nonblockw.c
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
 * @brief Figure 14.1 Large nonblocking write
 */
#include "apue.h"
#include <errno.h>
#include <fcntl.h>

char buf[500000];

int
main(void)
{
  int ntowrite, nwrite;
  char *ptr;

  ntowrite = read(STDIN_FILENO, buf, sizeof(buf));
  fprintf(stderr, "read %d bytes\n", ntowrite);

  set_fl(STDOUT_FILENO, O_NONBLOCK); /* set nonblocking */

  ptr = buf;
  while (ntowrite > 0) {
    errno = 0;
    nwrite = write(STDOUT_FILENO, ptr, ntowrite);
    fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite, errno);

    if (nwrite > 0) {
      ptr += nwrite;
      ntowrite -= nwrite;
    }
  }

  clr_fl(STDOUT_FILENO, O_NONBLOCK); /* clear nonblocking */

  exit(0);
}
