

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "game.h"

static t_incantation	gl_incantation[] = {
  { 0, { 0, 0, 0, 0, 0, 0, 0 } },
  { 1, { 0, 1, 0, 0, 0, 0, 0 } },
  { 2, { 0, 1, 1, 1, 0, 0, 0 } },
  { 2, { 0, 2, 0, 1, 0, 2, 0 } },
  { 4, { 0, 1, 1, 2, 0, 1, 0 } },
  { 4, { 0, 1, 2, 1, 3, 0, 0 } },
  { 6, { 0, 1, 2, 3, 0, 1, 0 } },
  { 6, { 0, 2, 2, 2, 2, 2, 1 } }
};

int	end_game(t_game *game)
{
  unsigned int	ndx;
  unsigned int action_ndx;

  ndx = -1;
  while (++ndx < MAX_CLIENT)
    if (game->clients[ndx])
      {
  	action_ndx = -1;
  	while (++action_ndx < MAX_ACTIONS)
  	  if (game->clients[ndx]->actions[action_ndx].action)
	    free(game->clients[ndx]->actions[action_ndx].action);
      }
  free(game->map.map);
  return (STOP);
}

static void	to_graphic(t_game *game, t_player *player)
{
  char		buff[512];

  (void)game;
  (void)player;
  bzero(buff, sizeof(buff));
}

int		check_incantation(t_game *game, t_player *player)
{
  unsigned int	idx;
  unsigned int	level;
  unsigned int	cpt;

  if ((level = player->level) > 7)
    return (ERROR_VALUE);
  idx = 0;
  while (++idx < MAX_ITEMS)
    if (game->map.map[ACCESS_TO_CELL(player->pos.x, player->pos.y,
				     (int)game->map.width,
				     (int)game->map.height)][idx]
	!= gl_incantation[level].rocks[idx])
      return (ERROR_VALUE);
  cpt = 0;
  idx = -1;
  while (++idx < MAX_CLIENT)
    if (IS_GAMING(game->clients[idx])
	&& player->pos.x == game->clients[idx]->pos.x
	&& player->pos.y == game->clients[idx]->pos.y
	&& level == game->clients[idx]->level)
      ++cpt;
  if (cpt == gl_incantation[level].player_required)
    return (SUCCESS_VALUE);
  return (ERROR_VALUE);
}

static void	rock_repartition(t_game *game, t_player *player)
{
  unsigned int	idx;
  unsigned int	level;
  unsigned int	nb_rock;

  level = player->level;
  idx = 0;
  while (++idx < MAX_ITEMS)
    {
      game->map.map[ACCESS_TO_CELL(player->pos.x, player->pos.y,
				   (int)game->map.width,
				   (int)game->map.height)][idx]	= 0;
      nb_rock = gl_incantation[level].rocks[idx];
      while (nb_rock-- > 0)
	{
	  game->map.map[ACCESS_TO_CELL(rand() % (int)game->map.width,
				       rand() % (int)game->map.height,
				       (int)game->map.width,
				       (int)game->map.height)][idx] += 1;
	}
    }
}

int		action_incantation(t_game *game, t_player *player,
				   __attribute__((unused))unsigned int idx_action)
{
  char		msg[512];

  printf("incantation\n");
  if (check_incantation(game, player) == ERROR_VALUE)
    {
      sock_send(player->sock, KO);
      return (ERROR_VALUE);
    }
  foreach_player(game, handle_level_up, player);
  ++player->level;
  sprintf(msg, "niveau actuel : %d\n", player->level);
  sock_send(player->sock, msg);
  to_graphic(game, player);
  if (player->level == 8)
    return (end_game(game));
  rock_repartition(game, player);
  return (SUCCESS_VALUE);
}
