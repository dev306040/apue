/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  getenv1.c
 *
 *         Editor:  vim :set et ts=2 sts=2 sw=2
 *
 *         Author:  Martin Y. Yang , yang@libpix.org
 *
 *    Description:  
 *
 * =============================================================
 */

#include <limits.h>
#include <string.h>

static char envbuf[ARG_MAX];

extern char **environ;

char *
getenv(const char *name)
{
  int i, len;
  
  len = strlen(name);
  for (i = 0; environ[i] != NULL; i++) {
    if ((strncmp(name, environ[i], len) == 0) &&
        (environ[i][len] == '=')) {
      strcpy(envbuf, &environ[i][len+1]);
      return envbuf;
    }
  }
  return NULL;
}

