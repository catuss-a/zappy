

#include <stdlib.h>

#include "game.h"

int			handle_map(t_game *game)
{
  unsigned int		ndx;
  unsigned int		food;
  static unsigned int	food_required = 0;

  if (food_required == 0)
    food_required = game->map.nb_cells / 2;
  ndx = 0;
  food = count_food_on_map(&game->map);
  if (food < food_required)
    {
      food = food_required - food;
      while (food && ndx < game->map.nb_cells)
	{
	  if (game->map.map[ndx][NOURRITURE] < 5)
	    game->map.map[ndx][NOURRITURE] += !(rand() % 100);
	  --food;
	  ++ndx;
	}
    }
  return (SUCCESS_VALUE);
}
