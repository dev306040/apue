/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  locktest.c
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
 * @brief Figure 14.6 Function to test for a locking condition
 */
#include "apue.h"
#include <fcntl.h>

pid_t
lock_test(int fd, int type, off_t offset, int whence, off_t len)
{
  struct flock lock;

  lock.l_type = type;     /* F_RDLCK of F_WRLCK */
  lock.l_start = offset;  /* byte offset, relative to l_whence */
  lock.l_whence = whence; /* SEEK_SET, SEEK_CUR, SEEK_END */
  lock.l_len = len;       /* #bytes (0 means to EOF) */

  if (fcntl(fd, F_GETLK, &lock) < 0)
    err_sys("fcntl error");

  if (lock.l_type == F_UNLCK)
    return(0);  /* false, region isn't locked by another proc */
  return (lock.l_pid); /* true, return pid of lock owner */
}



