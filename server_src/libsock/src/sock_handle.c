

#include "libsock.h"
#include "private_libsock.h"

t_sockserver		*g_server;

int			sock_handle(void)
{
  if (!g_server->epoll.epoll)
    sock_handle_select();
  else
    sock_handle_epoll();
  return (0);
}
