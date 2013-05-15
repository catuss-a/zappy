

#include "libsock.h"
#include "private_libsock.h"

char		sock_find_user(void *ptr, void *arg)
{
  return (((t_users *)ptr)->sock == (int)arg);
}
