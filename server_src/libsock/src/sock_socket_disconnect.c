

#include "libsock.h"
#include "private_libsock.h"
#include "list_wrapper.h"

extern t_sockserver	*g_server;

void			sock_socket_disconnect(int socket)
{
  t_users		*user;

  if (!(user = list_find_if(&g_server->users, (void*)socket,
			    sock_find_user)))
    return ;
  sock_disconnect(user);
}
