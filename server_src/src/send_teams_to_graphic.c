

#include <stdio.h>
#include <string.h>

#include "game.h"

void		send_teams_to_graphic(t_game *game, int sock)
{
  unsigned int	i;
  char		buff[512];

  i = 0;
  while (game->teams[i].name)
    {
      bzero(buff, sizeof(buff));
      sprintf(buff, G_TEAM_NAME, game->teams[i].name);
      sock_send(sock, buff);
      ++i;
    }
}
