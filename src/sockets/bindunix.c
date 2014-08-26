/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  bindunix.c
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
 * @brief Figure 17.14 Binding an address to a UNIX domain socket
 */
#include "apue.h"
#include <sys/socket.h>
#include <sys/un.h>

int
main(void)
{
  int fd, size;
  struct sockaddr_un un;

  un.sun_family = AF_UNIX;
  strcpy(un.sun_path, "foo.socket");
  if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
    err_sys("socket failed");
  size = offsetof(struct sockaddr_un, sun_path) + strlen(un.sun_path);
  if (bind(fd, (struct sockaddr *)&un, size) < 0)
    err_sys("bind failed");
  printf("UNIX domain socket bound\n");
  exit(0);
}


