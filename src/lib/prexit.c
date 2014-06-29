/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  prexit.c
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
 * @brief Figure 8.5 Print a description of the exit status
 * @note I modified some lines of original code list.
 */

#include "apue.h"
#include <sys/wait.h>

void pr_exit(int status)
{
  if (WIFEXITED(status))
    printf("normal termination, exit status = %d\n",
        WEXITSTATUS(status));
  else if (WIFSIGNALED(status))
    printf("abnormal termination, signal number = %d%s\n",
        WTERMSIG(status),
#ifdef WCOREDUMP
        WCOREDUMP(status) ? " (core file generated)" : ""
#else
        ""
#endif
        );
  else if (WIFSTOPPED(status))
    printf("child stopped, signal number = %d\n",
        WSTOPSIG(status));
        
}


