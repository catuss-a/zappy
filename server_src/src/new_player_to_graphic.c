

#include <stdio.h>
#include <string.h>

#include "game.h"

void		new_player_to_graphic(t_player *player, t_game *game)
{
  char		buff[512];

  bzero(buff, sizeof(buff));
  sprintf(buff, G_NEW_PLAYER,
	  player->num,
	  player->pos.x,
	  player->pos.y,
	  player->direction,
	  player->level,
	  player->team->name);
  send_to_graphic(game, buff);
}
