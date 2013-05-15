

#ifndef		CIRC_BUFFER_H_
# define	CIRC_BUFFER_H_

# define CIRC_SIZE (65536)

typedef struct	s_circ_buffer
{
  char		buff[CIRC_SIZE + 1];
  char		read[CIRC_SIZE + 1];
  size_t	read_ndx;
  size_t	write_ndx;
}		t_circ_buffer;

t_circ_buffer*	new_circ_buffer(void);
size_t		write_to_buffer(t_circ_buffer *, char const *);
void		incr_ndx(t_circ_buffer *this, size_t incr);
char		*read_from_buffer(t_circ_buffer *);
char		buffer_is_empty(t_circ_buffer *);
char		buffer_is_ready(t_circ_buffer *);

#endif		
