

#include <sys/types.h>
#include <stdlib.h>
#include "list_wrapper.h"

void		*list_cpush_insert(void *current, void *head, size_t size)
{
  t_list	*rnew;

  if ((rnew = list_create(size)) == NULL)
    return (NULL);
  return (list_push_insert(rnew, current, head));
}
