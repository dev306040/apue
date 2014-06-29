/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  f5_11.c
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
 * @brief Figure 5.11 Print buffering for various standard I/O streams
 */

#include "apue.h"

void pr_stdio(const char *, FILE *);

int buf_main(int argc , char *argv[])
{
  FILE *fp;
  fputs("enter any character\n", stdout);
  if (getchar() == EOF)
    err_sys("getchar error");
  fputs("one line to standard error\n", stderr);

  pr_stdio("stdin", stdin);
  pr_stdio("stdout", stdout);
  pr_stdio("stderr", stderr);

  if ((fp = fopen("/etc/motd", "r")) == NULL)
    err_sys("fopen error");
  if (getc(fp) == EOF)
    err_sys("getc error");
  pr_stdio("/etc/motd", fp);
  exit(0);
}

void pr_stdio(const char *name, FILE *fp)
{
  printf("stream = %s, ", name);
  /*
   * The following is nonportable
   */
  if (fp->_IO_file_flags & _IO_UNBUFFERED)
    printf("unbuffered");
  else if (fp->_IO_file_flags & _IO_LINE_BUF)
    printf("line buffered");
  else
    printf("fully buffered");
  printf(", buffer size = %d\n", fp->_IO_buf_end - fp->_IO_buf_base);
}
