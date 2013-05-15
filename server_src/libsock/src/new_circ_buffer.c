

#include <stdlib.h>
#include <string.h>

#include "circ_buffer.h"

t_circ_buffer*	new_circ_buffer(void)
{
  t_circ_buffer	*this;

  this = (t_circ_buffer*)malloc(sizeof(t_circ_buffer));
  if (this == NULL)
    return (NULL);
  bzero(this, sizeof(*this));
  return (this);
}
