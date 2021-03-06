

#include <stdio.h>
#include <string.h>

#include "game.h"

static void	to_graphic(t_game *game, t_player *player)
{
  char		buff[512];

  bzero(buff, sizeof(buff));
  sprintf(buff, G_PLAYER_EXP, player->num);
  send_to_graphic(game, buff);
}

int		action_expulse(t_game *game, t_player *player,
			       __attribute__((unused))unsigned int idx_action)
{
  unsigned int	idx_client;
  char		msg[512];
  int		k;
  char		flag;

  printf("expulse\n");
  flag = 0;
  idx_client = -1;
  while (++idx_client < MAX_CLIENT)
    if (player != game->clients[idx_client]
	&& IS_GAMING(game->clients[idx_client])
	&& game->clients[idx_client]->pos.x == player->pos.x
	&& game->clients[idx_client]->pos.y == player->pos.y)
      {
	flag = 1;
	avance_player(game, game->clients[idx_client], player->direction);
	k = get_id_pos_by_coord(game, game->clients[idx_client],
				&player->pos);
	sprintf(msg, "deplacement: %d\n", k);
	to_graphic(game, game->clients[idx_client]);
	sock_send(game->clients[idx_client]->sock, msg);
      }
  sock_send(player->sock, flag ? OK : KO);
  return (SUCCESS_VALUE);
}
