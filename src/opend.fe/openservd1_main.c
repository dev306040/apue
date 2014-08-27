/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  openservd_main1.c
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
 * @brief Figure 17.30 The server main function, version 1
 */

#include "openservd1.h"

char errmsg[MAXLINE]
int oflag;
char *pathname;

int
main(void)
{
  int nread;
  char buf[MAXLINE];

  for (;;) { /* read arg buffer from client, process request */
    if ((nread = read(STDIN_FILENO, buf, MAXLINE)) < 0)
      err_sys("read error on stream pipe");
    else if (nread == 0)
      break; /* client has closed the stream pipe */
    request(buf, nread, STDOUT_FILENO);
  }
  exit(0);
}


