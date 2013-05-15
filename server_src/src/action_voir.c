

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"

static void	init_position(t_player *player, int *posx, int *posy,
			      unsigned int max_w)
{
  if (player->direction == NORD || player->direction == SUD)
    *posx = player->pos.x;
  else
    *posy = player->pos.y;
  *posx -= player->direction == NORD ? max_w / 2 : 0;
  *posx += player->direction == SUD ? max_w / 2 : 0;
  *posy += player->direction == EST ? max_w / 2 : 0;
  *posy -= player->direction == OUEST ? max_w / 2 : 0;
}

static void	inc_coord_w(t_direction direction, int *posx, int *posy)
{
  *posx += direction == NORD ? 1 : 0;
  *posx -= direction == SUD ? 1 : 0;
  *posy -= direction == EST ? 1 : 0;
  *posy += direction == OUEST ? 1 : 0;
}

static void	inc_coord_h(t_direction direction, int *posx, int *posy)
{
  *posy += direction == NORD ? 1 : 0;
  *posy -= direction == SUD ? 1 : 0;
  *posx += direction == EST ? 1 : 0;
  *posx -= direction == OUEST ? 1 : 0;
}

static void	pars_cells(t_game *game, t_player *player, char **msg)
{
  unsigned int	max_w;
  unsigned int	cur_h;
  unsigned int	cur_w;
  t_coord2d	pos;

  printf("voir\n");
  max_w = 1;
  cur_h = -1;
  pos.x = player->pos.x;
  pos.y = player->pos.y;
  while (++cur_h < player->level + 1)
    {
      init_position(player, &pos.x, &pos.y, max_w);
      cur_w = -1;
      while (++cur_w < max_w)
	{
	  get_description_of_cell(game, player, &pos, msg);
	  inc_coord_w(player->direction, &pos.x, &pos.y);
	}
      inc_coord_h(player->direction, &pos.x, &pos.y);
      max_w += 2;
    }
}

int		action_voir(t_game *game, t_player *player,
			    __attribute__((unused))unsigned int idx_action)
{
  char		*msg;
  char		*tmp;

  msg = NULL;
  pars_cells(game, player, &msg);
  if (msg)
    {
      msg[strlen(msg) - 1] = 0;
      tmp = msg;
      asprintf(&msg, "%s%s%s", "{ ", msg, "}\n");
      free(tmp);
    }
  sock_send(player->sock, msg);
  free(msg);
  return (SUCCESS_VALUE);
}
