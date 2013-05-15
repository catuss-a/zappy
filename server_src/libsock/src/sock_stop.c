

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libsock.h"
#include "private_libsock.h"
#include "list_wrapper.h"

extern t_sockserver	*g_server;

void			sock_stop(void)
{
  t_users		*head;

  head = g_server->users;
  while ((head = list_remove_first(&head, sock_free_user)));
  if (close(g_server->sock) == -1)
    perror("close");
  if (g_server->handlers->stop)
    g_server->handlers->stop(g_server->arg);
  free(g_server);
}
