

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "list_wrapper.h"

static t_teams	*is_team(t_game *game, char const *msg)
{
  unsigned int	idx;

  idx = -1;
  while (++idx < MAX_CLIENT)
    {
      if (game->teams[idx].name && msg)
	{
	  if (!strncmp(game->teams[idx].name, msg,
		       strlen(game->teams[idx].name)))
	    return (&game->teams[idx]);
	}
    }
  return (NULL);
}

static int	is_graphic(char const *msg)
{
  if (!strcmp(GRAPHIC_CLIENT, msg))
    return (TRUE);
  return (FALSE);
}

static int	put_graphic_client_in_game(t_game *game,
					   unsigned int i,
					   t_users *usr)
{
  char			buff[512];
  t_pending_clients	*pending;

  pending = list_find_if(&game->pending, &usr->sock, find_by_sock);
  if (pending)
    {
      bzero(buff, sizeof(buff));
      game->clients[i] = pending->p_player;
      game->clients[i]->type = TYPE_GRAPHIC;
      game->clients[i]->num = i;
      game->clients[i]->graphic_pos_x = 0;
      game->clients[i]->graphic_pos_y = 0;
      game->clients[i]->team_sent = 0;
      game->clients[i]->sock = usr->sock;
      game->clients[i]->team = NULL;
      sprintf(buff, G_MAP_SIZE, game->map.width, game->map.height);
      sock_send(usr->sock, buff);
      sprintf(buff, G_TIME_UNIT, game->options.time_unit);
      sock_send(usr->sock, buff);
      return (SUCCESS_VALUE);
    }
  return (ERROR_VALUE);
}

static int	init_graphic_client(t_game *game, t_users *usr)
{
  unsigned int	i;

  i = 0;
  while (i < MAX_CLIENT)
    {
      if (game->clients[i] == NULL)
	return (put_graphic_client_in_game(game, i, usr));
      ++i;
    }
  return (ERROR_VALUE);
}

int	request_for_team(t_users *usr, t_game *game, char const *msg)
{
  t_teams	*team;

  if ((team = is_team(game, msg)) != NULL)
    return (init_player_client(game, usr, team));
  else if (is_graphic(msg))
    return (init_graphic_client(game, usr));
  printf("fail\n");
  sock_send(usr->sock, "ko\n");
  return (ERROR_VALUE);
}
