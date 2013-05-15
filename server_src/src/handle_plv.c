

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"

void		handle_plv(t_game *game, t_users *usr, char const *msg)
{
  int		num;
  char		buff[512];

  bzero(buff, sizeof(buff));
  num = get_player_num(msg);
  if (num != -1 && game->clients[num])
    {
      sprintf(buff, G_PLAYER_LVL,
	      game->clients[num]->num,
	      game->clients[num]->level);
      sock_send(usr->sock, buff);
    }
}
