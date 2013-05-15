

#include <stdlib.h>
#include "list_wrapper.h"

void		*list_remove(void *ptr, void *head,
				void (*removeFunction)(void *ptr))
{
  void		*next;

  if (!(t_list *)ptr)
    return (NULL);
  if (removeFunction != NULL)
    removeFunction(ptr);
  next = list_pop(ptr, head);
  free(ptr);
  return (next);
}
