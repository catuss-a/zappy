

#include <stdio.h>
#include <string.h>

#include "game.h"

static void	to_graphic(t_game *game, t_player *player)
{
  char		buff[512];

  (void)game;
  bzero(buff, sizeof(buff));
  sprintf(buff, G_PLAYER_POS,
	  player->num,
	  player->pos.x,
	  player->pos.y,
	  player->direction);
  send_to_graphic(game, buff);
}

int		action_gauche(t_game *game, t_player *player,
			      __attribute__((unused))unsigned int idx_action)
{
  printf("gauche\n");
  if (player->direction == NORD)
    player->direction = OUEST;
  else
    player->direction -= 1;
  to_graphic(game, player);
  sock_send(player->sock, OK);
  return (SUCCESS_VALUE);
}
