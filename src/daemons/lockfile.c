/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  lockfile.c
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
 * @brief Figure 14.9 Place a write lock on an entire file
 */

#include <unistd.h>
#include <fcntl.h>

int
lockfile(int fd)
{
  struct flock fl;

  fl.l_type = F_WRLCK;
  fl.l_start = 0;
  fl.l_whence = SEEK_SET;
  fl.l_len = 0;
  return (fcntl(fd, F_SETLK, &fl));
}


