

#include <stdlib.h>
#include "list_wrapper.h"

void		*list_remove_first(void *head, void (*removeFunction)(void *ptr))
{
  void		*save;

  if (!*(t_list **)head)
    return (NULL);
  if (removeFunction != NULL)
    removeFunction(*(t_list **)head);
  save = *(t_list **)head;
  list_pop_front(head);
  free(save);
  return (*(t_list **)head);
}
