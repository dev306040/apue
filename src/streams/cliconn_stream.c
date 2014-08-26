/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  cliconn.c
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
 * @brief Figure 17.12 The cli_conn function using STREAMS pipes
 */

#include "apue.h"
#include <fcntl.h>
#include <stropts.h>

/*
 * Create a client endpoint and connect to a server.
 * Returns fd if all OK, <0 on error.
 */

int
cli_conn(const char *name)
{
  int fd;

  /* open the mounted stream */
  if ((fd = open(name, O_RDWR)) < 0)
    return(-1);
  if (isastream(fd) == 0) {
    close(fd);
    return(-2);
  }
  return(fd);
}

