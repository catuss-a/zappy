

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libsock.h"
#include "private_libsock.h"

extern t_sockserver	*g_server;

void			sock_free_user(void *ptr)
{
  t_users		*user;

  user = ptr;
  if (close(user->sock) == -1)
    perror("close");
  free(user->rc_buffer);
  free(user->tx_buffer);
}
