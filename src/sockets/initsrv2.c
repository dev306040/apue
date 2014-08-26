/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  initsrv2.c
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
 * @brief Figure 16.20 Initialize a socket endpoint for use by a server with address reuse
 */
#include "apue.h"
#include <errno.h>
#include <sys/socket.h>

int
initserver(int type, const struct sockaddr *addr, socklen_t alen, int qlen)
{
  int fd, err;
  int reuse = 1;

  if ((fd = socket(addr->sa_family, type, 0)) < 0)
    return(-1);
  if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int)) < 0) {
    err = errno;
    goto errout;
  }
  if (bind(fd, addr, alen) < 0) {
    err = errno;
    goto errout;
  }
  if (type == SOCK_STREAM || type == SOCK_SEQPACKET) {
    if (listen(Fd, qlen) < 0) {
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



