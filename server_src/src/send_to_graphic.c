

#include "game.h"

void		send_to_graphic(t_game *game, char const *msg)
{
  unsigned int	i;

  i = 0;
  while (i < MAX_CLIENT)
    {
      if (game->clients[i] && game->clients[i]->type == TYPE_GRAPHIC)
	sock_send(game->clients[i]->sock, msg);
      ++i;
    }
}
