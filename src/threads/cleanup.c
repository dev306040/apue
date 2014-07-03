/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  cleanup.c
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
 * @brief Figure 11.5  Thread cleanup handler
 */

#include "apue.h"
#include <pthread.h>

static void cleanup(void *arg)
{
  printf("cleanup: %s\n", (char *) arg);
}

static void * thr_fn1(void *arg)
{
  printf("thread 1 start\n");
  pthread_cleanup_push(cleanup, "thread 1 first handler");
  pthread_cleanup_push(cleanup, "thread 1 second handler");
  printf("thread 1 push complete\n");
  if (arg)
    return (void *) 1;
  pthread_cleanup_pop(0);
  pthread_cleanup_pop(0);
  return (void *) 1;
}

static void * thr_fn2(void *arg)
{
  printf("thread 2 start\n");
  pthread_cleanup_push(cleanup, "thread 2 first handler");
  pthread_cleanup_push(cleanup, "thread 2 second handler");
  printf("thread 2 push complete\n");
  if (arg)
    pthread_exit((void *) 2);
  pthread_cleanup_pop(0);
  pthread_cleanup_pop(0);
  pthread_exit( (void *) 2);
}

int cleanup_main(int argc, char *argv[])
{
  int err;
  pthread_t tid1, tid2;
  void *tret;

  err = pthread_create(&tid1, NULL, thr_fn1, (void *) 1);
  if (err != 0)
    err_quit("can't create thread 1: %s\n", strerror(err));
  err = pthread_create(&tid2, NULL, thr_fn2, (void *) 1);
  if (err != 0)
    err_quit("can't create thread 2: %s\n", strerror(err));
  err = pthread_join(tid1, &tret);
  if (err != 0)
    err_quit("can't join with thread 1: %s\n", strerror(err));
  printf("thread 1exit code %d\n", (int) tret);
  err = pthread_join(tid2, &tret);
  if (err != 0)
    err_quit("can't join with thread 2: %s\n", strerror(err));
  printf("thread 2 exit code %d\n", (int)tret);
  exit(0);
}
