/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  spipe.c
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
 * @brief Figure 17.13 Socket version of the s_pipe function
 */

#include "apue.h"
#include <sys/socket.h>

/*
 * Returns a full-duplex "stream" pipe (a UNIX domain socket)
 * with the two file descriptors returned in fd[0] and fd[1]
 */

int
s_pipe(int fd[2])
{
  return(socketpair(AF_UNIX, SOCK_STREAM, 0, fd));
}

