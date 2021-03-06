

#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "libsock.h"
#include "private_libsock.h"

extern t_sockserver	*g_server;
extern int		errno;

t_status		sock_write_on_socket(t_users* user)
{
 ssize_t		nb_write;
 char			*cmd;

 cmd = read_from_buffer(user->tx_buffer);
 if (!cmd)
   return (FAILURE);
 if (!strlen(cmd))
   return (FAILURE);
 if ((nb_write = send(user->sock, cmd, strlen(cmd), MSG_NOSIGNAL)) == 0
     || (nb_write == -1 && errno != EINTR))
   {
     sock_disconnect(user);
     return (FAILURE);
   }
 else if (nb_write == -1)
   perror("send");
 else
   {
     incr_ndx(user->tx_buffer, nb_write);
     if (g_server->epoll.epoll && !buffer_is_ready(user->tx_buffer))
       sock_mod_fd(user->sock, EPOLLIN);
   }
 return (SUCCESS);
}
