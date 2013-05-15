

#include <stdlib.h>

#include "game.h"

void		handle_tna(t_game *game, t_users *usr, char const *msg)
{
  (void)msg;
  send_teams_to_graphic(game, usr->sock);
}
