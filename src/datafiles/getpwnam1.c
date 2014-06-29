/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  getpwnam.c
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
 * @brief Figure 6.2 The getpwnam function
 */

#include <pwd.h>
#include <stddef.h>
#include <string.h>

struct passwd * getpwnam1(const char *name)
{
  struct passwd *ptr;

  getpwent();
  while ((ptr = getpwent()) != NULL)
    if (strcmp(name, ptr->pw_name) == 0)
      break;                                    /* found a match */
  endpwent();
  return ptr;                                   /* ptr is NULL if no match found */
}

