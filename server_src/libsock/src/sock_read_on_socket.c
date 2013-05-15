

#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <errno.h>
#include "libsock.h"
#include "private_libsock.h"

extern t_sockserver	*g_server;
extern int		errno;

t_status		sock_read_on_socket(t_users* user)
{
  static char		buffer[4096];
  ssize_t		nb_read;

  bzero(buffer, sizeof(buffer));
  if ((nb_read = read(user->sock, buffer, 4096)) == -1
      && errno == EINTR)
    user->error = raise_error("read", TRUE);
  else if (nb_read <= 0)
    {
      if (nb_read == -1)
	perror("read");
      sock_disconnect(user);
      return (FAILURE);
    }
  else
    write_to_buffer(user->rc_buffer, buffer);
  return (SUCCESS);
}
