/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  f3_2.c
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
 * @brief Figure 3.2 Create a file with a hole in it
 */

#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int hole_main(int argc, char *argv[])
{
  int fd;

  if ((fd = creat("file.hole", FILE_MODE)) < 0)
    err_sys("creat error");

  if(write(fd, buf1, 10) != 10)
    err_sys("buf1 write error");

  if (lseek(fd, 16384, SEEK_SET) == -1)
    err_sys("lseek error");

  if (write(fd, buf2, 10) != 10)
    err_sys("buf2 write error");
  exit(0);
}
