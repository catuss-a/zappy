

#include <stdlib.h>
#include <strings.h>
#include "libsock.h"
#include "private_libsock.h"
#include "list_wrapper.h"

extern t_sockserver	*g_server;

static void		_set_client_select(void *elem, void *arg)
{
  (void)arg;
  FD_SET(((t_users *)elem)->sock, &g_server->sread);
  if (!buffer_is_empty(((t_users *)elem)->tx_buffer))
    FD_SET(((t_users *)elem)->sock, &g_server->swrite);
}

static int		_get_fd_max(t_users *users)
{
  int			gt;

  gt = g_server->sock;
  while (users)
    {
      if (users->sock > gt)
	gt = users->sock;
      users = (t_users*)users->next;
    }
  return (gt);
}

static void		_handle_select_event(void *elem, void *arg)
{
  t_users		*user;

  user = elem;
  (void)arg;
  if ((user->sock != -1 && FD_ISSET(user->sock, &g_server->sread)))
    {
      g_server->call_treatment = 1;
      if (sock_read_on_socket(user) == FAILURE)
	return;
    }
  if (user->sock != -1 && FD_ISSET(user->sock, &g_server->swrite))
    {
      if (buffer_is_ready(user->tx_buffer))
	sock_write_on_socket(user);
    }
}

t_status		sock_handle_select(void)
{
  struct timeval	t;

  bzero(&t, sizeof(t));
  FD_ZERO(&g_server->sread);
  FD_ZERO(&g_server->swrite);
  FD_SET(g_server->sock, &g_server->sread);
  FD_SET(g_server->sock, &g_server->swrite);
  list_foreach(&g_server->users, NULL, _set_client_select);
  t.tv_usec = g_server->timeout;
  if (select(_get_fd_max(g_server->users) + 1,
	     &g_server->sread, &g_server->swrite, NULL,
	     g_server->timeout != -1 ? &t : NULL) == -1)
    return (raise_error("select", FAILURE));
  g_server->elapsed_time = g_server->timeout - t.tv_usec;
  list_foreach(&g_server->users, NULL, _handle_select_event);
  if (!g_server->elapsed_time)
    g_server->call_treatment = 1;
  else if (!g_server->call_treatment)
    g_server->timeout = t.tv_usec;
  return (SUCCESS);
}
