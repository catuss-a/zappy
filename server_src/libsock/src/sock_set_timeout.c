

#include "libsock.h"

extern t_sockserver		*g_server;

void		sock_set_timeout(int timeout)
{
  g_server->timeout = timeout;
}
