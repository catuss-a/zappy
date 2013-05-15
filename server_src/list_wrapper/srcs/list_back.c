

#include <sys/types.h>
#include "list_wrapper.h"

void		*list_back(void *ptr)
{
  while (ptr && ((t_list *)ptr)->next)
    ptr = ((t_list *)ptr)->next;
  return (ptr);
}
