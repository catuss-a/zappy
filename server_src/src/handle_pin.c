

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"

void		handle_pin(t_game *game, t_users *usr, char const *msg)
{
  int		num;
  char		buff[512];

  bzero(buff, sizeof(buff));
  num = get_player_num(msg);
  if (num != -1 && game->clients[num])
    {
      sprintf(buff, G_PLAYER_INV,
	      game->clients[num]->num,
	      game->clients[num]->pos.x,
	      game->clients[num]->pos.y,
	      game->clients[num]->life.nb,
	      game->clients[num]->bag[LINEMATE],
	      game->clients[num]->bag[DERAUMERE],
	      game->clients[num]->bag[SIBUR],
	      game->clients[num]->bag[MENDIANE],
	      game->clients[num]->bag[PHIRAS],
	      game->clients[num]->bag[THYSTAME]);
      sock_send(usr->sock, buff);
    }
}
