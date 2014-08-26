/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  readn.c
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
 * @brief Figure 14.29a The readn function
 */
#include "apue.h"

/* Read "n" bytes from a descriptor */
ssize_t
readn(int fd, void *ptr, size_t n)
{
  size_t nleft;
  ssize_t nread;

  nleft = n;
  while (nleft > 0) {
    if ((nread = read(fd, ptr, nleft)) < 0) {
      if (nleft == n)
        return (-1); /* error, return -1 */
      else
        break; /* error, return amount read so far */
    } else if (nread == 0) {
      break;  /* EOF */
    }
    nleft -= nread;
    ptr += nread;
  }
  return (n - nleft);  /* return >= 0 */
}


