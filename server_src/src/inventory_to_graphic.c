

#include <stdio.h>
#include <string.h>

#include "game.h"

void		inventory_to_graphic(t_game *game, t_player *player)
{
  char		buff[512];

  bzero(buff, sizeof(buff));
  sprintf(buff, G_PLAYER_INV, player->num, player->pos.x, player->pos.y,
	  player->bag[NOURRITURE],
	  player->bag[LINEMATE],
	  player->bag[DERAUMERE],
	  player->bag[SIBUR],
	  player->bag[MENDIANE],
	  player->bag[PHIRAS],
	  player->bag[THYSTAME]);
  send_to_graphic(game, buff);
}
