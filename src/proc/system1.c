/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  system.c
 *
 *         Editor:  vim :set et ts=2 sts=2 sw=2
 *
 *         Author:  Martin Y. Yang , yang@libpix.org
 *
 *    Description:  :
 *
 * =============================================================
 */

/**
 * @file
 * @brief Figure 8.22 The system function, without signal handling
 * @note The original system function name conflicts with standard library,
 * we add _apue suffix to it. 
 */

#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>

int system1(const char *cmdstring)              /* version without signal handling */
{
  pid_t pid;
  int status;

  if (cmdstring == NULL)
    return 1;                                   /* always a command processor with UNIX */

  if ((pid = fork()) < 0) {
    status = -1;                                /* probably out of processes */
  } else if (pid == 0) {                        /* child */
    execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
    _exit(127);                                 /* execl error */
  } else {
    while (waitpid(pid, &status, 0) < 0) {
      if (errno != EINTR) {
        status = -1;                            /* error other than EINTR from waitpid() */
        break;
      }
    }
  }
  return status;
}

