

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"

static int	get_time_unit(char const *msg)
{
  int		new_unit;
  char		*str;
  char		*dup;

  if (!(dup = strdup(msg)))
    return (-1);
  if (!(str = strtok(dup, " \t")))
    {
      free(dup);
      return (-1);
    }
  if (!(str = strtok(NULL, " \t")))
    {
      free(dup);
      return (-1);
    }
  new_unit = strtol(str, NULL, 10);
  free(dup);
  return (new_unit);
}

void		handle_sst(t_game *game, t_users *usr, char const *msg)
{
  int		new_unit;

  (void)usr;
  new_unit = get_time_unit(msg);
  if (new_unit != -1)
    game->options.time_unit = new_unit;
}
