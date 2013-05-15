

#include <sys/types.h>
#include "list_wrapper.h"

void		*list_at(unsigned int pos, void *head)
{
  t_list	*parse;

  parse = *(t_list **)head;
  while (parse && parse->next && pos)
    {
      parse = parse->next;
      --pos;
    }
  return (parse);
}
