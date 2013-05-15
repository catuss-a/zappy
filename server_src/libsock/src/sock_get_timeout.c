

#include <stdio.h>
#include "libsock.h"

extern t_sockserver	*g_server;

int			sock_get_timeout(void)
{
  return (g_server->timeout);
}
