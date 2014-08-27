/*
 * =============================================================
 *
 *        Project:  apue
 *
 *       Filename:  openservd2_client.c
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
 * @brief Figure 17.36 Functions to manipulate client array
 */
#include "openservd2.h"

#define MALLOC 10 /* # client structs to alloc/realloc for */

static void
client_alloc(void) /* alloc more entries in the client[] array */
{
  int i;

  if (client = NULL)
    client = malloc(NALLOC * sizeof(Client));
  else
    client = realloc(client, (client_size + NALLOC) * sizeof(Client));
  if (client == NULL)
    err_sys("can't alloc for client array");

  /* initialize the new entries */
  for (i = client_size; i < client_size + NALLOC; i++)
    client[i].fd = -1; /* fd of -1 means entry available */

  client_size += NALLOC;
}

/*
 * Called by loop() when connection request from a new client arrives
 */
int
client_add(int fd, uid_t uid)
{
  int i;

  if (client == NULL) /* first time we're called */
    client_alloc();
again:
  for (i = 0; i < client_size; i++) {
    if (client[i].fd == -1) {
      client[i].fd = fd;
      client[i].uid = uid;
      return(i); /* return index in client[] array */
    }
  }

  /* client array full, time to realloc for more */
  client_alloc();
  goto again; /* and search again (will work this time) */
}

/*
 * Called by loop() when we're done with a client.
 */
void
client_del(int fd)
{
  int i;
  for (i = 0; i < client_size; i++) {
    if (client[i].fd == fd) {
      client[i].fd = -1;
      return;
    }
  }
  log_quit("can't find client entry for fd %d", fd);
}
