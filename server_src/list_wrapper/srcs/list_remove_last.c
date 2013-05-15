

#include <stdlib.h>
#include "list_wrapper.h"

void		*list_remove_last(void *head, void (*removeFunction)(void *ptr))
{
  void		*prev;
  void		*back;

  if (!*(t_list **)head)
    return (NULL);
  if (removeFunction != NULL)
    removeFunction(*(t_list **)head);
  back = list_back(*(t_list **)head);
  prev = list_pop_back(head);
  free(back);
  return (prev);
}
