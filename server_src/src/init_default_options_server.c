

#include <string.h>

#include "game.h"

int		init_default_options_server(t_game *game)
{
  bzero(game, sizeof(*game));
  game->options.port = DEFAULT_PORT;
  game->options.max_client = DEFAULT_MAX_CLIENTS;
  game->options.time_unit = DEFAULT_TIME_UNIT;
  game->map.height = DEFAULT_MAP_HEIGHT;
  game->map.width = DEFAULT_MAP_WIDTH;
  game->map.nb_cells = DEFAULT_MAP_HEIGHT * DEFAULT_MAP_WIDTH;
  return (0);
}
