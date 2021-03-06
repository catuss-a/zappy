

#ifndef		PRIVATE_LIBSOCK_H_
# define	PRIVATE_LIBSOCK_H_

# define BUFFSIZE	4096

typedef enum	e_status
  {
    FAILURE = 0,
    SUCCESS
  }		t_status;

int		raise_error(char *binary, int return_value);

t_status	sock_handle_select(void);
t_status	sock_read_on_socket(t_users* user);
t_status	sock_write_on_socket(t_users* user);
void		sock_free_user(void *user);
int		sock_init(uint16_t reuse);
int		sock_accept(void);
char		*sock_receive(int sock);
void		sock_reception_handler(void *ptr, void *arg);
void		sock_stop(void);
int		sock_add_fd(int sock, int mod);
int		sock_remove_fd(int sock);
int		sock_mod_fd(int sock, int mod);
void		sock_handle_epoll(void);
char		sock_find_user(void *ptr, void *arg);

#endif		
