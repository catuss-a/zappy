

#include <stdio.h>
#include "libsock.h"
#include "private_libsock.h"
#include "list_wrapper.h"

t_sockserver	*g_server;

static void	_set_epollout(void *elem, void *arg)
{
  t_users	*user;

  user = elem;
  (void)arg;
  if (buffer_is_ready(user->tx_buffer))
    sock_mod_fd(user->sock, EPOLLIN | EPOLLOUT);
}

static int	_get_event(void)
{
  int		nb_events;

  if ((nb_events = epoll_wait(g_server->epoll.efd, g_server->epoll.events,
			      MAX_EVENTS, g_server->timeout / 1000)) == -1)
    perror("epoll_wait");
  return (nb_events);
}

void		sock_handle_epoll(void)
{
  int		i;
  int		sock;
  int		nb_events;
  t_users	*user;

  i = -1;
  nb_events = _get_event();
  while (++i < nb_events)
    {
      sock = g_server->epoll.events[i].data.fd;
      if (sock == g_server->sock &&
	  (g_server->epoll.events[i].events & EPOLLIN))
	g_server->epoll.new_client = TRUE;
      else if (sock != -1 && (user = list_find_if(&g_server->users,
						     (void *)sock,
						     sock_find_user)))
	if (((g_server->epoll.events[i].events & EPOLLIN)
	     && sock_read_on_socket(user) == FAILURE)
	    || ((g_server->epoll.events[i].events & EPOLLOUT)
		&& sock_write_on_socket(user) == FAILURE))
	  return ;
    }
  list_foreach(&g_server->users, NULL, _set_epollout);
}
