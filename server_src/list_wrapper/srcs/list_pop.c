

#include <stdlib.h>
#include "list_wrapper.h"

void		*list_pop(void *ptr, void *head)
{
  if (((t_list *)ptr)->prev)
    ((t_list *)ptr)->prev->next = ((t_list *)ptr)->next;
  else
    *((t_list **)head) = ((t_list *)ptr)->next;
  if (((t_list *)ptr)->next)
    ((t_list *)ptr)->next->prev = ((t_list *)ptr)->prev;
  return (((t_list *)ptr)->next);
}
