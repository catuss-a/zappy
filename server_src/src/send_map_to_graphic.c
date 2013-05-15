

#include <stdio.h>
#include <string.h>

#include "game.h"

void	send_cell_to_graphic(t_game *game, int sock, t_coord2d *pos)
{
  char	buf[512];
  int	offset;

  bzero(buf, sizeof(buf));
  offset = MAP_OFFSET(pos->x, pos->y, game->map.width);
  sprintf(buf, G_CELL_CONTENT, pos->x, pos->y,
	  game->map.map[offset][NOURRITURE],
	  game->map.map[offset][LINEMATE],
	  game->map.map[offset][DERAUMERE],
	  game->map.map[offset][SIBUR],
	  game->map.map[offset][MENDIANE],
	  game->map.map[offset][PHIRAS],
	  game->map.map[offset][THYSTAME]);
  sock_send(sock, buf);
  sock_set_timeout(0);
}

void		send_next_cell(t_game *game, t_player *graphic)
{
  t_coord2d	pos;

  if (graphic->graphic_pos_y < game->map.height &&
      graphic->graphic_pos_x < game->map.width)
    {
      pos.x = graphic->graphic_pos_x;
      pos.y = graphic->graphic_pos_y;
      send_cell_to_graphic(game, graphic->sock, &pos);
      ++graphic->graphic_pos_x;
      if (graphic->graphic_pos_x == game->map.width)
	{
	  graphic->graphic_pos_x = 0;
	  ++graphic->graphic_pos_y;
	}
      sock_set_timeout(-1);
    }
  else if (graphic->team_sent == 0)
    {
      graphic->team_sent = 1;
      send_teams_to_graphic(game, graphic->sock);
      send_players_to_graphic(game, graphic->sock);
      sock_set_timeout(-1);
    }
}

int		handle_graphic(t_game *game)
{
  unsigned int	i;

  i = 0;
  while (i < MAX_CLIENT)
    {
      if (game->clients[i] && game->clients[i]->type == TYPE_GRAPHIC)
	send_next_cell(game, game->clients[i]);
      ++i;
    }
  return (SUCCESS_VALUE);
}
