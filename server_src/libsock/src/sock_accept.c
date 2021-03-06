

#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <sys/epoll.h>
#include "libsock.h"
#include "private_libsock.h"
#include "list_wrapper.h"

extern t_sockserver		*g_server;

static int			_accept_new_client(void)
{
  int				client;
  t_users			*new;
  static struct sockaddr_in	csin;
  static socklen_t		size;

  client = -1;
  g_server->epoll.new_client = FALSE;
  if ((client = accept(g_server->sock, (struct sockaddr*)&csin, &size)) == -1)
    return (raise_error("accept", -1));
  if (!(new = list_cpush_back(&g_server->users, sizeof(*new))))
    {
      if (close(client) == -1)
	perror("close");
      return (-1);
    }
  new->sock = client;
  if (!(new->rc_buffer = new_circ_buffer())
      || !(new->tx_buffer = new_circ_buffer())
      || (g_server->epoll.epoll && sock_add_fd(client, EPOLLIN) == -1))
    {
      sock_disconnect(new);
      return (-1);
    }
  g_server->handlers->accept(new, g_server->arg);
  return (client);
}

int			sock_accept(void)
{
  if ((g_server->epoll.epoll && g_server->epoll.new_client)
      || (!g_server->epoll.epoll
	  && FD_ISSET(g_server->sock, &g_server->sread)))
    return (_accept_new_client());
  return (-1);
}
