/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  f4_12.c
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
 * @brief Figure 4.2 Example of chmod function
 */

#include "apue.h"

int changemod_main(int argc, char *argv[])
{
  struct stat statbuf;

  if (stat("foo", &statbuf) < 0)
    err_sys("stat error for foo");
  if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
    err_sys("chmod error for foo");

  if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
    err_sys("chmod error for bar");
  exit(0);
}

