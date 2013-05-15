

#include <stdio.h>
#include <stdlib.h>
#include "libsock.h"
#include "private_libsock.h"
#include "list_wrapper.h"

extern t_sockserver	*g_server;

int			sock_send(int sock, char const *msg)
{
  t_users		*user;

  if (!(user = list_find_if(&g_server->users, (void*)sock,
			       sock_find_user)))
    return (-1);
  write_to_buffer(user->tx_buffer, msg);
  return (0);
}
