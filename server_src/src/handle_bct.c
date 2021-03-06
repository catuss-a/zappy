

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "game.h"

static int	get_pos_from_buff(t_coord2d *pos, char *dup)
{

  char		*str;

  if (!(str = strtok(dup, " \t")))
    return (0);
  if (!(str = strtok(NULL, " \t")))
    return (0);
  pos->x = strtol(str, NULL, 10);
  if (!(str = strtok(NULL, " \t")))
    return (0);
  pos->y = strtol(str, NULL, 10);
  return (1);
}

void		handle_bct(t_game *game, t_users *usr, char const *msg)
{
  t_player	*player;
  char		*dup;
  t_coord2d	pos;

  if ((player = find_player(game, usr)))
    {
      if (!(dup = strdup(msg)))
	return ;
      if (get_pos_from_buff(&pos, dup))
	send_cell_to_graphic(game, player->sock, &pos);
      free(dup);
    }
}
