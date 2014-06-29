/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  f2_16.c
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
 * @brief Figure 2.16 Determine the number of file descriptors
 */
#include "apue.h"
#include <errno.h>
#include <limits.h>

#ifdef OPEN_MAX
static long openmax = OPEN_MAX;
#else
static long openmax = 0;
#endif
/*
 * @note If OPEN_MAX is indeterminate, we're not
 * guaranteed that this is adequate
 */

#define OPEN_MAX_GUESS 256

long open_max(void)
{
  if (openmax == 0) {
    errno = 0;
    if ((openmax = sysconf(_SC_OPEN_MAX)) < 0) {
      if (errno == 0)
        openmax = OPEN_MAX_GUESS;
      else
        err_sys("sysconf error for _SC_OPEN_MAX");
    }
  }
  return openmax;
}
