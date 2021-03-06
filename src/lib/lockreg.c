/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  lockreg.c
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
 * @brief Figure 14.5 Function to lock or unlock a region of a file
 */

#include "apue.h"
#include <fcntl.h>

int
lock_reg(int fd, int cmd, int type, off_t offset, int whence, off_t len)
{
  struct flock lock;

  lock.l_type = type;     /* F_RDLCK, F_WRLCK, F_UNLCK  */
  lock.l_start = offset;  /* byte offset, relative to l_whence */
  lock.l_whence = whence; /* SEEK_SET, SEEK_CUR, SEEK_END */
  lock.l_len = len;       /* #bytes (0 means to EOF) */
  return (fcntl(fd, cmd, &lock));
}

