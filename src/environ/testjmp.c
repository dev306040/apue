/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  testjmp.c
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
 * @brief Figure 7.13 Effect of longjmp on various types of variables
 */

#include "apue.h"
#include <setjmp.h>

static void f1(int, int, int, int);
static void f2(void);

static jmp_buf jmpbuffer;
static int globval;

int testjmp_main(int argc, char *argv[])
{
  int autoval;
  register int regival;
  volatile int volaval;
  static int statval;
  globval = 1; autoval = 2; regival = 3; volaval = 4; statval = 5;

  if (setjmp(jmpbuffer) != 0) {
    printf("after longjmp:\n");
    printf("globval = %d, autoval = %d, regival = %d,"
        " volaval = %d, statval = %d\n", 
        globval, autoval, regival, volaval, statval);
    exit(0);
  }

  /*
   * Change variables after setjmp, but before longjmp.
   */
  globval = 95; autoval = 96; regival = 97; volaval = 98;
  statval = 99;

  f1(autoval, regival, volaval, statval);       /* never return */
  exit(0);

}

static void f1(int i, int j, int k, int l)
{
  printf("in f1():\n");
  printf("globval = %d, autoval = %d, regival = %d,"
      " volaval = %d, statval = %d\n", 
      globval, i, j, k, l);
  f2();
}

static void f2(void)
{
  longjmp(jmpbuffer, 1);
}


