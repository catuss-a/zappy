

#include <stdio.h>
#include <string.h>

#include "game.h"

void		send_players_to_graphic(t_game *game, int sock)
{
  unsigned int	i;
  char		buff[4096];

  i = 0;
  while (i < MAX_CLIENT)
    {
      if (game->clients[i] && game->clients[i]->type == TYPE_PLAYER)
	{
	  bzero(buff, sizeof(buff));
	  sprintf(buff, G_NEW_PLAYER,
		  game->clients[i]->num,
		  game->clients[i]->pos.x,
		  game->clients[i]->pos.y,
		  game->clients[i]->direction,
		  game->clients[i]->level,
		  game->clients[i]->team->name);
	  sock_send(sock, buff);
	}
      ++i;
    }
}
