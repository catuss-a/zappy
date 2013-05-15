

#include <strings.h>
#include "libsock.h"
#include "private_libsock.h"

extern t_sockserver	*g_server;

int			sock_add_fd(int sock, int mod)
{
  struct epoll_event	event;

  bzero(&event, sizeof(event));
  event.data.fd = sock;
  event.events = mod;
  if (epoll_ctl(g_server->epoll.efd, EPOLL_CTL_ADD, sock, &event) == -1)
    return (raise_error("epoll_ctl", -1));
  return (0);
}
