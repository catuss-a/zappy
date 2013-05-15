

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "list_wrapper.h"

void		*list_create(size_t size)
{
  void		*new;

  if ((new = malloc(size)) == NULL)
    {
      perror("list_wrapper: malloc");
      return (NULL);
    }
  bzero(new, size);
  return (new);
}
