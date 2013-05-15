

#include <stdio.h>

#include "game.h"

int		action_connect_nbr(t_game *game, t_player *player,
				   __attribute__((unused))unsigned int idx_action)
{
  char		msg[16];

  (void)game;
  (void)player;
  (void)game;
  printf("connect_nbr\n");
  sprintf(msg, "%d\n", player->team->nb_clients);
  sock_send(player->sock, msg);
  return (SUCCESS_VALUE);
}
