

#include <stdio.h>
#include "libsock.h"

extern t_sockserver	*g_server;

int			sock_get_elapsed_time(void)
{
  return (g_server->elapsed_time);
}
