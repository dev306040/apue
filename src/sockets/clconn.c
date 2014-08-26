/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  clconn.c
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
 * @brief Figure 16.9 Connect with retry
 */

#define MAXSLEEP 128

int
connect_retry(int sockfd, const struct sockaddr *addr, socklen_t alen)
{
  int nsec;
  /*
   * Try to connect with exponential backoff.
   */
  for (nsec = 1; nsec <= MAXSLEEP; nsec <<= 1) {
    if (connect(sockfd, addr, alen) == 0) {
      /*
       * Connection accpted.
       */
      return(0);
    }
    /*
     * Delay before trying again.
     */
    if (nsec <= MAXSLEEP/2)
      sleep(nsec);
  }
  return(-1);
}




