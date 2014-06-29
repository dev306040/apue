/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  lib.c
 *
 *         Editor:  vim :set et ts=2 sts=2 sw=2
 *
 *         Author:  Martin Y. Yang , yang@libpix.org
 *
 *    Description:  
 *
 * =============================================================
 */

/*
 * @file
 * @brief Support multi-version functions
 */

#include "apue.h"
#include <stdlib.h>
#include <string.h>

int system1(const char *cmd);                   /* Figure 8.22 */
int system2(const char *cmd);                   /* Figure 10.28 */

int system_lib(const char *cmd)
{
  const char * ver = getenv("system");
  if (!ver) {
    ver = getenv("figure");
    if (!ver)
      err_sys("no figure env");
    ver = "ansi";
  }
  if (getenv("verbose")) printf("system=%s\n", ver);

  if (strcmp(ver , "8.22") == 0) return system1(cmd);
  if (strcmp(ver , "10.22") == 0) return system2(cmd);
  return system(cmd);
}


unsigned int sleep1(unsigned sec);              /* Figure 10.7 */
unsigned int sleep2(unsigned sec);              /* Figure 10.8 */
unsigned int sleep3(unsigned sec);              /* Figure 10.29 */

unsigned int sleep_lib(unsigned sec)
{
  const char *ver = getenv("sleep");
  if (!ver) {
    ver = getenv("figure");
    if (!ver)
      err_sys("no figure env");
    if (strcmp(ver, "10.9") == 0) return sleep2(sec);
  }
  if (getenv("verbose")) printf("sleep=%s\n", ver);
  if (strcmp(ver, "10.7") == 0) return sleep1(sec);
  if (strcmp(ver, "10.8") == 0) return sleep2(sec);
  if (strcmp(ver, "10.29") == 0) return sleep3(sec);
  return sleep(sec);
}

void abort1(void);                               /* Figure 10.25 */

void abort_lib(void)
{
  const char *ver = getenv("abort");
  if (!ver) {
    ver = getenv("figure");
    if (!ver)
      err_sys("no figure env");
  }
  if (getenv("verbose")) printf("sleep=%s\n", ver);
  if (strcmp(ver, "10.25")) abort1();
  else abort();
}

Sigfunc *signal1(int signo, Sigfunc *func);     /* Figure 10.18 */
Sigfunc *signal_intr(int signo, Sigfunc *func); /* Figure 10.19 */

Sigfunc *signal_lib(int signo, Sigfunc *func)
{
  const char *ver = getenv("signal");
  if (!ver) {
    ver = getenv("figure");
    if (!ver)
      err_sys("no figure env");
  }
  if (getenv("verbose")) printf("signal=%s\n", ver);
  if (strcmp(ver, "10.18") == 0) return signal1(signo , func);
  if (strcmp(ver , "10.19") == 0) return signal_intr(signo, func);
  return signal(signo, func);
}
struct passwd * getpwnam1(const char *name);
struct passwd * getpwnam_lib(const char *name)
{
  const char *ver = getenv("getpwnam");
  if (!ver) {
    ver = getenv("figure");
    if (!ver) err_sys("no figure env");
  }
  if (getenv("verbose")) printf("getpwnam=%s\n", ver);
  if (strcmp(ver, "6.2") == 0) return getpwnam1(name);
  return getpwnam(name);

}

