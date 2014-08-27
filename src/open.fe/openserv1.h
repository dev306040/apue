/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  open.h
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
 * @brief Figure 17.26 The open.h header
 */
#include "apue.h"
#include <errno.h>

#define CL_OPEN "open" /* client's request for server */

int csopen(char *, int);

