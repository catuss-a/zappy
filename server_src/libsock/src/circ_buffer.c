

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "libsock.h"
#include "circ_buffer.h"

size_t	write_to_buffer(t_circ_buffer *this, char const *msg)
{
  size_t	ndx;

  ndx = 0;
  while (msg[ndx])
    {
      if (this->write_ndx == CIRC_SIZE)
      	this->write_ndx = 0;
      this->buff[this->write_ndx] = msg[ndx];
      ++this->write_ndx;
      ++ndx;
    }
  return (ndx);
}

char	*read_from_buffer(t_circ_buffer *this)
{
  size_t	ndx;
  size_t	tmp_read_ndx;

  ndx = 0;
  tmp_read_ndx = this->read_ndx;
  bzero(this->read, CIRC_SIZE + 1);
  if (tmp_read_ndx > this->write_ndx)
    {
      while (tmp_read_ndx < CIRC_SIZE)
	{
	  this->read[ndx] = this->buff[tmp_read_ndx++];
	  if (this->read[ndx] == '\n')
	    return (this->read);
	  ++ndx;
	}
      tmp_read_ndx = 0;
    }
  while (tmp_read_ndx < this->write_ndx)
    {
      this->read[ndx] = this->buff[tmp_read_ndx++];
      if (this->read[ndx] == '\n')
	return (this->read);
      ++ndx;
    }
  return (this->read);
}

char	buffer_is_empty(t_circ_buffer *this)
{
  return (this->write_ndx == this->read_ndx);
}

char		buffer_is_ready(t_circ_buffer *this)
{
  size_t	ndx;

  ndx = this->read_ndx;
  if (ndx > this->write_ndx)
    {
      while (ndx < CIRC_SIZE)
	{
	  if (this->buff[ndx] == '\n')
	    return (TRUE);
	  ++ndx;
	}
      ndx = 0;
    }
  while (ndx < this->write_ndx)
    {
      if (this->buff[ndx] == '\n')
	return (TRUE);
      ++ndx;
    }
  return (FALSE);
}

void		incr_ndx(t_circ_buffer *this, size_t incr)
{
  while (incr)
    {
      if (this->read_ndx == CIRC_SIZE)
	this->read_ndx = 0;
      else
	++this->read_ndx;
      --incr;
    }
}
