

#include <stdio.h>
#include <stdlib.h>

#include "game.h"

t_player	*find_player(t_game *game, t_users *usr)
{
  unsigned int	i;

  i = 0;
  while (i < MAX_CLIENT)
    {
      if (game->clients[i] && game->clients[i]->sock == usr->sock)
	return (game->clients[i]);
      ++i;
    }
  return (NULL);
}
