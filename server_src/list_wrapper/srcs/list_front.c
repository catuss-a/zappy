

#include <sys/types.h>
#include "list_wrapper.h"

void		*list_front(void *ptr)
{
  while (ptr && ((t_list *)ptr)->prev)
    ptr = ((t_list *)ptr)->prev;
  return (ptr);
}
