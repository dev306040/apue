/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  tsleep2.c
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
 * @brief Figure 10.9 Calling sleep2 from a program that catches other signals
 * @note sleep2 declaration moved to unp.h, 
 * and the the definition will be build into libapue.a
 */

#include "apue.h"

/* unsigned int sleep2(unsigned int); moved to unp.h */
static void sig_int(int);

int tsleep2_main(int argc, char *argv[])
{
  unsigned int unslept;

  if (signal_lib(SIGINT, sig_int) == SIG_ERR)
    err_sys("signal(SIGINT) error");
  unslept = sleep_lib(5);
  printf("sleep2 returned: %u\n", unslept);
  exit(0);
}

static void sig_int(int signo)
{
  int i, j;
  volatile int k;

  /*
   * Tune these loops to run for more than 5 seconds
   * on whatever system this test program is run.
   */

  printf("\nsig_int starting\n");
  for (i = 0; i < 300000; i++)
    for (j = 0; j < 4000; j++)
      k+= i * j;
  printf("sig_int finished\n");
}


