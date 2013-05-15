

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include "list_wrapper.h"

void		*list_push_front(void *new, void *head)
{
  if (new == NULL)
    {
      fprintf(stderr, "Error: list_wrapper:"
	      "list_push_front won't insert a NULL element");
      return (NULL);
    }
  ((t_list *)new)->prev = NULL;
  ((t_list *)new)->next = *(t_list **)head;
  if (((t_list *)new)->next)
    ((t_list *)new)->next->prev = new;
  return ((*(t_list **)head = new));
}
