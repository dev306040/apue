/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  openservd1.h
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
 * @brief Figure 17.29 The opend.h header, version 1
 */

#include "apue.h"
#include <errno.h>

#define CL_OPEN "open" /* client's request for server */

extern char errmsg[]; /* error message string to return to client */
extern int oflag; /* open() flag: 0_xxx ... */
extern char *pathname; /* of file to open() for client */

int cli_args(int, char **);
void request(char *, int, int);
