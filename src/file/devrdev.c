/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  f4_25.c
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
 * @brief Figure 4.25 Print st_dev and st_rdev values
 */
#define _BSD_SOURCE
#include "apue.h"
#ifdef SOLARIS
#include <sys/mkdev.h>
#endif


int devrdev_main(int argc, char *argv[])
{
  int i;
  struct stat buf;

  for (i = 1; i < argc; i++) {
    printf("%s: ", argv[i]);
    if (stat(argv[i], &buf) < 0) {
      err_ret("stat error");
      continue;
    }
    printf("dev = %d/%d", major(buf.st_dev), minor(buf.st_dev));
    if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode)) {
      printf(" (%s) rdev = %d/%d",
          (S_ISCHR(buf.st_mode)) ? "character" : "block",
          major(buf.st_rdev), minor(buf.st_rdev));
    }
    printf("\n");
  }
  exit(0);
}


