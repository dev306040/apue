/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  isastream.c
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
 * @brief Figure 14.16 Check if descriptor is a STREAMS device
 */
#include <stropts.h>
#include <unistd.h>

int
isastream(int fd)
{
  return (ioctl(fd, I_CANPUT, 0) != -1 );
}

