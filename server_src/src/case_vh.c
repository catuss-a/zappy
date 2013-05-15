

#include "game.h"

int		case_nord(struct s_game *game, t_player *dest, t_coord2d *pos)
{
  t_coord2d	w;

  w.x = dest->pos.x;
  w.y = dest->pos.y;
  if (dest->direction == NORD)
    w.y = MOD_COORD_Y(dest->pos.y + 1, game->map.height);
  else if (dest->direction == SUD)
    w.y = MOD_COORD_Y(dest->pos.y - 1, game->map.height);
  else if (dest->direction == EST)
    w.x = MOD_COORD_X(dest->pos.x + 1, game->map.width);
  else if (dest->direction == OUEST)
    w.x = MOD_COORD_X(dest->pos.x - 1, game->map.width);
  return (pos->x == w.x && pos->y == w.y ? SUCCESS_VALUE: ERROR_VALUE);
}

int		case_sud(struct s_game *game, t_player *dest, t_coord2d *pos)
{
  t_coord2d	w;

  w.x = dest->pos.x;
  w.y = dest->pos.y;
  if (dest->direction == NORD)
    w.y = MOD_COORD_Y(dest->pos.y - 1, game->map.height);
  else if (dest->direction == SUD)
    w.y = MOD_COORD_Y(dest->pos.y + 1, game->map.height);
  else if (dest->direction == EST)
    w.x = MOD_COORD_X(dest->pos.x - 1, game->map.width);
  else if (dest->direction == OUEST)
    w.x = MOD_COORD_X(dest->pos.x + 1, game->map.width);
  return (pos->x == w.x && pos->y == w.y ? SUCCESS_VALUE: ERROR_VALUE);
}

int		case_est(struct s_game *game, t_player *dest, t_coord2d *pos)
{
  t_coord2d	w;

  w.x = dest->pos.x;
  w.y = dest->pos.y;
  if (dest->direction == NORD)
    w.x = MOD_COORD_X(dest->pos.x + 1, game->map.width);
  else if (dest->direction == SUD)
    w.x = MOD_COORD_X(dest->pos.x - 1, game->map.width);
  else if (dest->direction == EST)
    w.y = MOD_COORD_Y(dest->pos.y - 1, game->map.height);
  else if (dest->direction == OUEST)
    w.y = MOD_COORD_Y(dest->pos.y + 1, game->map.height);
  return (pos->x == w.x && pos->y == w.y ? SUCCESS_VALUE: ERROR_VALUE);
}

int		case_ouest(struct s_game *game, t_player *dest, t_coord2d *pos)
{
  t_coord2d	w;

  w.x = dest->pos.x;
  w.y = dest->pos.y;
  if (dest->direction == NORD)
    w.x = MOD_COORD_X(dest->pos.x - 1, game->map.width);
  else if (dest->direction == SUD)
    w.x = MOD_COORD_X(dest->pos.x + 1, game->map.width);
  else if (dest->direction == EST)
    w.y = MOD_COORD_Y(dest->pos.y + 1, game->map.height);
  else if (dest->direction == OUEST)
    w.y = MOD_COORD_Y(dest->pos.y - 1, game->map.height);
  return (pos->x == w.x && pos->y == w.y ? SUCCESS_VALUE: ERROR_VALUE);
}
