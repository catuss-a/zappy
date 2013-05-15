

#include <stdlib.h>
#include <unistd.h>

#include "game.h"

static int	init_map(t_map *map)
{
  unsigned int	idx;
  unsigned int	item;

  if ((map->map = calloc(map->nb_cells, sizeof(*map->map))) == NULL)
    return (raise_error("calloc", ERROR_VALUE));
  idx = -1;
  while (++idx < map->nb_cells)
    {
      item = -1;
      while (++item < MAX_ITEMS)
	map->map[idx][item] = !(rand() % 5);
    }
  return (SUCCESS_VALUE);
}

static void	init_team(t_game *game)
{
  unsigned int	idx;

  idx = -1;
  while (++idx < MAX_CLIENT)
    game->teams[idx].nb_clients = game->options.max_client;
}

int		init_game(t_game *game)
{
  if (init_map(&game->map) == ERROR_VALUE)
    return (ERROR_VALUE);
  init_team(game);
  return (SUCCESS_VALUE);
}
