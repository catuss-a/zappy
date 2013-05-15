

#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "list_wrapper.h"

void		*list_push_insert(void *new, void *current, void *head)
{
  if (new == NULL)
    {
      fprintf(stderr, "Error: list_wrapper:"
	      "list_push_insert won't insert a NULL element");
      return (NULL);
    }
  if (current == NULL)
    {
      bzero(new, sizeof(t_list));
      return ((*(t_list **)head = new));
    }
  ((t_list *)new)->prev = current;
  ((t_list *)new)->next = ((t_list *)current)->next;
  if (((t_list *)new)->next)
    ((t_list *)new)->next->prev = new;
  ((t_list *)current)->next = new;
  return (new);
}
