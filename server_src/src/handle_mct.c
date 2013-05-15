

#include <stdlib.h>

#include "game.h"

void		handle_mct(t_game *game, t_users *usr, char const *msg)
{
  t_player	*player;

  (void)msg;
  if ((player = find_player(game, usr)))
    {
      player->graphic_pos_x = 0;
      player->graphic_pos_y = 0;
    }
}
