

#include <stdlib.h>
#include "list_wrapper.h"

void		*list_pop_front(void *head)
{
  if ((*(t_list **)head)->next)
    (*(t_list **)head)->next->prev = NULL;
  (*(t_list **)head) = (*(t_list **)head)->next;
  return ((*(t_list **)head));
}
