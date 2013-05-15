

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"

static void	write_rock(t_game *game, char **str,
			   int idx_cell, int *flag)
{
  unsigned int	idx;
  int		cpt;
  char		*tmp;

  idx = -1;
  while (++idx < MAX_ITEMS)
    {
      cpt = game->map.map[idx_cell][idx];
      while (cpt--)
	{
	  tmp = *str;
	  asprintf(str, "%s%s%s", *str?*str:"", !*flag ? "": " ", gl_objects[idx]);
	  free(tmp);
	  *flag = 1;
	}
    }
}

static void	construct_final_cell_msg(char **msg, char **str)
{
  char		*tmp;

  tmp = *str;
  asprintf(str, "%s%s,", *str && *msg ? " ":"", *str ? *str : "");
  free(tmp);
  tmp = *msg;
  asprintf(msg, "%s%s", *msg ? *msg : "", *str ? *str : "");
  free(tmp);
  free(*str);
}

void		get_description_of_cell(t_game *game, t_player *player,
					t_coord2d *pos, char **msg)
{
  int		idx_cell;
  unsigned int	idx;
  char		*str;
  int		flag;
  char		*tmp;

  (void)player;
  idx_cell = ACCESS_TO_CELL(pos->x, pos->y, (int)game->map.width,
			    (int)game->map.height);
  str = NULL;
  flag = 0;
  write_rock(game, &str, idx_cell, &flag);
  idx = -1;
  while (++idx < MAX_CLIENT)
    if (game->clients[idx] != NULL
	&& game->clients[idx]->type != TYPE_GRAPHIC
	&& game->clients[idx]->pos.x == MOD_COORD_X(pos->x, game->map.width)
	&& (game->clients[idx]->pos.y == MOD_COORD_Y(pos->y, game->map.height))
	&& (flag = 1))
      {
	tmp = str;
	asprintf(&str, "%s%s%s", str?str:"", !flag ? "": " ", "joueur");
	free(tmp);
      }
  construct_final_cell_msg(msg, &str);
}
