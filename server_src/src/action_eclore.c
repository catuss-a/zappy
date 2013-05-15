

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"

static void	to_graphic(t_game *game, t_player *player)
{
  char		buff[512];

  (void)game;
  bzero(buff, sizeof(buff));
  sprintf(buff, G_HATCH, player->num);
  send_to_graphic(game, buff);
}

int		action_eclore(t_game *game, t_player *player,
			      __attribute__((unused))unsigned int idx_action)
{
  player->type = TYPE_PLAYER;
  to_graphic(game, player);
  return (SUCCESS_VALUE);
}
