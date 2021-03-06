/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  writen.c
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
 * @brief Figure 14.29b The writen function
 */
#include "apue.h"

ssize_t
writen(int fd, const void *ptr, size_t n)
{
  size_t nleft;
  ssize_t nwritten;

  nleft = n;
  while (nleft > 0) {
    if ((nwritten = write(fd, ptr, nleft)) < 0) {
      if (nleft == n)
        return (-1); /* error, return -1 */
      else
        break;  /*  error, return amount written so far */
    } else if (nwritten == 0) {
      break;
    }
    nleft -= nwritten;
    ptr += nwritten;
  }
  return (n - nleft);  /* return >= 0 */
}


