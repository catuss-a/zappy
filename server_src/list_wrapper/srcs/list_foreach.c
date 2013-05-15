

#include <stdlib.h>
#include "list_wrapper.h"

void		list_foreach(void *head, void *arg,
			     void (*functor)(void *ptr, void *arg))
{
  t_list	*parse;
  t_list	*next;

  parse = *(t_list **)head;
  while (parse)
    {
      next = parse->next;
      functor(parse, arg);
      parse = next;
    }
}
