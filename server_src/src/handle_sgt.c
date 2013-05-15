

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"

void		handle_sgt(t_game *game, t_users *usr, char const *msg)
{
  char		buff[512];

  (void)msg;
  bzero(buff, sizeof(buff));
  sprintf(buff, G_TIME_UNIT, game->options.time_unit);
  sock_send(usr->sock, buff);
}
