

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"

static void	to_graphic(t_game *game, t_player *player)
{
  char		buff[512];

  bzero(buff, sizeof(buff));
  sprintf(buff, G_PLAYER_DEAD, player->num);
  send_to_graphic(game, buff);
}

void		handle_dying_player(t_game *game, t_player *player)
{
  unsigned int	action_ndx;
  int		num;

  action_ndx = -1;
  num = player->num;
  print_time();
  printf("Player %d is dead.\n", player->num);
  to_graphic(game, player);
  if (game->clients[num] &&
      game->clients[num]->team->nb_clients <
      game->options.max_client)
    ++(player->team->nb_clients);
  if (player->sock)
    sock_socket_disconnect(player->sock);
  while (++action_ndx < MAX_ACTIONS)
    if (game->clients[num]->actions[action_ndx].action)
      free(game->clients[num]->actions[action_ndx].action);
  free(game->clients[num]);
  game->clients[num] = NULL;
}

int		foreach_player(t_game *game,
			       t_handle_player handle_player, void *arg)
{
  unsigned int	idx_client;

  idx_client = 0;
  while (idx_client < MAX_CLIENT)
    {
      if (game->clients[idx_client] && game->clients[idx_client]->team)
	if ((handle_player(game, game->clients[idx_client], arg)) == STOP)
	  return (STOP);
      ++idx_client;
    }
  return (SUCCESS_VALUE);
}
