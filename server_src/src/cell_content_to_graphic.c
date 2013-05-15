

#include <stdio.h>
#include <string.h>

#include "game.h"

void		cell_content_to_graphic(t_game *game, t_coord2d *pos)
{
  int		offset;
  char		buff[512];

  offset = MAP_OFFSET(pos->x, pos->y, game->map.width);
  bzero(buff, sizeof(buff));
  sprintf(buff, G_CELL_CONTENT, pos->x, pos->y,
	  game->map.map[offset][NOURRITURE],
	  game->map.map[offset][LINEMATE],
	  game->map.map[offset][DERAUMERE],
	  game->map.map[offset][SIBUR],
	  game->map.map[offset][MENDIANE],
	  game->map.map[offset][PHIRAS],
	  game->map.map[offset][THYSTAME]);
  send_to_graphic(game, buff);
}
