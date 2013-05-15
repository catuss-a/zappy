

#include <stdio.h>

int		raise_error(char *binary, int return_value)
{
  perror(binary);
  return (return_value);
}
