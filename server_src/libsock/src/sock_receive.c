

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libsock.h"
#include "private_libsock.h"
#include "list_wrapper.h"

extern t_sockserver	*g_server;

char			*sock_receive(int sock)
{
  char			*rcv;
  t_users		*user;

  if (!(user = list_find_if(&g_server->users, (void*)sock,
			       sock_find_user)))
    return (NULL);
  if (buffer_is_ready(user->rc_buffer))
    {
      if ((rcv = read_from_buffer(user->rc_buffer)))
	incr_ndx(user->rc_buffer, strlen(rcv));
      return (rcv);
    }
  return (NULL);
}
