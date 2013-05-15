

#include <stdlib.h>
#include "libsock.h"
#include "private_libsock.h"

extern t_sockserver	*g_server;

int			sock_remove_fd(int sock)
{
  if (epoll_ctl(g_server->epoll.efd, EPOLL_CTL_DEL, sock, NULL) == -1)
    return (raise_error("epoll_ctl", -1));
  return (0);
}
