

#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include "libsock.h"
#include "private_libsock.h"

extern t_sockserver	*g_server;

static int		_create_socket(uint16_t port)
{
  int			sock;
  int			reuse;
  struct sockaddr_in	sin;

  reuse = 1;
  if ((sock = socket(AF_INET, SOCK_STREAM,
		     getprotobyname("TCP")->p_proto)) == -1)
    return (raise_error("socket", -1));
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1)
    perror("setsockopt");
  if (bind(sock, (struct sockaddr*)&sin,
	   sizeof(sin)) == -1)
    {
      if (close(sock) == -1)
	perror("close");
      return (raise_error("bind", FAILURE));
    }
  return (sock);
}

static t_status		_listen_on_socket(int sock)
{
  if (listen(sock, 10) == -1)
    {
      if (close(sock) == -1)
	perror("close");
      return (raise_error("listen", FAILURE));
    }
  return (SUCCESS);
}

int			sock_init(uint16_t port)
{
  if ((g_server->sock = _create_socket(port)) == -1
      || _listen_on_socket(g_server->sock) == FAILURE)
    return (-1);
#ifdef EPOLL_
  if ((g_server->epoll.efd = epoll_create(1)) == -1)
    return (raise_error("epoll_create", g_server->sock));
  if ((sock_add_fd(g_server, g_server->sock, EPOLLIN)) == -1)
    return (raise_error("epoll_ctl", g_server->sock));
  g_server->epoll.epoll = TRUE;
#endif
  if (g_server->handlers->init)
    g_server->handlers->init(g_server->arg);
  return (g_server->sock);
}
