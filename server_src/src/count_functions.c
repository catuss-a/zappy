

#include <stdlib.h>

#include "game.h"

unsigned int	count_food_on_map(t_map *map)
{
  unsigned int	cpt;
  unsigned int	ndx;

  cpt = 0;
  ndx = 0;
  while (ndx < map->nb_cells)
    {
      cpt += map->map[ndx][NOURRITURE];
      ++ndx;
    }
  return (cpt);
}

unsigned int	count_current_actions(t_player *player)
{
  unsigned int	i;
  unsigned int	cpt;

  i = 0;
  cpt = 0;
  while (i < MAX_ACTIONS)
    {
      if (player->actions[cpt].action != NULL)
	++cpt;
      ++i;
    }
  return (cpt);
}
