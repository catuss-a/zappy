

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "game.h"

int	get_player_num(char const *msg)
{
  int		num;
  char		*str;
  char		*dup;

  if (!(dup = strdup(msg)))
    return (-1);
  if (!(str = strtok(dup, " \t")))
    {
      free(dup);
      return (-1);
    }
  if (!(str = strtok(NULL, " \t")))
    {
      free(dup);
      return (-1);
    }
  num = strtol(str, NULL, 10);
  free(dup);
  return (num);
}

void		handle_ppo(t_game *game, t_users *usr, char const *msg)
{
  int		num;
  char		buff[512];

  bzero(buff, sizeof(buff));
  num = get_player_num(msg);
  if (num != -1 && game->clients[num])
    {
      sprintf(buff, G_PLAYER_POS,
	      game->clients[num]->num,
	      game->clients[num]->pos.x,
	      game->clients[num]->pos.y,
	      game->clients[num]->direction);
      sock_send(usr->sock, buff);
    }
}
