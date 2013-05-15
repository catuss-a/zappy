

#include <stdio.h>

#include "game.h"

void		display_map(t_map *map)
{
  unsigned int	idx;

  idx = -1;
  while (++idx < map->nb_cells)
    {
      printf("case %03u: {linemate : %u, deraumere : %u, sibur : %u, \
mendiane : %u, phiras : %u, thystame : %u, nourritur : %u\n", idx,
	     map->map[idx][LINEMATE],
	     map->map[idx][DERAUMERE],
	     map->map[idx][SIBUR],
	     map->map[idx][MENDIANE],
	     map->map[idx][PHIRAS],
	     map->map[idx][THYSTAME],
	     map->map[idx][NOURRITURE]);
    }
}
