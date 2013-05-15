

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include "list_wrapper.h"

void		*list_push_back(void *new, void *head)
{
  t_list	*parse;

  if (new == NULL)
    {
      fprintf(stderr, "Error: list_wrapper:"
	      "list_push_back won't insert a NULL element");
      return (NULL);
    }
  parse = *(t_list **)head;
  if (parse == NULL)
    {
      ((t_list *)new)->prev = NULL;
      ((t_list *)new)->next = NULL;
      return ((*(t_list **)head = new));
    }
  while (parse->next)
    parse = parse->next;
  ((t_list *)new)->prev = parse;
  ((t_list *)new)->next = NULL;
  parse->next = new;
  return (new);
}
