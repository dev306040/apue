/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  cmd2.c
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
 * @brief Figure 7.11 Example of setjmp and longjmp
 * @note This is not a runable program, just a code list
 */

#include "apue.h"
#include <setjmp.h>

#define TOK_ADD 5

int cmd2_main(int argc, char *argv[])
{
  char line[MAXLINE];

  if (setjmp(jmpbuffer) != 0)
    printf("error");
  while (fgets(line, MAXLINE, stdin) != NULL)
    do_line(line);
  exit(0);
}

. . .

void cmd_add(void)
{
  int token;

  token = get_token();
  if(token < 0)                                 /* an error has occured */
    longjmp(jmpbuffer, 1);
  /* reset of processing for this command */
}
