/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  threadid.c
 *
 *         Editor:  vim :set et ts=2 sts=2 sw=2
 *
 *         Author:  Martin Y. Yang , yang@libpix.org
 *
 *    Description:  
 *
 * =============================================================
 *
 */

/**
 * @file
 * @brief Figure 11.2 Printing thread IDs
 */


#include "apue.h"
#include <pthread.h>

pthread_t ntid;

void printids(const char *s)
{
  pid_t pid;
  pthread_t tid;

  pid = getpid();
  tid = pthread_self();
  printf("%s pid %u tid %u (0x%x)\n", s , (unsigned int) pid,
      (unsigned int) tid, (unsigned int) tid);

}

void * thr_fn(void *arg)
{
  printids("new thread: ");
  return 0;
}

int threadid_main(int argc , char *argv[])
{
  int err;

  err = pthread_create(&ntid, NULL, thr_fn, NULL);
  if (err != 0)
    err_quit("can't create thread: %s\n", strerror(err));
  printids("main thread: ");
  sleep(1);
  exit(0);
}
