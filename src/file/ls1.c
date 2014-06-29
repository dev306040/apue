/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  apue_f1_3.c
 *
 *         Editor:  vim :set et ts=2 sts=2 sw=2
 *
 *         Author:  Martin Y. Yang , yang@libpix.org
 *
 *    Description:  impl. of apue figure 1.3
 *
 * =============================================================
 */
/**
 * @file
 * @brief Figure 1.3 List all the files in a directory
 */

#include "apue.h"
#include <dirent.h>

int ls1_main(int argc, char *argv[])
{
  DIR *dp;
  struct dirent *dirp;

  if (argc != 2)
    err_quit("usage: apue 1.3 dir_name");
  if ((dp = opendir(argv[1])) == NULL)
    err_sys("can't open %s", argv[1]);
  while ((dirp = readdir(dp)) != NULL)
    printf("%s\n", dirp->d_name);
  closedir(dp);
  exit(0);
}

