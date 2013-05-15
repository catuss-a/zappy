

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "game.h"

void		handle_msz(t_game *game, t_users *usr, char const *msg)
{
  char		buff[512];

  (void)msg;
  bzero(buff, sizeof(buff));
  sprintf(buff, G_MAP_SIZE, game->map.width, game->map.height);
  sock_send(usr->sock, buff);
}
