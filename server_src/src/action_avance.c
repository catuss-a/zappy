

#include <stdio.h>
#include <string.h>

#include "game.h"

static void	to_graphic(t_game *game, t_player *player)
{
  char		buff[512];

  bzero(buff, sizeof(buff));
  sprintf(buff, G_PLAYER_POS,
	  player->num,
	  player->pos.x,
	  player->pos.y,
	  player->direction);
  send_to_graphic(game, buff);
}

void		avance_player(t_game *game, t_player *player,
			      t_direction direction)
{
  if (direction == NORD)
    player->pos.y = MOD_COORD_Y(player->pos.y + 1, game->map.height);
  else if (direction == SUD)
    player->pos.y = MOD_COORD_Y(player->pos.y - 1, game->map.height);
  else if (direction == EST)
    player->pos.x = MOD_COORD_X(player->pos.x + 1, game->map.width);
  else if (direction == OUEST)
    player->pos.x = MOD_COORD_X(player->pos.x - 1, game->map.width);
}

int		action_avance(t_game *game, t_player *player,
			      __attribute__((unused))unsigned int idx_action)
{
  printf("avance\n");
  avance_player(game, player, player->direction);
  to_graphic(game, player);
  sock_send(player->sock, OK);
  return (SUCCESS_VALUE);
}
