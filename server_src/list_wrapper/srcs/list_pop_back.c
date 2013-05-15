

#include <stdlib.h>
#include "list_wrapper.h"

void		*list_pop_back(void *head)
{
  t_list	*ptr;

  ptr = list_back(*(t_list **)head);
  if (ptr == NULL || ptr->prev == NULL)
    return ((*(t_list **)head = NULL));
  ptr->prev->next = ptr->next;
  return (ptr->prev);
}
