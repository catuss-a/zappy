

#include <stdlib.h>
#include "game.h"

int			set_next_delay(struct timeval *delay,
				       unsigned int t,
				       unsigned int time_unit)
{
  double		unit;
  struct timeval	cur_date;

  if (gettimeofday(&cur_date, NULL) == ERROR_VALUE)
    return (ERROR_VALUE);
  unit = t / (double)time_unit;
  delay->tv_sec = cur_date.tv_sec + unit;
  delay->tv_usec = cur_date.tv_usec + (unit < 1.0 ? unit * 1000000 : 0);
  return (SUCCESS_VALUE);
}
