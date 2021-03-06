

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "game.h"

static int	request_for_actions(t_player *player, t_game *game,
				    char const *msg)
{
  static unsigned int size = sizeof(gl_protocol) / sizeof(*gl_protocol);
  unsigned int	idx;

  if (count_current_actions(player) == MAX_ACTIONS)
    return (ERROR_VALUE);
  idx = -1;
  while (++idx < size)
    if (!strncmp(gl_protocol[idx].action, msg,
		 strlen(gl_protocol[idx].action)))
      {
	if (push_action(game, player, idx, msg) == SUCCESS_VALUE)
	  return (SUCCESS_VALUE);
      }
  sock_send(player->sock, KO);
  return (ERROR_VALUE);
}

static int		is_graphic_request(t_game *game,
					   t_users *usr,
					   char const *msg)
{
  static unsigned int	size = sizeof(g_graphic_protocol) /
    sizeof(*g_graphic_protocol);
  unsigned int		i;

  i = 0;
  while (i < size)
    {
      if (!strncmp(g_graphic_protocol[i].request, msg,
		   strlen(g_graphic_protocol[i].request)))
	{
	  g_graphic_protocol[i].handler(game, usr, msg);
	  return (TRUE);
	}
      ++i;
    }
  return (FALSE);
}

void		request_callback(t_users *usr, char const *msg, void *arg)
{
  t_game	*game;
  t_player	*player;

  game = arg;
  player = find_player(game, usr);
  if (player && player->type == TYPE_GRAPHIC &&
      is_graphic_request(game, usr, msg))
    return ;
  else if (player)
    {
      print_time();
      printf("From player %d received: %s", player->num, msg);
      (void)request_for_actions(player, game, msg);
    }
  else if (request_for_team(usr, game, msg) == ERROR_VALUE)
    sock_disconnect(usr);
}
