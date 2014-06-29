/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  reenter.c
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
 * @brief Figure 10.5 Call a nonreentrant function from a signal handler
 */

#include "apue.h"
#include <pwd.h>

static void my_alarm(int signo)
{
  struct passwd *rootptr;

  printf("in signal handler\n");
  if ((rootptr = getpwnam_lib("root")) == NULL)
    err_sys("getpwnam(root) error");
  alarm(1);
}

int reenter_main(int argc, char *argv[])
{
  struct passwd *ptr;

  signal(SIGALRM, my_alarm);
  alarm(1);
  for ( ; ; ) {
    if ((ptr = getpwnam_lib("sar")) == NULL)
      err_sys("getpwnam error");
    if (strcmp(ptr->pw_name, "sar") != 0)
      printf("return value corrupted!, pw_name = %s\n", ptr->pw_name);

  }
}

