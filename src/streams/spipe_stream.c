/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  spipe.c
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
 * @brief Figure 17.6 STREAMS version of the s_pipe function
 */

#include "apue.h"
/*
 * Returns a STREAMS-based pipe, with the two file descriptors
 * return in fd[0] and fd[1].
 */

int
s_pipe(int fd[2])
{
  return(pipe(fd));
}
