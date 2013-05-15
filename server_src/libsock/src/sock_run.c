

#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libsock.h"
#include "private_libsock.h"
#include "list_wrapper.h"

t_sockserver		*g_server = NULL;

static void		_stop_server(int signum)
{
  if (signum == SIGINT)
    g_server->stop = TRUE;
}

static int		_signal_initialisation(void)
{
  struct sigaction	sigac;

  if (sigemptyset(&sigac.sa_mask) == -1)
    return (perror("signal"), -1);
  sigac.sa_flags = 0;
  sigac.sa_handler = &_stop_server;
  if (sigaction(SIGINT, &sigac, NULL) == -1)
    return (perror("signal"), -1);
  return (0);
}

int			sock_run(uint16_t port, int timeout,
				    void *arg, t_handlers *handlers)
{
  if (g_server || !(g_server = malloc(sizeof(*g_server))))
    return (1);
  bzero(g_server, sizeof(*g_server));
  g_server->handlers = handlers;
  g_server->arg = arg;
  g_server->timeout = timeout;
  if (_signal_initialisation() == -1
      || sock_init(port) == -1)
    return (1);
  while (!g_server->stop)
    {
      sock_accept();
      if (g_server->handlers->treatment
	  && g_server->call_treatment
	  && g_server->handlers->treatment(g_server->arg) == STOP)
	g_server->stop = TRUE;
      g_server->call_treatment = 0;
      if (!g_server->stop)
	{
	  sock_handle();
	  list_foreach(&g_server->users, NULL, sock_reception_handler);
	}
    }
  sock_stop();
  return (0);
}
