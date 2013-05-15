

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "game.h"

int			print_time(void)
{
  char			buf[15];
  struct timeval	tv;
  time_t		cur_time;

  gettimeofday(&tv, NULL);
  cur_time = tv.tv_sec;
  strftime(buf, 15, "%T.", localtime(&cur_time));
  printf("%c[1;%dm", 0x1B, 36);
  printf("At %s%06ld: ", buf, tv.tv_usec);
  printf("%c[0m", 0x1B);
  return (SUCCESS_VALUE);
}
