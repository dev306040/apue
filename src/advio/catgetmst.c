/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  catgetmst.c
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
 * @brief Figure 14.19 Copy standard input to standard output using getmsg
 */

#include "apue.h"
#include <stropts.h>

#define BUFFSIZE 4096

int
main(void)
{
  int n, flag;
  char ctlbuf[BUFFSIZE], datbuf[BUFFSIZE];
  struct strbuf ctl, dat;

  ctl.buf = ctlbuf;
  ctl.maxlen = BUFFSIZE;
  dat.buf = datbuf;
  dat.maxlen = BUFFSIZE;
  for (;;) {
    flag = 0; /* return any message */
    if ((n = getmsg(STDIN_FILENO, &ctl, &dat, &flag)) < 0)
      err_sys("getmsg error");
    fprintf(stderr, "flag = %d, ctl.len = %d, dat.len = %d\n",
        flag, ctl.len, dat.len);
    if (dat.len == 0)
      exit(0);
    else if (dat.len > 0)
      if (write(STDOUT_FILENO, dat.buf, dat.len) != dat.len)
        err_sys("write error");
  }
}


