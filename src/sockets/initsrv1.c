/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  initsrv1.c
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
 * @brief Figure 16.10 Initialize a socket endpoint for use by a server
 */
#include "apue.h"
#include <errno.h>
#include <sys/socket.h>

int
initserver(int type, const struct sockaddr *addr, socklen_t alen, int qlen)
{
  int fd;
  int err = 0;

  if ((fd = socket(addr->sa_family, type, 0)) < 0)
    return(-1);
  if (bind(fd, addr, alen) < 0) {
    err = errno;
    goto errout;
  }
  if (type == SOCK_STREAM || type == SOCK_SEQPACKET) {
    if (listen(fd, qlen) < 0) {
      err = errno;
      goto errout;
    }
  }
  return(fd);

errout:
  close(fd);
  errno = err;
  return(-1);
}
