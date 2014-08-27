/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  oepnservd1.c
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
 * @brief Figure 17.31 The request function, version 1
 */

#include "openservd1.h"
#include <fcntl.h>

void
request(char *buf, int nread, int fd)
{
  int newfd;
  
  if (buf[nread-1] != 0) {
    sprintf(errmsg, "request not null terminated: %*.*s\n",
        nread, nread, buf);
    send_err(fd, -1, errmsg);
    return;
  }
  if (buf_args(buf, cli_args) < 0) { /* parse args & set options */
    send_err(fd, -1, errmsg);
    return;
  }
  if ((newfd = open(pathname, oflag)) < 0) {
    sprintf(errmsg, "can't open %s: %s\n", pathname,
        strerror(errno));
    send_err(fd, -1, errmsg);
    return;
  }
  if (send_fd(fd, newfd) < 0) /* sned the descriptor */
    err_sys("send_fd error");
  close(newfd); /* we're done with descriptor */
}



