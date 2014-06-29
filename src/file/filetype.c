/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  f4_3.c
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
 * @brief Figure 4.3 Print type of file for each command-line argument
 */

#include "apue.h"

int filetype_main(int argc, char *argv[])
{
  int i;
  struct stat buf;
  char *ptr;

  for (i = 1; i < argc; i++) {
    printf("%s: ", argv[i]);
    if (lstat(argv[i], &buf) < 0) {
      err_ret("lstat error");
      continue;
    }
    if (S_ISREG(buf.st_mode))
      ptr = "regular";
    else if (S_ISDIR(buf.st_mode))
      ptr = "directory";
    else if (S_ISCHR(buf.st_mode))
      ptr = "character special";
    else if (S_ISBLK(buf.st_mode))
      ptr = "block special";
    else if (S_ISFIFO(buf.st_mode))
      ptr = "fifo";
    else if (S_ISLNK(buf.st_mode))
      ptr = "symbolic link";
    else if (S_ISSOCK(buf.st_mode))
      ptr = "socket";
    else
      ptr = "** unknown mode **";
    printf("%s\n", ptr);
  }
  exit(0);
}
