

#include <stdlib.h>
#include "memory_pool.h"
#include "libsock.h"
#include "private_libsock.h"

extern t_sockserver	*g_server;

void			sock_reception_handler(void *ptr, void *arg)
{
  t_users		*user;
  char			*cmd;

  cmd = NULL;
  user = ptr;
  (void)arg;
  cmd = sock_receive(user->sock);
  if (cmd)
    {
      if (g_server->handlers->reception)
	g_server->handlers->reception(user, cmd, g_server->arg);
    }
}
