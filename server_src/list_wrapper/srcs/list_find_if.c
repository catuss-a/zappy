

#include <stdlib.h>
#include "list_wrapper.h"

void		*list_find_if(void *head, void *arg,
			      char (*predicate)(void *ptr, void *arg))
{
  t_list	*parse;

  parse = *(t_list **)head;
  while (parse)
    {
      if (predicate(parse, arg) != 0)
	return (parse);
      parse = parse->next;
    }
  return (NULL);
}
