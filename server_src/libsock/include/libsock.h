

#ifndef		LIBSOCK_H_
# define	LIBSOCK_H_

# include <stdint.h>
# include <sys/types.h>
# include <sys/epoll.h>
# include "circ_buffer.h"

# define MAX_EVENTS	1024

typedef struct s_users		t_users;
typedef struct s_sockserver	t_sockserver;

typedef enum	e_state
  {
    CONTINUE,
    STOP
  }		t_state;

typedef enum	e_bool
  {
    FALSE = 0,
    TRUE
  }		t_bool;

typedef void (*reception_callback)(t_users *, const char *, void *);
typedef void (*accept_callback)(t_users *, void *);
typedef void (*disconnect_callback)(t_users *, void *);
typedef void (*init_handler)(void *);
typedef void (*stop_handler)(void *);
typedef t_state (*treatment_handler)(void *);

typedef struct		s_handlers
{
  reception_callback	reception;
  accept_callback	accept;
  disconnect_callback	disconnect;
  treatment_handler	treatment;
  init_handler		init;
  stop_handler		stop;
}			t_handlers;

struct			s_users
{
  struct s_users	*prev;
  struct s_users	*next;
  int			sock;
  t_circ_buffer		*rc_buffer;
  t_circ_buffer		*tx_buffer;
  char			error;
};

typedef struct		s_epoll
{
  int			efd;
  struct epoll_event	events[MAX_EVENTS];
  t_bool		epoll;
  t_bool		new_client;
}			t_epoll;

struct			s_sockserver
{
  int			sock;
  t_users		*users;
  fd_set		sread;
  fd_set		swrite;
  char			call_treatment;
  void			*arg;
  t_bool		stop;
  t_epoll		epoll;
  t_handlers		*handlers;
  int			timeout;
  int			elapsed_time;
};

int		sock_run(uint16_t port, int timeout,
			 void *arg, t_handlers *handlers);
int		sock_send(int sock, char const *msg);
int		sock_get_elapsed_time(void);
void		sock_set_timeout(int timeout);
int		sock_get_timeout(void);
void		sock_socket_disconnect(int socket);
void		sock_disconnect(t_users *user);
int		sock_handle(void);

#endif		
