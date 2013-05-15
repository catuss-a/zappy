

#include "libsock.h"
#include "private_libsock.h"
#include "list_wrapper.h"

extern t_sockserver	*g_server;

void			sock_disconnect(t_users *user)
{
  if (g_server->epoll.epoll)
    sock_remove_fd(user->sock);
  g_server->handlers->disconnect(user, g_server->arg);
  list_remove(user, &g_server->users, sock_free_user);
}
